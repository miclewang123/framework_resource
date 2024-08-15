unit uItemStatus;

interface

uses Windows, SysUtils, Classes, Graphics, Forms, Controls, StdCtrls,
  Buttons, ExtCtrls, Grids, ValEdit;

type
  TItemStatus = class(TForm)
    OKBtn: TButton;
    RefreshBtn: TButton;
    Props: TValueListEditor;
    procedure RefreshBtnClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
  private
    FServer: DWORD;
    FItemName: string;
    procedure SetItemName(const Value: string);
    procedure SetServer(const Value: DWORD);
  public
  published
    property Server: DWORD read FServer write SetServer;
    property ItemName: string read FItemName write SetItemName;
  end;

var
  ItemStatus: TItemStatus;

implementation

uses DACLTSDK;

{$R *.dfm}

{ TItemStatus }

procedure TItemStatus.SetItemName(const Value: string);
begin
  FItemName := Value;
end;

procedure TItemStatus.SetServer(const Value: DWORD);
begin
  FServer := Value;
end;

procedure TItemStatus.RefreshBtnClick(Sender: TObject);
var
  I: Integer;
  IDList, DescList, DataTypeList: Variant;
  v: Variant;
  Count: Integer;
begin
  Props.Strings.Clear;
  Count:=ASDAC_GetItemProperties(FServer, PChar(FItemName), @IDList, @DataTypeList, @DescList);
  for I := 0 to Count-1 do
  begin
    VarClear(v);
    if ASDAC_GetItemPropertyValue(FServer, PChar(FItemName), IDList[I], @v) then
      Props.InsertRow(DescList[I], v, true);
  end;
end;

procedure TItemStatus.FormShow(Sender: TObject);
begin
  RefreshBtnClick(nil);
end;

end.
