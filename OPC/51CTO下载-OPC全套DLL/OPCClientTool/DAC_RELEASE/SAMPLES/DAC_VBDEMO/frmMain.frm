VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Begin VB.Form frmMain 
   Caption         =   "OPC DA Client Demo by VB(Agilewill software co.ltd)"
   ClientHeight    =   6105
   ClientLeft      =   165
   ClientTop       =   450
   ClientWidth     =   9915
   Icon            =   "frmMain.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   6105
   ScaleWidth      =   9915
   StartUpPosition =   2  'CenterScreen
   Begin MSComctlLib.ListView lvListView 
      Height          =   2055
      Left            =   120
      TabIndex        =   1
      Top             =   360
      Width           =   1455
      _ExtentX        =   2566
      _ExtentY        =   3625
      View            =   3
      LabelEdit       =   1
      LabelWrap       =   -1  'True
      HideSelection   =   -1  'True
      FullRowSelect   =   -1  'True
      HotTracking     =   -1  'True
      _Version        =   393217
      ForeColor       =   -2147483640
      BackColor       =   -2147483643
      BorderStyle     =   1
      Appearance      =   1
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      NumItems        =   5
      BeginProperty ColumnHeader(1) {BDD1F052-858B-11D1-B16A-00C0F0283628} 
         Text            =   "Name"
         Object.Width           =   3881
      EndProperty
      BeginProperty ColumnHeader(2) {BDD1F052-858B-11D1-B16A-00C0F0283628} 
         SubItemIndex    =   1
         Text            =   "Value"
         Object.Width           =   3351
      EndProperty
      BeginProperty ColumnHeader(3) {BDD1F052-858B-11D1-B16A-00C0F0283628} 
         SubItemIndex    =   2
         Text            =   "Quality"
         Object.Width           =   3351
      EndProperty
      BeginProperty ColumnHeader(4) {BDD1F052-858B-11D1-B16A-00C0F0283628} 
         SubItemIndex    =   3
         Text            =   "TimeStamp"
         Object.Width           =   3351
      EndProperty
      BeginProperty ColumnHeader(5) {BDD1F052-858B-11D1-B16A-00C0F0283628} 
         SubItemIndex    =   4
         Object.Width           =   2540
      EndProperty
   End
   Begin MSComctlLib.StatusBar sbStatusBar 
      Align           =   2  'Align Bottom
      Height          =   270
      Left            =   0
      TabIndex        =   0
      Top             =   5835
      Width           =   9915
      _ExtentX        =   17489
      _ExtentY        =   476
      _Version        =   393216
      BeginProperty Panels {8E3867A5-8586-11D1-B16A-00C0F0283628} 
         NumPanels       =   3
         BeginProperty Panel1 {8E3867AB-8586-11D1-B16A-00C0F0283628} 
            AutoSize        =   1
            Object.Width           =   11853
            Text            =   "Status"
            TextSave        =   "Status"
         EndProperty
         BeginProperty Panel2 {8E3867AB-8586-11D1-B16A-00C0F0283628} 
            Style           =   6
            AutoSize        =   2
            TextSave        =   "2005-11-22"
         EndProperty
         BeginProperty Panel3 {8E3867AB-8586-11D1-B16A-00C0F0283628} 
            Style           =   5
            AutoSize        =   2
            TextSave        =   "22:10"
         EndProperty
      EndProperty
   End
   Begin MSComDlg.CommonDialog dlgCommonDialog 
      Left            =   1740
      Top             =   1350
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin VB.Menu mnuFile 
      Caption         =   "&File"
      Begin VB.Menu mnuExit 
         Caption         =   "Exit"
      End
   End
   Begin VB.Menu mnuOpc 
      Caption         =   "&OPC"
      Begin VB.Menu mnuConnect 
         Caption         =   "&Connect"
      End
      Begin VB.Menu mnuDisconnect 
         Caption         =   "&Disconnect"
         Enabled         =   0   'False
      End
      Begin VB.Menu mnuServerStatus 
         Caption         =   "Server Status"
         Enabled         =   0   'False
      End
      Begin VB.Menu mnuSplit2 
         Caption         =   "-"
      End
      Begin VB.Menu mnuGroupStatus 
         Caption         =   "Group Stat"
         Enabled         =   0   'False
      End
      Begin VB.Menu mnuGroupRefresh 
         Caption         =   "Refresh Data"
         Enabled         =   0   'False
      End
      Begin VB.Menu mnuSplit 
         Caption         =   "-"
      End
      Begin VB.Menu mnuAddItem 
         Caption         =   "&Add Item"
         Enabled         =   0   'False
      End
      Begin VB.Menu mnuRemoveItem 
         Caption         =   "&Remove Item"
         Enabled         =   0   'False
      End
      Begin VB.Menu mnuReadItem 
         Caption         =   "R&ead Item"
         Enabled         =   0   'False
      End
      Begin VB.Menu mnuWriteItem 
         Caption         =   "&Write Item"
         Enabled         =   0   'False
      End
      Begin VB.Menu mnuItemStatus 
         Caption         =   "Item Properties"
         Enabled         =   0   'False
      End
   End
   Begin VB.Menu mnuHelp 
      Caption         =   "&Help"
      Begin VB.Menu mnuHelpAbout 
         Caption         =   "&About"
      End
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public Sub Disconnect()
    If ServerHandle = 0 Then Exit Sub
    If GroupHandle > 0 Then
        lvListView.ListItems.Clear
        ASDAC_RemoveGroup ServerHandle, GroupHandle
    End If
    
    If ASDAC_Disconnect(ServerHandle) Then
        ServerHandle = 0
        GroupHandle = 0
        mnuConnect.Enabled = True
        mnuDisconnect.Enabled = False
        mnuServerStatus.Enabled = False
        mnuGroupStatus.Enabled = False
        mnuGroupRefresh.Enabled = False
        mnuAddItem.Enabled = False
        mnuAddItem.Enabled = False
        mnuRemoveItem.Enabled = False
        mnuReadItem.Enabled = False
        mnuWriteItem.Enabled = False
        mnuItemStatus.Enabled = False
    End If
