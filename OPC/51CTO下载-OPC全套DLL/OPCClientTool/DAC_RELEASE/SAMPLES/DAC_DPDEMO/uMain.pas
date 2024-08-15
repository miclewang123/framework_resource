unit uMain;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ComCtrls, ToolWin, Menus, ExtCtrls, ActiveX, StdCtrls;

type
  PItem=^TItem;

  TItem=record
    Handle: DWORD;
    Name: string;
  end;
  
  TForm1 = class(TForm)
    MainMenu1: TMainMenu;
    lvItems: TListView;
    mnOperate: TMenuItem;
    mnConnect: TMenuItem;
    mnDisconnect: TMenuItem;
    mnExit: TMenuItem;
    N6: TMenuItem;
    mnHelp: TMenuItem;
    StatusBar1: TStatusBar;
    N3: TMenuItem;
    mnGroupStatus: TMenuItem;
    mnItemAdd: TMenuItem;
    mnItemRemove: TMenuItem;
    N11: TMenuItem;
    mnItemWrite: TMenuItem;
    mnItemRead: TMenuItem;
    mnServerStatus: TMenuItem;
    mnItemRefresh: TMenuItem;
    mnAbout: TMenuItem;
    mnItemProperties: TMenuItem;
    procedure mnConnectClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure mnDisconnectClick(Sender: TObject);
    procedure mnExitClick(Sender: TObject);
    procedure mnItemAddClick(Sender: TObject);
    procedure mnItemRemoveClick(Sender: TObject);
    procedure FormCloseQuery(Sender: TObject; var CanClose: Boolean);
    procedure mnItemWriteClick(Sender: TObject);
    procedure lvItemsClick(Sender: TObject);
    procedure mnItemReadClick(Sender: TObject);
    procedure mnGroupStatusClick(Sender: TObject);
    procedure mnServerStatusClick(Sender: TObject);
    procedure mnItemPropertiesClick(Sender: TObject);
  private
    FServer, FGroup: THandle;
    FGroupName: string;
    procedure Clear;
  public
    procedure RefreshData(ItemHandle: DWORD; pVar: Variant; timestamp: TFILETIME; quality: WORD);
    procedure AddItem(ItemName: string);
    function GetItem(Handle: THandle): TListItem;
    procedure ShutDownRequest;
  end;

var
  Form1: TForm1;

implementation

uses DACLTSDK, uServerBrowser, uGroupStatus, uItemBrowser, uServerStatus, uItemStatus;

{$R *.dfm}

function FileTimeToString(AFileTime: TFileTime): string;
var
  FileTime: TFileTime;
  SystemTime: TSystemTime;
  D: TDatetime;
  Year, Month, Day, Hour, Min, Sec, MSec: Word;
begin
  FileTimeToLocalFileTime(AFileTime, FileTime);
  FileTimeToSystemTime(FileTime, SystemTime);
  D := SystemTimeToDateTime(SystemTime);
  DecodeDate(D, Year, Month, Day);
  DecodeTime(D, Hour, Min, Sec, MSec);
  Result := Format('%.4d-%.2d-%.2d %.2d:%.2d:%.2d.%.3d', [Year, Month, Day, Hour,
    Min, Sec, MSec]);
end;

procedure ShutDownProc(ServerHandle: DWORD); stdcall;
begin
  Form1.ShutDownRequest;
end;

procedure DataChangeProc(hServer,GroupHandle,ItemHandle:DWORD;pVar:Variant; timestamp:TFILETIME; quality:WORD); stdcall;
begin
  Form1.RefreshData(ItemHandle, pVar, timestamp, quality);
end;

{ TForm1 }

procedure TForm1.mnConnectClick(Sender: TObject);
var
  Browser: TServerBrowser;
begin
  Browser:= TServerBrowser.Create(nil);
  try
    if Browser.ShowModal = mrOK then
    begin
      FServer:= ASDAC_Connect(PChar(Browser.Selected.Node),PChar(Browser.Selected.ClassID),Browser.Selected.Version);
      if FServer>0 then
      begin
        ASDAC_SetDataChangeProc(FServer, @DataChangeProc);
        ASDAC_SetShutdownProc(FServer, @ShutdownProc);
        mnConnect.Enabled:= False;
        mnDisconnect.Enabled:= true;
        mnServerStatus.Enabled:= true;
        FGroup:= ASDAC_AddGroup(FServer, PChar(FGroupName), true, 1000,0,0,0);
        if FGroup>0 then
        begin
          mnGroupStatus.Enabled:= true;
          mnItemAdd.Enabled:= true;
        end;
      end;
    end;
  finally
    Browser.Free;
  end;
