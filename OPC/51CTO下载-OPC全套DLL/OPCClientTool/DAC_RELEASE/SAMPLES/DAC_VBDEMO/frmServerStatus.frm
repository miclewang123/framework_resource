VERSION 5.00
Begin VB.Form frmServerStatus 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Server Status"
   ClientHeight    =   3630
   ClientLeft      =   2760
   ClientTop       =   3750
   ClientWidth     =   5730
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3630
   ScaleWidth      =   5730
   ShowInTaskbar   =   0   'False
   StartUpPosition =   2  'CenterScreen
   Begin VB.TextBox Text9 
      Enabled         =   0   'False
      Height          =   285
      Left            =   1680
      TabIndex        =   15
      Top             =   3120
      Width           =   2535
   End
   Begin VB.TextBox Text8 
      Enabled         =   0   'False
      Height          =   285
      Left            =   1680
      TabIndex        =   14
      Top             =   2760
      Width           =   2535
   End
   Begin VB.TextBox Text7 
      Enabled         =   0   'False
      Height          =   285
      Left            =   1680
      TabIndex        =   13
      Top             =   2400
      Width           =   2535
   End
   Begin VB.TextBox Text1 
      Enabled         =   0   'False
      Height          =   285
      Left            =   1680
      TabIndex        =   12
      Top             =   240
      Width           =   2535
   End
   Begin VB.TextBox Text6 
      Enabled         =   0   'False
      Height          =   285
      Left            =   1680
      TabIndex        =   8
      Top             =   2040
      Width           =   2535
   End
   Begin VB.TextBox Text5 
      Enabled         =   0   'False
      Height          =   285
      Left            =   1680
      TabIndex        =   7
      Top             =   1680
      Width           =   2535
   End
   Begin VB.TextBox Text4 
      Enabled         =   0   'False
      Height          =   285
      Left            =   1680
      TabIndex        =   6
      Top             =   1320
      Width           =   2535
   End
   Begin VB.TextBox Text3 
      Enabled         =   0   'False
      Height          =   285
      Left            =   1680
      TabIndex        =   5
      Top             =   960
      Width           =   2535
   End
   Begin VB.TextBox Text2 
      Enabled         =   0   'False
      Height          =   285
      Left            =   1680
      TabIndex        =   4
      Top             =   600
      Width           =   2535
   End
   Begin VB.CommandButton OKButton 
      Caption         =   "Done"
      Default         =   -1  'True
      Height          =   375
      Left            =   4320
      TabIndex        =   0
      Top             =   240
      Width           =   1215
   End
   Begin VB.Label Label1 
      Caption         =   "Build Number"
      Height          =   255
      Index           =   8
      Left            =   240
      TabIndex        =   18
      Top             =   3120
      Width           =   1335
   End
   Begin VB.Label Label1 
      Caption         =   "Minor Version"
      Height          =   255
      Index           =   7
      Left            =   240
      TabIndex        =   17
      Top             =   2760
      Width           =   1335
   End
   Begin VB.Label Label1 
      Caption         =   "Major Version"
      Height          =   255
      Index           =   6
      Left            =   240
      TabIndex        =   16
      Top             =   2400
      Width           =   1335
   End
   Begin VB.Label Label1 
      Caption         =   "Group Count"
      Height          =   255
      Index           =   5
      Left            =   240
      TabIndex        =   11
      Top             =   2040
      Width           =   1335
   End
   Begin VB.Label Label1 
      Caption         =   "Server State"
      Height          =   255
      Index           =   4
      Left            =   240
      TabIndex        =   10
      Top             =   1680
      Width           =   1335
   End
   Begin VB.Label Label1 
      Caption         =   "Band Width"
      Height          =   255
      Index           =   3
      Left            =   240
      TabIndex        =   9
      Top             =   1320
      Width           =   1335
   End
   Begin VB.Label Label1 
      Caption         =   "Last Update Time"
      Height          =   255
      Index           =   2
      Left            =   240
      TabIndex        =   3
      Top             =   960
      Width           =   1335
   End
   Begin VB.Label Label1 
      Caption         =   "Current Time"
      Height          =   255
      Index           =   1
      Left            =   240
      TabIndex        =   2
      Top             =   600
      Width           =   1335
   End
   Begin VB.Label Label1 
      Caption         =   "Start Time"
      Height          =   255
      Index           =   0
      Left            =   240
      TabIndex        =   1
      Top             =   240
      Width           =   735
   End
End
Attribute VB_Name = "frmServerStatus"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Option Explicit

Private Sub Form_Load()

End Sub

Private Sub OKButton_Click()
  Unload Me
End Sub