End Sub

Private Sub Form_Load()
    ServerHandle = 0
    GroupHandle = 0
    ItemIndex = 0
    GroupName = "GROUP"
    '序列号用户使用
    'AS_ActiveCode "", ""
    Call ASDAC_Init
    
End Sub

Private Sub Form_Unload(Cancel As Integer)
    If ServerHandle > -1 Then
        ASDAC_Disconnect ServerHandle
    End If
    ASDAC_Uninit
End Sub


Private Sub Form_Resize()
    On Error Resume Next
    If Me.Width < 3000 Then Me.Width = 3000
    lvListView.Top = 0
    lvListView.Left = 10
    lvListView.Width = Me.Width - 120
    lvListView.Height = Me.ScaleHeight - sbStatusBar.Height
End Sub

Private Sub lvListView_ItemClick(ByVal Item As MSComctlLib.listItem)
    If lvListView.SelectedItem Is Nothing Then Exit Sub
    mnuReadItem.Enabled = True
    mnuWriteItem.Enabled = True
    mnuItemStatus.Enabled = True
    mnuRemoveItem.Enabled = True
End Sub

Private Sub mnuAddItem_Click()
    frmItemBrowser.Show vbModal, Me
End Sub

Private Sub mnuConnect_Click()
    frmServerBrowser.Show vbModal, Me
    If frmServerBrowser.mbReturn = False Then Exit Sub
    If Len(frmServerBrowser.ServerClassID) < 1 Then Exit Sub
    
    ServerHandle = ASDAC_Connect(frmServerBrowser.ComputerName, frmServerBrowser.ServerClassID, frmServerBrowser.Version)
    If ServerHandle > 0 Then
        ASDAC_SetDataChangeProc ServerHandle, AddressOf ServerDataChangeProc
        ASDAC_SetShutdownProc ServerHandle, AddressOf ServerShutdownProc
        GroupHandle = ASDAC_AddGroup(ServerHandle, GroupName, True, 1000, 0, 0, 0)
        If GroupHandle > 0 Then
            mnuConnect.Enabled = False
            mnuDisconnect.Enabled = True
            mnuServerStatus.Enabled = True
            mnuGroupStatus.Enabled = True
            mnuGroupRefresh.Enabled = True
            mnuAddItem.Enabled = True
        End If
    End If
End Sub

Private Sub mnuDisconnect_Click()
     If ASDAC_Disconnect(ServerHandle) Then
            lvListView.ListItems.Clear
            GroupHandle = 0
            ServerHandle = 0
            mnuConnect.Enabled = True
            mnuDisconnect.Enabled = False
            mnuServerStatus.Enabled = False
            mnuGroupStatus.Enabled = False
            mnuGroupRefresh.Enabled = False
            mnuAddItem.Enabled = False
            mnuReadItem.Enabled = False
            mnuWriteItem.Enabled = False
            mnuRemoveItem.Enabled = False
            mnuItemStatus.Enabled = False
     End If
End Sub

Private Sub mnuExit_Click()
    Unload Me
End Sub

Private Sub mnuGroupStatus_Click()
    frmGroupStatus.frmGroupName = GroupName
    frmGroupStatus.Show vbModal, Me
    If frmGroupStatus.mbReturn Then
        If frmGroupStatus.frmGroupName <> GroupName Then
            If ASDAC_SetGroupName(ServerHandle, GroupHandle, frmGroupStatus.frmGroupName) Then
                GroupName = frmGroupStatus.frmGroupName
            End If
        End If
        ASDAC_SetGroupStat ServerHandle, GroupHandle, frmGroupStatus.UpdateRate, frmGroupStatus.Active, frmGroupStatus.TimeBias, frmGroupStatus.DeadBand, 0
    End If