end;

procedure TForm1.FormCreate(Sender: TObject);
begin
  FGroupName:= 'GROUP';
  ASDAC_Init;
end;

procedure TForm1.FormDestroy(Sender: TObject);
begin
  Clear;
  ASDAC_Uninit;
end;

procedure TForm1.mnDisconnectClick(Sender: TObject);
begin
  Clear;
  if FServer>0 then
  begin
    if ASDAC_Disconnect(FServer) then
    begin
      FServer:= 0;
      FGroup:= 0;
      FGroupName:= 'GROUP';
      mnConnect.Enabled:= true;
      mnDisconnect.Enabled:= False;
      mnServerStatus.Enabled:= False;
      mnGroupStatus.Enabled:= False;
      mnItemAdd.Enabled:= False;
      mnItemRemove.Enabled:= False;
      mnItemRead.Enabled:= False;
      mnItemWrite.Enabled:= False;
      mnItemRefresh.Enabled:= False;
    end;
  end;
end;

procedure TForm1.RefreshData(ItemHandle:DWORD;pVar:Variant;
    timestamp:TFILETIME; quality:WORD);
var
  lsItem: TListItem;
begin
  lsItem:= GetItem(ItemHandle);
  if Assigned(lsItem) then
  begin
    lsItem.SubItems[0]:= pVar;
    lsItem.SubItems[1]:= Format('%d',[quality]);
    lsItem.SubItems[2]:= FileTimeToString(timestamp);
  end;
end;

procedure TForm1.mnExitClick(Sender: TObject);
begin
  Close;
end;

procedure TForm1.mnItemAddClick(Sender: TObject);
var
  Browser: TItemBrowser;
begin
  Browser:= TItemBrowser.Create(nil);
  Browser.Server:= FServer;
  Browser.OnAddItem:= AddItem;
  Browser.ShowModal;
  Browser.Free;
end;

procedure TForm1.AddItem(ItemName: string);
var
  item: PItem;
  lsItem: TListItem;
  h: THandle;
begin
  h:= ASDAC_AddItem(FServer, FGroup, PChar(ItemName));
  if h>0 then
  begin
    new(item);
    try
      item^.Handle:= h;
      item.Name:= ItemName;
      lsItem:= lvItems.Items.Add;
      lsItem.Caption:= ItemName;
      lsItem.SubItems.Add('Bad');
      lsItem.SubItems.Add('');
      lsItem.SubItems.Add('');
      lsItem.Data:= Item;
    except
      on Exception do ;
    end;
  end;
end;

procedure TForm1.mnItemRemoveClick(Sender: TObject);
var
  lvItem: TListItem;
begin
  lvItem:= lvItems.Selected;
  if Assigned(lvItem) then
  begin
    ASDAC_RemoveItem(FServer, FGroup, PItem(lvItem.Data).Handle);
    Dispose(lvItems.Selected.Data);
    lvItems.Selected.Delete;
  end;
end;

function TForm1.GetItem(Handle: THandle): TListItem;
var
  I: Integer;
begin
  for I:=0 to lvItems.Items.Count-1 do
  begin
    result:= lvItems.Items[I];
    if PItem(result.Data).Handle=Handle then Exit;
  end;
  result:= nil;
end;

procedure TForm1.ShutDownRequest;
begin
  Close;
end;

procedure TForm1.FormCloseQuery(Sender: TObject; var CanClose: Boolean);
begin
  if mnDisconnect.Enabled then
    mnDisconnectClick(Sender);
end;

procedure TForm1.mnItemWriteClick(Sender: TObject);
var
  lvItem: TListItem;
  Data: string;
  v: Variant;
begin
  lvItem:= lvItems.Selected;
  if Assigned(lvItem) then
  begin
    if InputQuery('提示','写入数值:',Data) then
    begin
      VarClear(v);
      TVarData(v).VType:= varSingle;
      TVarData(V).VSingle:= StrToFloat(Data);
      if ASDAC_WriteItem(FServer, FGroup, PItem(lvItem.Data).Handle, v, true) then
        lvitem.SubItems[0]:= v;
    end;
  end;
end;

procedure TForm1.lvItemsClick(Sender: TObject);
begin
  if Assigned(lvItems.Selected) then
  begin
    mnItemWrite.Enabled:= true;
    mnItemRead.Enabled:= true;
    mnItemRemove.Enabled:= true;
    mnItemRefresh.Enabled:= true;
    mnItemProperties.Enabled:= true;
  end;
