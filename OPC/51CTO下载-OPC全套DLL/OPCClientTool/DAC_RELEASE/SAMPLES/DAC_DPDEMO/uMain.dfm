object Form1: TForm1
  Left = 244
  Top = 286
  Width = 640
  Height = 480
  Caption = 'OPC DA Client by DELPHI(Agilewill Software co.ltd)'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object lvItems: TListView
    Left = 0
    Top = 0
    Width = 632
    Height = 415
    Align = alClient
    Columns = <
      item
        AutoSize = True
        Caption = 'Name'
      end
      item
        Caption = 'Value'
        Width = 120
      end
      item
        Caption = 'Quality'
      end
      item
        Caption = 'TimeStamp'
        Width = 150
      end>
    ReadOnly = True
    TabOrder = 0
    ViewStyle = vsReport
    OnClick = lvItemsClick
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 415
    Width = 632
    Height = 19
    Panels = <
      item
        Width = 180
      end
      item
        Width = 50
      end>
  end
  object MainMenu1: TMainMenu
    Left = 224
    Top = 40
    object mnOperate: TMenuItem
      Caption = 'OPC'
      object mnConnect: TMenuItem
        Caption = 'Connect...'
        OnClick = mnConnectClick
      end
      object mnDisconnect: TMenuItem
        Caption = 'Disconnect'
        Enabled = False
        OnClick = mnDisconnectClick
      end
      object mnServerStatus: TMenuItem
        Caption = 'Server Status...'
        Enabled = False
        OnClick = mnServerStatusClick
      end
      object N6: TMenuItem
        Caption = '-'
      end
      object mnGroupStatus: TMenuItem
        Caption = 'Group Parameters...'
        Enabled = False
        OnClick = mnGroupStatusClick
      end
      object N3: TMenuItem
        Caption = '-'
      end
      object mnItemAdd: TMenuItem
        Caption = 'Add Items'
        Enabled = False
        OnClick = mnItemAddClick
      end
      object mnItemProperties: TMenuItem
        Caption = 'Item Properties'
        Enabled = False
        OnClick = mnItemPropertiesClick
      end
      object mnItemRemove: TMenuItem
        Caption = 'Remove Item'
        Enabled = False
        OnClick = mnItemRemoveClick
      end
      object mnItemWrite: TMenuItem
        Caption = 'Write Value to Item'
        Enabled = False
        OnClick = mnItemWriteClick
      end
      object mnItemRead: TMenuItem
        Caption = 'Read item '
        Enabled = False
        OnClick = mnItemReadClick
      end
      object mnItemRefresh: TMenuItem
        Caption = 'Refresh'
        Enabled = False
      end
      object N11: TMenuItem
        Caption = '-'
      end
      object mnExit: TMenuItem
        Caption = 'Exit'
        OnClick = mnExitClick
      end
    end
    object mnHelp: TMenuItem
      Caption = 'Help'
      object mnAbout: TMenuItem
        Caption = 'About'
      end
    end
  end
end
