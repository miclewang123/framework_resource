VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Begin VB.Form frmItemStatus 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Item Properties"
   ClientHeight    =   3150
   ClientLeft      =   2760
   ClientTop       =   3750
   ClientWidth     =   6030
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3150
   ScaleWidth      =   6030
   ShowInTaskbar   =   0   'False
   StartUpPosition =   2  'CenterScreen
   Begin MSComctlLib.ListView ListView1 
      Height          =   2895
      Left            =   120
      TabIndex        =   2
      Top             =   120
      Width           =   4455
      _ExtentX        =   7858
      _ExtentY        =   5106
      View            =   3
      LabelWrap       =   -1  'True
      HideSelection   =   -1  'True
      FullRowSelect   =   -1  'True
      _Version        =   393217
      ForeColor       =   -2147483640
      BackColor       =   -2147483643
      BorderStyle     =   1
      Appearance      =   1
      NumItems        =   2
      BeginProperty ColumnHeader(1) {BDD1F052-858B-11D1-B16A-00C0F0283628} 
         Text            =   "Key"
         Object.Width           =   3528
      EndProperty
      BeginProperty ColumnHeader(2) {BDD1F052-858B-11D1-B16A-00C0F0283628} 
         SubItemIndex    =   1
         Text            =   "Value"
         Object.Width           =   2540
      EndProperty
   End
   Begin VB.CommandButton RefreshButton 
      Caption         =   "Refresh"
      Height          =   375
      Left            =   4680
      TabIndex        =   1
      Top             =   600
      Width           =   1215
   End
   Begin VB.CommandButton OKButton 
      Caption         =   "Done"
      Default         =   -1  'True
      Height          =   375
      Left            =   4680
      TabIndex        =   0
      Top             =   120
      Width           =   1215
   End
End
Attribute VB_Name = "frmItemStatus"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Option Explicit
Public ItemName As String

Private Sub Form_Load()
    LoadProperties
End Sub

Private Sub OKButton_Click()
    Unload Me
End Sub

Private Sub LoadProperties()
    Dim I, Count As Long
    Dim lvItem As listItem
    Dim IDList, DataTypeList, DescList As Variant
    Dim v As Variant
    Count = ASDAC_GetItemProperties(ServerHandle, ItemName, IDList, DataTypeList, DescList)
    ListView1.ListItems.Clear
    For I = 0 To Count - 1
        If ASDAC_GetItemPropertyValue(ServerHandle, ItemName, IDList(I), v) Then
            Set lvItem = ListView1.ListItems.Add(, , DescList(I))
            lvItem.SubItems(1) = v
        End If
    Next
End Sub

Private Sub RefreshButton_Click()
    LoadProperties
End Sub
