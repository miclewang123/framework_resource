object ServerBrowser: TServerBrowser
  Left = 387
  Top = 448
  BorderStyle = bsDialog
  Caption = 'Server Browser'
  ClientHeight = 221
  ClientWidth = 347
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #23435#20307
  Font.Style = []
  OldCreateOrder = True
  Position = poMainFormCenter
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 12
  object Label2: TLabel
    Left = 16
    Top = 48
    Width = 81
    Height = 13
    AutoSize = False
    Caption = 'Server Name'
  end
  object Label1: TLabel
    Left = 16
    Top = 8
    Width = 73
    Height = 17
    AutoSize = False
    Caption = 'Server Node'
  end
  object OKBtn: TButton
    Left = 256
    Top = 16
    Width = 73
    Height = 20
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 0
  end
  object CancelBtn: TButton
    Left = 256
    Top = 38
    Width = 73
    Height = 20
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 1
  end
  object RefreshBtn: TButton
    Left = 256
    Top = 64
    Width = 73
    Height = 20
    Caption = 'Refresh'
    TabOrder = 2
    OnClick = RefreshBtnClick
  end
  object Servers: TListBox
    Left = 16
    Top = 112
    Width = 313
    Height = 97
    ItemHeight = 12
    TabOrder = 3
    OnClick = ServersClick
    OnDblClick = ServersDblClick
  end
  object rbV1: TRadioButton
    Left = 208
    Top = 88
    Width = 49
    Height = 17
    Caption = '1.0'
    TabOrder = 4
  end
  object rbV2: TRadioButton
    Left = 272
    Top = 88
    Width = 57
    Height = 17
    Caption = '2.0'
    Checked = True
    TabOrder = 5
    TabStop = True
  end
  object ServerName: TEdit
    Left = 16
    Top = 64
    Width = 233
    Height = 20
    TabOrder = 6
  end
  object ServerNode: TEdit
    Left = 16
    Top = 24
    Width = 233
    Height = 20
    TabOrder = 7
  end
end
