object ItemStatus: TItemStatus
  Left = 515
  Top = 573
  BorderStyle = bsDialog
  Caption = 'Item Properties'
  ClientHeight = 194
  ClientWidth = 384
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object OKBtn: TButton
    Left = 300
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Done'
    Default = True
    ModalResult = 1
    TabOrder = 0
  end
  object RefreshBtn: TButton
    Left = 300
    Top = 40
    Width = 75
    Height = 25
    Caption = 'Refresh'
    TabOrder = 1
    OnClick = RefreshBtnClick
  end
  object Props: TValueListEditor
    Left = 8
    Top = 8
    Width = 281
    Height = 177
    TabOrder = 2
    ColWidths = (
      150
      125)
  end
end
