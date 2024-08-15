VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Begin VB.Form frmItemBrowser 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Item Browser"
   ClientHeight    =   3960
   ClientLeft      =   2760
   ClientTop       =   3750
   ClientWidth     =   6150
   Icon            =   "frmItemBrowser.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3960
   ScaleWidth      =   6150
   ShowInTaskbar   =   0   'False
   StartUpPosition =   2  'CenterScreen
   Begin VB.CommandButton Command1 
      Caption         =   "Item Properties"
      Height          =   255
      Left            =   4680
      TabIndex        =   9
      Top             =   960
      Width           =   1215
   End
   Begin VB.TextBox Text1 
      Height          =   285
      Left            =   1320
      TabIndex        =   6
      Top             =   600
      Width           =   3015
   End
   Begin VB.ListBox listItem 
      Height          =   2400
      ItemData        =   "frmItemBrowser.frx":000C
      Left            =   3240
      List            =   "frmItemBrowser.frx":000E
      TabIndex        =   5
      Top             =   1320
      Width           =   2655
   End
   Begin VB.TextBox txtItemName 
      Height          =   285
      Left            =   1320
      TabIndex        =   3
      Top             =   240
      Width           =   3015
   End
   Begin VB.CommandButton CancelButton 
      Caption         =   "&Done"
      Height          =   255
      Left            =   4680
      TabIndex        =   1
      Top             =   600
      Width           =   1215
   End
   Begin VB.CommandButton AddItem 
      Caption         =   "&Add Item"
      Default         =   -1  'True
      Height          =   255
      Left            =   4680
      TabIndex        =   0
      Top             =   240
      Width           =   1215
   End
   Begin MSComctlLib.TreeView TreeView1 
      Height          =   2445
      Left            =   240
      TabIndex        =   4
      Top             =   1320
      Width           =   3015
      _ExtentX        =   5318
      _ExtentY        =   4313
      _Version        =   393217
      Style           =   7
      Appearance      =   1
   End
   Begin VB.Label Label3 
      Caption         =   "Item Tree"
      Height          =   255
      Left            =   240
      TabIndex        =   8
      Top             =   960
      Width           =   1455
   End
   Begin VB.Label Label2 
      Caption         =   "Access Path"
      Height          =   255
      Left            =   240
      TabIndex        =   7
      Top             =   600
      Width           =   1215
   End
   Begin VB.Label Label1 
      Caption         =   "Item Name"
      Height          =   255
      Left            =   240
      TabIndex        =   2
      Top             =   240
      Width           =   975
   End
End
Attribute VB_Name = "frmItemBrowser"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Option Explicit
Private root As Node

Private Sub AddItem_Click()
   frmMain.AddItem txtItemName
End Sub

Private Sub CancelButton_Click()
    Unload Me
End Sub
Private Sub Browse()
    Dim NameSpace As Integer
    If ASDAC_GetNameSpace(ServerHandle, NameSpace) Then
        If NameSpace = 1 Then
            BrowseItems
        Else
            BrowseBranch
        End If
    End If
End Sub
Private Sub ChangePosition(n As Node)
    Dim buf(128) As Byte
    If n.root <> n Then
        ChangePosition n.Parent
        ASDAC_ChangeBrowsePosition ServerHandle, 2, n.Text
    Else
        ASDAC_ChangeBrowsePosition ServerHandle, 1, ""
    End If
End Sub
Private Sub BrowseBranch()
    Dim I, Count As Integer
    Dim n As Node
    Dim ItemNames As Variant
    
    If TreeView1.SelectedItem = "" Then Return
    Set n = TreeView1.SelectedItem
    ChangePosition n
    BrowseItems
    If n.Children = 0 Then
        Count = ASDAC_BrowseItems(ServerHandle, 1, "*", 0, 0, ItemNames)
        For I = 0 To Count - 1
            TreeView1.Nodes.Add n.Key, tvwChild, "", ItemNames(I)
        Next
        n.Expanded = True
    End If
End Sub
Private Sub BrowseItems()
    Dim I, Count As Integer
    Dim ItemNames As Variant
    
    listItem.Clear
    If TreeView1.SelectedItem = "" Then Return
    
    Count = ASDAC_BrowseItems(ServerHandle, 2, "*", 0, 0, ItemNames)
    For I = 0 To Count - 1
        listItem.AddItem ItemNames(I)
    Next
End Sub

Private Sub Command1_Click()
    If txtItemName.Text = "" Then Exit Sub
    frmItemStatus.ItemName = txtItemName.Text
    frmItemStatus.Show vbModal
End Sub

Private Sub Form_Load()
    Set root = TreeView1.Nodes.Add(, , "Root", "Root")
    TreeView1.SelectedItem = root
    BrowseBranch
    
End Sub

Private Sub listItem_Click()
    Dim FullName As String
    FullName = Space(128)
    If listItem.ListIndex = -1 Then Exit Sub
    If ASDAC_GetItemFullName(ServerHandle, listItem.List(listItem.ListIndex), FullName, 127) Then
        txtItemName.Text = FullName
    End If
End Sub

Private Sub listItem_DblClick()
    If listItem.ListIndex = -1 Then Exit Sub
    listItem_Click
    AddItem_Click
End Sub

Private Sub TreeView1_NodeClick(ByVal Node As MSComctlLib.Node)
    BrowseBranch
End Sub
