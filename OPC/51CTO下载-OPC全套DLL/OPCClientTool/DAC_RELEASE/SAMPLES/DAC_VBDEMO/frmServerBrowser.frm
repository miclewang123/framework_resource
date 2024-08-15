VERSION 5.00
Begin VB.Form frmServerBrowser 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Server Browser"
   ClientHeight    =   3465
   ClientLeft      =   2760
   ClientTop       =   3750
   ClientWidth     =   6150
   Icon            =   "frmServerBrowser.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3465
   ScaleWidth      =   6150
   ShowInTaskbar   =   0   'False
   StartUpPosition =   1  'CenterOwner
   Begin VB.TextBox txtServerName 
      Enabled         =   0   'False
      Height          =   285
      Left            =   1440
      TabIndex        =   11
      Top             =   240
      Width           =   3015
   End
   Begin VB.TextBox txtComputer 
      Height          =   270
      Left            =   1440
      TabIndex        =   10
      Top             =   960
      Width           =   3015
   End
   Begin VB.TextBox txtServerClassID 
      Enabled         =   0   'False
      Height          =   285
      Left            =   1440
      TabIndex        =   8
      Top             =   600
      Width           =   3015
   End
   Begin VB.CommandButton cmdFind 
      Caption         =   "Refresh List"
      Height          =   255
      Left            =   4680
      TabIndex        =   4
      Top             =   1320
      Width           =   1215
   End
   Begin VB.CheckBox ckVer1 
      Caption         =   "2.0"
      Height          =   255
      Left            =   2760
      TabIndex        =   3
      Top             =   1320
      Width           =   1695
   End
   Begin VB.ListBox listServer 
      Height          =   1620
      Left            =   240
      TabIndex        =   2
      Top             =   1680
      Width           =   5655
   End
   Begin VB.CommandButton CancelButton 
      Caption         =   "&Cancel"
      Height          =   255
      Left            =   4680
      TabIndex        =   1
      Top             =   600
      Width           =   1215
   End
   Begin VB.CommandButton OKButton 
      Caption         =   "&OK"
      Default         =   -1  'True
      Height          =   255
      Left            =   4680
      TabIndex        =   0
      Top             =   240
      Width           =   1215
   End
   Begin VB.Label Label4 
      Caption         =   "Server ClassID"
      Height          =   255
      Left            =   240
      TabIndex        =   9
      Top             =   600
      Width           =   1095
   End
   Begin VB.Label Label3 
      Caption         =   "Server List:"
      Height          =   255
      Left            =   240
      TabIndex        =   7
      Top             =   1320
      Width           =   1215
   End
   Begin VB.Label Label2 
      Caption         =   "Computer"
      Height          =   255
      Left            =   240
      TabIndex        =   6
      Top             =   960
      Width           =   975
   End
   Begin VB.Label Label1 
      Caption         =   "Server Name"
      Height          =   255
      Left            =   240
      TabIndex        =   5
      Top             =   240
      Width           =   975
   End
End
Attribute VB_Name = "frmServerBrowser"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Option Explicit


Public ComputerName As String
Public ServerName As String
Public ServerClassID As String

Public Version As Long
Public mbReturn As Boolean

Private Sub CancelButton_Click()
    mbReturn = False
    Unload Me
End Sub

Private Sub cmdFind_Click()
    Dim Count, I As Long
    Dim ServerNames, ServerClassIDs As Variant
    
    listServer.Clear
    ComputerName = txtComputer.Text
    txtServerName.Text = ""
    txtServerClassID.Text = ""
    If ckVer1.Value = 0 Then Version = 1 Else Version = 2
    
    Count = ASDAC_GetServers(txtComputer.Text, Version, ServerNames, ServerClassIDs)
    For I = 0 To Count - 1
        ServerItems(I).ServerName = ServerNames(I)
        ServerItems(I).ServerClassID = ServerClassIDs(I)
        listServer.AddItem ServerNames(I)
    Next I
    
End Sub

Private Sub Form_Load()
    mbReturn = False
    Version = 2
    ckVer1.Value = 1
    txtComputer.Text = ""
    txtServerName.Text = ""
    txtServerClassID.Text = ""
    cmdFind_Click
End Sub

Private Sub listServer_Click()
    If listServer.ListIndex = -1 Then Exit Sub
    txtServerName.Text = ServerItems(listServer.ListIndex).ServerName
    txtServerClassID.Text = ServerItems(listServer.ListIndex).ServerClassID
    ServerName = txtServerName.Text
    ServerClassID = txtServerClassID.Text
End Sub

Private Sub OKButton_Click()
    mbReturn = True
    Unload Me
End Sub
