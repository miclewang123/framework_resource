unit uServerBrowser;

interface

uses Windows, SysUtils, Classes, Graphics, Forms, Controls, StdCtrls,
  Buttons, ExtCtrls;

type
  TServerInfo=class
    Node: string;
    ProgID, ClassID: string;
    Version: DWORD;
  end;

  TServerBrowser = class(TForm)
    OKBtn: TButton;
    CancelBtn: TButton;
    RefreshBtn: TButton;
    Servers: TListBox;
    rbV1: TRadioButton;
    rbV2: TRadioButton;
    ServerName: TEdit;
    Label2: TLabel;
    Label1: TLabel;
    ServerNode: TEdit;
    procedure RefreshBtnClick(Sender: TObject);
    procedure ServersClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure ServersDblClick(Sender: TObject);
  private
    { Private declarations }
  public
    Selected: TServerInfo;
  end;

var
  ServerBrowser: TServerBrowser;

implementation

uses DACLTSDK;
{$R *.dfm}

procedure TServerBrowser.RefreshBtnClick(Sender: TObject);
var
  I, Count: Integer;
  Version: DWORD;
  ServerNames, ServerClassIDs: Variant;
  info: TServerInfo;
begin
  Servers.Clear;
  Selected:= nil;
  if rbV2.Checked then Version:= 2 else Version:= 1;

  Count:=ASDAC_GetServers(PChar(ServerNode.Text), Version, @ServerNames, @ServerClassIDs);
  for I:=0 to Count-1 do
  begin
    Info:= TServerInfo.Create;
    Info.Node:=    ServerNode.Text;
    Info.ProgID:=  ServerNames[I];
    Info.ClassID:= ServerClassIDs[I];
    Info.Version:= Version;
    Servers.Items.AddObject(ServerNames[I], Info);
  end;
end;

procedure TServerBrowser.ServersClick(Sender: TObject);
begin
  if Servers.ItemIndex>-1 then
  begin
    Selected:=TServerInfo(Servers.Items.Objects[Servers.ItemIndex]);
    ServerName.Text:= Selected.ProgID;
  end;
end;

procedure TServerBrowser.FormCreate(Sender: TObject);
begin
  ServerName.Text:= '';
  ServerNode.TExt:= '';
  RefreshBtn.Click;
end;

procedure TServerBrowser.FormDestroy(Sender: TObject);
var
  I: Integer;
begin
  for I := 0 to Servers.Count-1 do
    Servers.Items.Objects[I].Free;
end;

procedure TServerBrowser.ServersDblClick(Sender: TObject);
begin
  if Servers.ItemIndex>-1 then
  begin
    Selected:=TServerInfo(Servers.Items.Objects[Servers.ItemIndex]);
    ModalResult:= mrOK;
  end;
end;

end.
