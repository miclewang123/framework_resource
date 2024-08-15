object ServerStatus: TServerStatus
  Left = 287
  Top = 323
  BorderStyle = bsDialog
  Caption = 'ServerStatus'
  ClientHeight = 228
  ClientWidth = 390
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 8
    Width = 81
    Height = 13
    AutoSize = False
    Caption = 'Start Time'
  end
  object Label2: TLabel
    Left = 24
    Top = 32
    Width = 81
    Height = 13
    AutoSize = False
    Caption = 'Current Time'
  end
  object Label3: TLabel
    Left = 24
    Top = 56
    Width = 89
    Height = 13
    AutoSize = False
    Caption = 'Last Update Time'
  end
  object Label4: TLabel
    Left = 24
    Top = 80
    Width = 81
    Height = 13
    AutoSize = False
    Caption = 'State'
  end
  object Label5: TLabel
    Left = 24
    Top = 104
    Width = 81
    Height = 13
    AutoSize = False
    Caption = 'Group Count'
  end
  object Label6: TLabel
    Left = 24
    Top = 128
    Width = 81
    Height = 13
    AutoSize = False
    Caption = 'Band Width'
  end
  object Label7: TLabel
    Left = 24
    Top = 152
    Width = 81
    Height = 13
    AutoSize = False
    Caption = 'Major Version'
  end
  object Label8: TLabel
    Left = 24
    Top = 176
    Width = 81
    Height = 13
    AutoSize = False
    Caption = 'Minor Version'
  end
  object Label9: TLabel
    Left = 24
    Top = 200
    Width = 81
    Height = 13
    AutoSize = False
    Caption = 'Build Version'
  end
  object OKBtn: TButton
    Left = 300
    Top = 8
    Width = 75
    Height = 21
    Caption = 'Done'
    Default = True
    ModalResult = 1
    TabOrder = 0
  end
  object StartTime: TEdit
    Left = 120
    Top = 8
    Width = 161
    Height = 21
    ReadOnly = True
    TabOrder = 1
  end
  object CurrentTime: TEdit
    Left = 120
    Top = 32
    Width = 161
    Height = 21
    ReadOnly = True
    TabOrder = 2
  end
  object LastUpdate: TEdit
    Left = 120
    Top = 56
    Width = 161
    Height = 21
    ReadOnly = True
    TabOrder = 3
  end
  object ServerState: TEdit
    Left = 120
    Top = 80
    Width = 161
    Height = 21
    ReadOnly = True
    TabOrder = 4
  end
  object GroupCount: TEdit
    Left = 120
    Top = 104
    Width = 161
    Height = 21
    ReadOnly = True
    TabOrder = 5
  end
  object BandWidth: TEdit
    Left = 120
    Top = 128
    Width = 161
    Height = 21
    ReadOnly = True
    TabOrder = 6
  end
  object MajorVersion: TEdit
    Left = 120
    Top = 152
    Width = 161
    Height = 21
    ReadOnly = True
    TabOrder = 7
  end
  object MinorVersion: TEdit
    Left = 120
    Top = 176
    Width = 161
    Height = 21
    ReadOnly = True
    TabOrder = 8
  end
  object BuildVersion: TEdit
    Left = 120
    Top = 200
    Width = 161
    Height = 21
    ReadOnly = True
    TabOrder = 9
  end
end