end;

procedure TForm1.mnItemReadClick(Sender: TObject);
var
  lvItem: TListItem;
  Data: Variant;
  ft: TFileTime;
  Quality: WORD;
begin
  lvItem:= lvItems.Selected;
  if Assigned(lvItem) then
  begin
    VarClear(Data);
    if ASDAC_ReadItem(FServer, FGroup, PItem(lvItem.Data).Handle, @Data,@ft, @Quality) then
    begin
      lvItem.SubItems[0]:= Data;
      lvItem.SubItems[1]:= IntTostr(Quality);
      lvItem.SubItems[2]:= FileTimeToString(ft);
    end;
  end;
end;

procedure TForm1.Clear;
var
  I: Integer;
begin
  for I:=0 to lvItems.Items.Count-1 do Dispose(PItem(lvItems.Items[I].Data));
  lvItems.Clear;
end;

procedure TForm1.mnGroupStatusClick(Sender: TObject);
var
  Editor: TGroupStatus;
  UpdateRate: DWORD;
  Active: BOOL;
  TimeBias: LONGINT;
  DeadBand: Single;
  dwLCID: DWORD;
begin
  Editor:= TGroupStatus.Create(nil);
  try
    if ASDAC_GetGroupStat(FServer, FGroup, @UpdateRate, @Active, @TimeBias, @DeadBand, @dwLCID) then
    begin
      Editor.Name.Text:= FGroupName;
      Editor.UpdateRate.Text:= IntToStr(UpdateRate);
      Editor.DeadBand.Text:= Format('%4.2f',[DeadBand*100]);
      Editor.Active.Checked:= Active;
      Editor.TimeBias.Text:= IntToStr(TimeBias);
    end;
    if Editor.ShowModal=mrOK then
    begin
      Active:= Editor.Active.Checked;
      TimeBias:= StrToInt(Editor.TimeBias.Text);
      DeadBand:= StrToFloat(Editor.DeadBand.Text) / 100;
      UpdateRate:= StrToInt(Editor.UpdateRate.Text);
      if CompareText(Editor.Name.Text, FGroupName)<>0 then
      begin
        if ASDAC_SetGroupName(FServer, FGroup, PChar(Editor.Name.Text)) then
          FgroupName:= Editor.Name.Text;
      end;
      ASDAC_SetGroupStat(FServer, FGroup, UpdateRate,Active, TimeBias, DeadBand, dwLCID);
    end;
  finally
    Editor.Free;
  end;
end;

procedure TForm1.mnServerStatusClick(Sender: TObject);
var
  Editor: TServerStatus;
  ftStart, ftCurrent, ftUpdate: TFileTime;
  dwBandWidth, dwGroupCount: DWORD;
  wState: WORD;
  vendor: PChar;
  wMajor, wMinor, wBuild: WORD; 
begin
  Editor:= TServerStatus.Create(nil);
  try
    vendor:= strAlloc(128);
    try
      if ASDAC_GetServerStatus(FServer, @ftStart, @ftCurrent, @ftUpdate, @wState,
        @dwBandWidth, @dwGroupCount, @wMajor, @wMinor, @wBuild, vendor, 128) then
      begin
        Editor.StartTime.Text   := FileTimeToString(ftStart);
        Editor.CurrentTime.Text := FileTimeToString(ftCurrent);
        Editor.LastUpdate.Text  := FileTimeToString(ftUpdate);
        Editor.ServerState.Text := IntToStr(wState);
        Editor.GroupCount.Text  := IntToStr(dwGroupCount);
        Editor.BandWidth.Text   := IntToStr(dwBandWidth);
        Editor.MajorVersion.Text:= IntToStr(wMajor);
        Editor.MinorVersion.Text:= IntToStr(wMinor);
        Editor.BuildVersion.Text:= IntToStr(wBuild);
      end;
      Editor.ShowModal;
    finally
      strDispose(vendor);
    end;
  finally
    Editor.Free;
  end;
end;

procedure TForm1.mnItemPropertiesClick(Sender: TObject);
var
  Editor: TItemStatus;
begin
  if Assigned(lvItems.Selected) then
  begin
    Editor:= TItemStatus.Create(nil);
    try
      Editor.Server:= FServer;
      Editor.ItemName:= lvitems.Selected.Caption;
      Editor.ShowModal;
    finally
      Editor.Free;
    end;
  end;
end;

end.
