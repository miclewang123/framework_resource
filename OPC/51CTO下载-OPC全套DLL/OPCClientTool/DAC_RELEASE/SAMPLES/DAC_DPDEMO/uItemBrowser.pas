unit uItemBrowser;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ComCtrls;

type
  TAddItemEvent = procedure(ItemName: string) of object;
  TItemBrowser = class(TForm)
    bAdd: TButton;
    bcancel: TButton;
    ePath: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    eName: TEdit;
    tvBranch: TTreeView;
    lbLeaf: TListBox;
    Label3: TLabel;
    PropBtn: TButton;
    procedure bAddClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure tvBranchChange(Sender: TObject; Node: TTreeNode);
    procedure lbLeafClick(Sender: TObject);
    procedure lbLeafDblClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure PropBtnClick(Sender: TObject);
  private
    FServer: THandle;
    FNameSpace: DWORD;
    FRoot: TTreeNode;
    FOnAddItem: TAddItemEvent;
    procedure BrowseItems;
    procedure BrowseBranch;
    procedure SetServer(const Value: DWORD);
  published
    property OnAddItem: TAddItemEvent read FOnAddItem write FOnAddItem;
    property Server: DWORD read FServer write SetServer;
  end;

var
  ItemBrowser: TItemBrowser;

implementation

uses DACLTSDK, uItemStatus;

{$R *.dfm}

{ TFItemInfo }

procedure TItemBrowser.bAddClick(Sender: TObject);
begin
  if eName.Text<>'' then
    if Assigned(FOnAddItem) then
      FOnAddItem(eName.Text);
end;

procedure TItemBrowser.FormCreate(Sender: TObject);
begin
  FRoot:= tvBranch.Items.AddChildFirst(nil,'ROOT');
  FRoot.Selected:= true;
end;

procedure TItemBrowser.BrowseBranch;
  procedure ChangePosition(node: TTreeNode);
  begin
    if node.Parent<>nil then
    begin
      if node.Parent.Text='ROOT' then
        ASDAC_ChangeBrowsePosition(FServer, OPC_BROWSE_UP, '')
      else
        ChangePosition(node.Parent);
      ASDAC_ChangeBrowsePosition(FServer, OPC_BROWSE_DOWN, PChar(node.Text));
    end
    else
      ASDAC_ChangeBrowsePosition(FServer, OPC_BROWSE_TO, '');
  end;
var
  Count,I: Integer;
  NameList: Variant;
begin
  if not Assigned(tvBranch.Selected) then Exit;
  ChangePosition(tvBranch.Selected);
  Browseitems;
  if not tvBranch.Selected.HasChildren then
  begin
    Count:= ASDAC_BrowseItems(FServer, OPC_BRANCH, '*', 0, 0, @NameList);
    for I:=0 to Count-1 do
    begin
      tvBranch.Items.AddChild(tvBranch.Selected,NameList[I]);
      tvbranch.Selected.Expand(False);
    end;
  end;
end;

procedure TItemBrowser.BrowseItems;
var
  Count,I: Integer;
  NameList: Variant;
begin
  if not Assigned(tvBranch.Selected) then Exit;
  lbLeaf.Clear;
  Count:= ASDAC_BrowseItems(FServer,OPC_LEAF,  '*', 0, 0, @NameList);
  for I:=0 to Count-1 do
    lbLeaf.Items.Add(NameList[I]);
end;

procedure TItemBrowser.tvBranchChange(Sender: TObject; Node: TTreeNode);
begin
  if FNameSpace<>OPC_NS_FLAT then
    BrowseBranch
  else
    BrowseItems;
end;

procedure TItemBrowser.lbLeafClick(Sender: TObject);
var
  Name: string;
  FullName: PChar;
begin
  if lbLeaf.ItemIndex>-1 then
  begin
    Name:= lbLeaf.Items[lbLeaf.itemIndex];
    FullName:= strAlloc(128);
    try
      ASDAC_GetItemFullName(FServer,PChar(Name), FullName, 127);
      eName.Text:= Fullname;
    finally
      strDispose(Fullname);
    end;
  end;
end;

procedure TItemBrowser.lbLeafDblClick(Sender: TObject);
var
  Name: string;
  FullName: PChar;
begin
  if lbLeaf.ItemIndex>-1 then
  begin
    Name:= lbLeaf.Items[lbLeaf.itemIndex];
    FullName:= strAlloc(128);
    try
      ASDAC_GetItemFullName(FServer,PChar(Name), FullName, 127);
      eName.Text:= Fullname;
    finally
      strDispose(Fullname);
    end;
    bAddClick(Sender);
  end;
end;

procedure TItemBrowser.FormShow(Sender: TObject);
begin
  ASDAC_GetNameSpace(FServer, @FNameSpace);
  ASDAC_ChangeBrowsePosition(FServer, OPC_BROWSE_UP, '');
  if FNameSpace=OPC_NS_FLAT then
    BrowseItems
  else
    BrowseBranch;
end;

procedure TItemBrowser.SetServer(const Value: DWORD);
begin
  FServer := Value;
end;

procedure TItemBrowser.PropBtnClick(Sender: TObject);
var
  Editor: TItemStatus;
begin
  if eName.Text<>'' then
  begin
    Editor:= TItemStatus.Create(nil);
    try
      Editor.Server:= FServer;
      Editor.ItemName:= eName.Text;
      Editor.ShowModal;
    finally
      Editor.Free;
    end;
  end;
end;

end.
