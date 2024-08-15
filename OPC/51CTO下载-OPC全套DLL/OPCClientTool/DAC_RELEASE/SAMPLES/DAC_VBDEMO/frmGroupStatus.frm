VERSION 5.00
Begin VB.Form frmGroupStatus 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Group Status"
   ClientHeight    =   2130
   ClientLeft      =   2760
   ClientTop       =   3750
   ClientWidth     =   5505
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   2130
   ScaleWidth      =   5505
   ShowInTaskbar   =   0   'False
   StartUpPosition =   2  'CenterScreen
   Begin VB.CheckBox Check1 
      Height          =   255
      Left            =   1320
      TabIndex        =   6
      Top             =   1680
      Width           =   735
   End
   Begin VB.TextBox Text4 
      Height          =   285
      Left            =   1320
      TabIndex        =   5
      Top             =   1320
      Width           =   1455
   End
   Begin VB.TextBox Text3 
      Height          =   285
      Left            =   1320
      TabIndex        =   4
      Top             =   960
      Width           =   2055
   End
   Begin VB.TextBox Text2 
      Height          =   285
      Left            =   1320
      TabIndex        =   3
      Top             =   600
      Width           =   2055
   End
   Begin VB.TextBox Text1 
      Height          =   285
      Left            =   1320
      TabIndex        =   2
      Top             =   240
      Width           =   2535
   End
   Begin VB.CommandButton CancelButton 
      Cancel          =   -1  'True
      Caption         =   "Cancel"
      Height          =   375
      Left            =   4080
      TabIndex        =   1
      Top             =   600
      Width           =   1215
   End
   Begin VB.CommandButton OKButton 
      Caption         =   "OK"
      Default         =   -1  'True
      Height          =   375
      Left            =   4080
      TabIndex        =   0
      Top             =   120
      Width           =   1215
   End
   Begin VB.Label Label1 
      Caption         =   "ms"
      Height          =   255
      Index           =   6
      Left            =   3480
      TabIndex        =   13
      Top             =   600
      Width           =   855
   End
   Begin VB.Label Label1 
      Caption         =   "% FS"
      Height          =   255
      Index           =   5
      Left            =   3480
      TabIndex        =   12
      Top             =   960
      Width           =   855
   End
   Begin VB.Label Label1 
      Caption         =   "Active"
      Height          =   255
      Index           =   4
      Left            =   240
      TabIndex        =   11
      Top             =   1680
      Width           =   855
   End
   Begin VB.Label Label1 
      Caption         =   "TimeBias"
      Height          =   255
      Index           =   3
      Left            =   240
      TabIndex        =   10
      Top             =   1320
      Width           =   855
   End
   Begin VB.Label Label1 
      Caption         =   "DeadBand"
      Height          =   255
      Index           =   2
      Left            =   240
      TabIndex        =   9
      Top             =   960
      Width           =   855
   End
   Begin VB.Label Label1 
      Caption         =   "Update Rate"
      Height          =   255
      Index           =   1
      Left            =   240
      TabIndex        =   8
      Top             =   600
      Width           =   1095
   End
   Begin VB.Label Label1 
      Caption         =   "Name"
      Height          =   255
      Index           =   0
      Left            =   240
      TabIndex        =   7
      Top             =   240
      Width           =   855
   End
End
Attribute VB_Name = "frmGroupStatus"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Option Explicit
Public mbReturn As Boolean
Public UpdateRate, TimeBias, LCID, Active As Long
Public DeadBand As Single
Public frmGroupName As String

Private Sub CancelButton_Click()
    Unload Me
End Sub

Private Sub Form_Load()
    mbReturn = False
    GetStat
End Sub
Private Sub GetStat()
    If ASDAC_GetGroupStat(ServerHandle, GroupHandle, UpdateRate, Active, TimeBias, DeadBand, LCID) Then
        Text1.Text = frmGroupName
        If Active = 0 Then Check1.Value = 0 Else Check1.Value = 1
        Text2.Text = CStr(UpdateRate)
        Text3.Text = CStr(DeadBand)
        Text4.Text = CStr(TimeBias)
    End If
End Sub
Private Sub OKButton_Click()
    mbReturn = True
    frmGroupName = Text1.Text
    UpdateRate = CLng(Text2.Text)
    TimeBias = CLng(Text4.Text)
    LCID = 0
    DeadBand = 0
    If Check1.Value = 0 Then Active = 0 Else Active = 1
    Unload Me
End Sub
