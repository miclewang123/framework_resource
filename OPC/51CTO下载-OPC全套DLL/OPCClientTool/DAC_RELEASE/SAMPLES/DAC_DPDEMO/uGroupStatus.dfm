object GroupStatus: TGroupStatus
  Left = 416
  Top = 430
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'GroupStatus'
  ClientHeight = 148
  ClientWidth = 336
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 20
    Width = 73
    Height = 13
    AutoSize = False
    Caption = 'Name'
  end
  object Label2: TLabel
    Left = 16
    Top = 44
    Width = 60
    Height = 13
    AutoSize = False
    Caption = 'Update'
  end
  object Label3: TLabel
    Left = 16
    Top = 116
    Width = 73
    Height = 13
    AutoSize = False
    Caption = 'Time Bias'
  end
  object Label4: TLabel
    Left = 16
    Top = 92
    Width = 60
    Height = 13
    AutoSize = False
    Caption = 'Active'
  end
  object Label5: TLabel
    Left = 16
    Top = 68
    Width = 60
    Height = 13
    AutoSize = False
    Caption = 'DeadBand'
  end
  object Label6: TLabel
    Left = 200
    Top = 68
    Width = 33
    Height = 13
    AutoSize = False
    Caption = '%FS'
  end
  object Label7: TLabel
    Left = 200
    Top = 44
    Width = 33
    Height = 13
    AutoSize = False
    Caption = 'ms'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
  end
  object Button1: TButton
    Left = 248
    Top = 16
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 0
  end
  object Button2: TButton
    Left = 248
    Top = 48
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 1
  end
  object Name: TEdit
    Left = 88
    Top = 16
    Width = 121
    Height = 21
    TabOrder = 2
    Text = 'GROUP'
  end
  object UpdateRate: TEdit
    Left = 88
    Top = 40
    Width = 105
    Height = 21
    TabOrder = 3
    Text = '1000'
  end
  object TimeBias: TEdit
    Left = 88
    Top = 112
    Width = 121
    Height = 21
    TabOrder = 4
    Text = '-480'
  end
  object Active: TCheckBox
    Left = 88
    Top = 88
    Width = 97
    Height = 17
    Checked = True
    State = cbChecked
    TabOrder = 5
  end
  object DeadBand: TEdit
    Left = 88
    Top = 64
    Width = 105
    Height = 21
    TabOrder = 6
    Text = '0'
  end
end
