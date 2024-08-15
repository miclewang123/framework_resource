object ItemBrowser: TItemBrowser
  Left = 370
  Top = 311
  BorderStyle = bsDialog
  Caption = #26631#31614#27983#35272#22120
  ClientHeight = 269
  ClientWidth = 406
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #23435#20307
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 12
  object Label1: TLabel
    Left = 16
    Top = 19
    Width = 65
    Height = 13
    AutoSize = False
    Caption = 'Access Path'
  end
  object Label2: TLabel
    Left = 16
    Top = 43
    Width = 65
    Height = 13
    AutoSize = False
    Caption = 'Item Name'
  end
  object Label3: TLabel
    Left = 16
    Top = 72
    Width = 113
    Height = 13
    AutoSize = False
    Caption = 'AddressSpace'
  end
  object bAdd: TButton
    Left = 312
    Top = 16
    Width = 73
    Height = 21
    Caption = 'Add'
    Default = True
    TabOrder = 0
    OnClick = bAddClick
  end
  object bcancel: TButton
    Left = 312
    Top = 40
    Width = 73
    Height = 21
    Cancel = True
    Caption = 'Done'
    ModalResult = 2
    TabOrder = 1
  end
  object ePath: TEdit
    Left = 88
    Top = 16
    Width = 209
    Height = 20
    TabOrder = 2
  end
  object eName: TEdit
    Left = 88
    Top = 40
    Width = 209
    Height = 20
    TabOrder = 3
  end
  object tvBranch: TTreeView
    Left = 16
    Top = 88
    Width = 209
    Height = 169
    Indent = 19
    TabOrder = 4
    OnChange = tvBranchChange
  end
  object lbLeaf: TListBox
    Left = 224
    Top = 88
    Width = 169
    Height = 169
    ItemHeight = 12
    TabOrder = 5
    OnClick = lbLeafClick
    OnDblClick = lbLeafDblClick
  end
  object PropBtn: TButton
    Left = 280
    Top = 64
    Width = 105
    Height = 21
    Cancel = True
    Caption = 'Item Properties'
    TabOrder = 6
    OnClick = PropBtnClick
  end
end
