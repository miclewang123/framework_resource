Attribute VB_Name = "Module1"
Option Explicit

'Time convert functions
Private Const rDayZeroBias As Double = 109205#
Private Const rMillisecondPerDay As Double = 10000000# * 60# * 60# * 24# / 10000#

Public Type FILETIME
    dwLowDateTime As Long
    dwHighDateTime As Long
End Type

Declare Function FileTimeToLocalFileTime Lib "kernel32" (lpFileTime As FILETIME, lpLocalFileTime As FILETIME) As Long
Declare Function LocalFileTimeToFileTime Lib "kernel32" (lpLocalFileTime As Any, lpFileTime As Any) As Long
Declare Sub CopyMemory Lib "kernel32" Alias "RtlMoveMemory" (hpvDest As Any, hpvSource As Any, ByVal cbCopy As Long)

Public ServerHandle, GroupHandle As Long
Public GroupName  As String

Public Type ServerItem
    ServerName As String
    ServerClassID As String
End Type

Public ServerItems(99) As ServerItem

Public Type OPCItem
    Handle As Long
    Name As String
    Value As Variant
    Quality As Integer
    Ft As FILETIME
    Index As Long
End Type

Public ItemArr(1024) As OPCItem
Public ItemIndex As Integer

Public Function DoubleToFileTime(ByVal Value As Double) As FILETIME
    Dim ftdt As FILETIME
    CopyMemory ftdt, Value, Len(Value)
    DoubleToFileTime = ftdt
End Function

Public Function FileTimeToDate(hFileTime As FILETIME) As Date
    Dim ftl As Currency, Ft As FILETIME
    FileTimeToLocalFileTime hFileTime, Ft
    CopyMemory ftl, Ft, Len(Ft)
    FileTimeToDate = CDate((ftl / rMillisecondPerDay) - rDayZeroBias)
End Function

Public Function Finditem(ItemHandle As Long) As Integer
    Dim I As Integer
    For I = 1 To ItemIndex
        If ItemArr(I).Handle = ItemHandle Then
            Finditem = ItemArr(I).Index
            Exit For
        End If
    Next
End Function

Public Function AddItem(ItemName As String) As Integer
    Dim h As Long
    If ItemIndex > 1023 Then Exit Function
    h = ASDAC_AddItem(ServerHandle, GroupHandle, ItemName)
    If h > 0 Then
        ItemIndex = ItemIndex + 1
        ItemArr(ItemIndex).Handle = h
        ItemArr(ItemIndex).Name = ItemName
        ItemArr(ItemIndex).Index = ItemIndex
        AddItem = ItemIndex
    End If
End Function

Public Function RemoveItem(Index As Long) As Boolean
    If Index > 0 And Index < 1025 Then
        If ASDAC_RemoveItem(ServerHandle, GroupHandle, ItemArr(Index).Handle) Then
            ItemArr(Index).Handle = 0
            RemoveItem = True
        End If
    End If
End Function

Sub ServerDataChangeProc(ByVal ServerHandle As Long, ByVal GroupHandle As Long, ByVal ItemHandle As Long, ByVal Value As Variant, ByVal Ft As Double, ByVal Quality As Integer)
    Dim Index As Integer
    Index = Finditem(ItemHandle)
    If Index > 0 Then
        ItemArr(Index).Ft = DoubleToFileTime(Ft)
        ItemArr(Index).Value = Value
        ItemArr(Index).Quality = Quality
        frmMain.RefreshItem (Index)
    End If
End Sub

Sub ServerShutdownProc(ByVal ServerHandle As Long)
    frmMain.Disconnect
End Sub