End Sub

Private Sub mnuHelpAbout_Click()
    frmAbout.Show vbModal, Me
End Sub

Private Sub mnuItemStatus_Click()
    If lvListView.SelectedItem Is Nothing Then Exit Sub
    frmItemStatus.ItemName = lvListView.SelectedItem.Text
    frmItemStatus.Show vbModal, Me
End Sub

Private Sub mnuReadItem_Click()
    Dim lvItem As listItem
    
    If lvListView.SelectedItem Is Nothing Then Exit Sub
    Dim Var As Variant
    Dim Ft As Double
    Dim ftdt As FILETIME
    Dim Quality As Integer
    
    
    If ASDAC_ReadItem(ServerHandle, GroupHandle, ItemArr(lvListView.SelectedItem.Tag).Handle, Var, Ft, Quality) Then
        CopyMemory ftdt, Ft, Len(Ft)
        ItemArr(lvListView.SelectedItem.Tag).Value = Var
        ItemArr(lvListView.SelectedItem.Tag).Quality = Quality
        ItemArr(lvListView.SelectedItem.Tag).Ft = ftdt
        lvListView.SelectedItem.SubItems(1) = Var
        lvListView.SelectedItem.SubItems(2) = CStr(Quality)
        lvListView.SelectedItem.SubItems(3) = CStr(FileTimeToDate(ftdt))
    End If
End Sub


Private Sub mnuGroupRefresh_Click()
    ASDAC_RefreshGroup ServerHandle, GroupHandle, 1
End Sub


Private Sub mnuRemoveItem_Click()
    Dim lvItem As listItem
    
    If lvListView.SelectedItem Is Nothing Then Exit Sub
    
    If RemoveItem(lvListView.SelectedItem.Tag) Then
        lvListView.ListItems.Remove lvListView.SelectedItem.Index
    End If
End Sub

Public Sub AddItem(ItemName As String)
    Dim Index As Long
    Dim lvItem As listItem
    Index = Module1.AddItem(ItemName)
    If Index > 0 Then
        Set lvItem = lvListView.ListItems.Add(1, "K" + CStr(Index), ItemName)
        lvItem.Tag = Index
        lvItem.SubItems(1) = "Bad"
        lvItem.SubItems(2) = ""
        lvItem.SubItems(3) = ""
    End If
End Sub

Public Sub RefreshItem(Index As Integer)
    Dim lvItem As listItem
    Set lvItem = lvListView.ListItems("K" + CStr(Index))
    If lvItem Is Nothing Then Exit Sub
    lvItem.SubItems(1) = ItemArr(Index).Value
    lvItem.SubItems(2) = CStr(ItemArr(Index).Quality)
    lvItem.SubItems(3) = CStr(FileTimeToDate(ItemArr(Index).Ft))
End Sub

Private Sub mnuServerStatus_Click()
    Dim ftStart, ftCurrent, ftUpdate As Double
    Dim BandWidth, GroupCount As Long
    Dim State, MajorVersion, MinorVersion, BuildNumber As Integer
    Dim vendor As String
    vendor = Space(128)
    If ASDAC_GetServerStatus(ServerHandle, ftStart, ftCurrent, ftUpdate, State, BandWidth, GroupCount, MajorVersion, MinorVersion, BuildNumber, vendor, 128) Then
        frmServerStatus.Text1.Text = CStr(FileTimeToDate(DoubleToFileTime(ftStart)))
        frmServerStatus.Text2.Text = CStr(FileTimeToDate(DoubleToFileTime(ftCurrent)))
        frmServerStatus.Text3.Text = CStr(FileTimeToDate(DoubleToFileTime(ftUpdate)))
        frmServerStatus.Text4.Text = CStr(BandWidth)
        frmServerStatus.Text5.Text = CStr(State)
        frmServerStatus.Text6.Text = CStr(GroupCount)
        frmServerStatus.Text7.Text = CStr(MajorVersion)
        frmServerStatus.Text8.Text = CStr(MinorVersion)
        frmServerStatus.Text9.Text = CStr(BuildNumber)
        frmServerStatus.Show vbModal, Me
    End If
End Sub

Private Sub mnuWriteItem_Click()
    Dim Index As Long
    Dim Value As Variant
    If lvListView.SelectedItem Is Nothing Then Exit Sub
    frmItemWrite.Show vbModal, Me
    If frmItemWrite.mbReturn = False Then Exit Sub
    If frmItemWrite.Value = "" Then Exit Sub
    
    Index = lvListView.SelectedItem.Tag
    Value = frmItemWrite.Value
   
    If ASDAC_WriteItem(ServerHandle, GroupHandle, ItemArr(Index).Handle, Value, frmItemWrite.Async) Then
        ItemArr(Index).Value = Value
        lvListView.SelectedItem.SubItems(1) = Value
    End If
End Sub

