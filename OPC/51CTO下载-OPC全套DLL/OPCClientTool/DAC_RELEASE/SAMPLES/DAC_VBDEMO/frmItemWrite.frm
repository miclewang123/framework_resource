VERSION 5.00
Begin VB.Form frmItemWrite 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Write OPC Item"
   ClientHeight    =   1200
   ClientLeft      =   2760
   ClientTop       =   3750
   ClientWidth     =   3975
   Icon            =   "frmItemWrite.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   1200
   ScaleWidth      =   3975
   ShowInTaskbar   =   0   'False
   StartUpPosition =   2  'CenterScreen
   Begin VB.CheckBox ckAsync 
      Caption         =   "Async Write"
      Height          =   255
      Left            =   240
      TabIndex        =   3
      Top             =   720
      Width           =   1575
   End
   Begin VB.TextBox txtValue 
      Height          =   375
      Left            =   240
      TabIndex        =   2
      Top             =   120
      Width           =   2055
   End
   Begin VB.CommandButton CancelButton 
      Caption         =   "&Cancel"
      Height          =   375
      Left            =   2520
      TabIndex        =   1
      Top             =   600
      Width           =   1215
   End
   Begin VB.CommandButton OKButton 
      Caption         =   "&OK"
      Default         =   -1  'True
      Height          =   375
      Left            =   2520
      TabIndex        =   0
      Top             =   120
      Width           =   1215
   End
End
Attribute VB_Name = "frmItemWrite"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public mbReturn As Boolean
Public Value As String
Public Async As Long

Private Sub CancelButton_Click()
    mbReturn = False
    Unload Me
End Sub

Private Sub OKButton_Click()
    mbReturn = True
    Value = txtValue.Text
    Async = ckAsync.Value
    Unload Me
End Sub
