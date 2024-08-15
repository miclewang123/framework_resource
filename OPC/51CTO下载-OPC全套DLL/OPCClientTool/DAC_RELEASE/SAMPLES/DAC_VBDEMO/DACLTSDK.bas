Attribute VB_Name = "DACLTSDK"
Option Explicit



Declare Function ASDAC_GetVersion Lib "DACLTSDK.dll" () As Long
Declare Function ASDAC_Init Lib "DACLTSDK.dll" () As Long
Declare Function ASDAC_Uninit Lib "DACLTSDK.dll" () As Long
Declare Function ASDAC_ActiveCode Lib "DACLTSDK.dll" (ByVal regName As String, ByRef regCode As String) As Long
Declare Function ASDAC_GetServers Lib "DACLTSDK.dll" (ByVal Host As String, ByVal Version As Long, ServerNames As Variant, _
    ServerClassIDs As Variant) As Long
Declare Function ASDAC_Connect Lib "DACLTSDK.dll" (ByVal Host As String, ByVal ServerClass As String, ByVal Version As Long) As Long
Declare Function ASDAC_Disconnect Lib "DACLTSDK.dll" (ByVal ServerHandle As Long) As Long
Declare Function ASDAC_GetServerStatus Lib "DACLTSDK.dll" (ByVal ServerHandle As Long, ByRef StartTime As Double, _
    ByRef CurrentTime As Double, ByRef LastUpdateTime As Double, ByRef State As Integer, ByRef BandWidth As Long, _
    ByRef GroupCount As Long, ByRef MajorVersion As Integer, ByRef MinorVersion As Integer, ByRef BuildNumber As Integer, _
    ByVal vendor As String, ByVal size As Long) As Long

Declare Function ASDAC_AddGroup Lib "DACLTSDK.dll" (ByVal ServerHandle As Long, ByVal Name As String, ByVal Active As Long, _
    ByVal UpdateRate As Long, ByVal TimeBias As Long, ByVal DeadBand As Single, ByVal LCID As Long) As Long
Declare Function ASDAC_RemoveGroup Lib "DACLTSDK.dll" (ByVal ServerHandle As Long, ByVal GroupHandle As Long)
Declare Function ASDAC_SetGroupName Lib "DACLTSDK.dll" (ByVal ServerHandle As Long, ByVal GroupHandle As Long, ByVal Name As String) As Long
Declare Function ASDAC_SetGroupStat Lib "DACLTSDK.dll" (ByVal ServerHandle As Long, ByVal GroupHandle As Long, _
    ByVal UpdateRate As Long, ByVal Active As Long, ByVal TimeBias As Long, ByVal DeadBand As Single, ByVal LCID As Long) As Long
Declare Function ASDAC_GetGroupStat Lib "DACLTSDK.dll" (ByVal ServerHandle As Long, ByVal GroupHandle As Long, _
    ByRef UpdateRate As Long, ByRef pActive As Long, ByRef pTimeBias As Long, ByRef pDeadBand As Single, ByRef pLCID As Long) As Long
Declare Function ASDAC_RefreshGroup Lib "DACLTSDK.dll" (ByVal ServerHandle As Long, ByVal GroupHandle As Long, _
    ByVal DataSoure As Integer) As Long

Declare Function ASDAC_GetNameSpace Lib "DACLTSDK.dll" (ByVal ServerHandle As Long, ByRef NameSpace As Integer) As Long
Declare Function ASDAC_ChangeBrowsePosition Lib "DACLTSDK.dll" (ByVal ServerHandle As Long, ByVal Direct As Integer, _
    ByVal NodeName As String) As Long
Declare Function ASDAC_BrowseItems Lib "DACLTSDK.dll" (ByVal ServerHandle As Long, ByVal FilterType As Integer, _
    ByVal FilterString As String, ByVal FilterDataType As Integer, ByVal FilterAccessRight As Integer, ByRef ItemNames As Variant) As Long
Declare Function ASDAC_GetItemFullName Lib "DACLTSDK.dll" (ByVal ServerHandle As Long, ByVal Name As String, _
    ByVal pFullName As String, ByVal size As Long) As Long
Declare Function ASDAC_GetItemProperties Lib "DACLTSDK.dll" (ByVal ServerHandle As Long, ByVal Name As String, _
    IDList As Variant, DataTypeList As Variant, DescList As Variant) As Long
Declare Function ASDAC_GetItemPropertyValue Lib "DACLTSDK.dll" (ByVal ServerHandle As Long, ByVal Name As String, _
    ByVal PropertyID As Long, Value As Variant) As Long

Declare Function ASDAC_AddItem Lib "DACLTSDK.dll" (ByVal ServerHandle As Long, ByVal GroupHandle As Long, ByVal Name As String) As Long
Declare Function ASDAC_RemoveItem Lib "DACLTSDK.dll" (ByVal ServerHandle As Long, ByVal GroupHandle As Long, ByVal ItemHandle As Long) As Long
Declare Function ASDAC_ActiveItem Lib "DACLTSDK.dll" (ByVal ServerHandle As Long, ByVal GroupHandle As Long, ByVal Active As Long) As Long
Declare Function ASDAC_WriteItem Lib "DACLTSDK.dll" (ByVal ServerHandle As Long, ByVal GroupHandle As Long, _
    ByVal ItemHandle As Long, ByVal Value As Variant, ByVal DoAsync As Long) As Long
Declare Function ASDAC_ReadItem Lib "DACLTSDK.dll" (ByVal ServerHandle As Long, ByVal GroupHandle As Long, _
    ByVal ItemHandle As Long, ByRef Value As Variant, ByRef TimeStamp As Double, ByRef Quality As Integer) As Long
Declare Function ASDAC_ValidateItem Lib "DACLTSDK.dll" (ByVal ServerHandle As Long, ByVal GroupHandle As Long, _
    ByVal Name As String, ByRef DataType As Integer, ByVal AccessRight As Integer) As Long

'// prototype for the callback function is as follows:
'//      void CALLBACK EXPORT DataChangeProc(HANDLE GroupHandle, HANDLE ItemHandle, VARIANT pVar, FILETIME timestamp, WORD quality)
'//  Param:  HANDLE ServerHandle             --  HANDLE of connected opc server
'//          DATACHANGEPROC lpCallback   --  pointer of callback function  in user application
'//  Return: BOOL                        --  TRUE if succeded, FALSE if failed
Declare Function ASDAC_SetDataChangeProc Lib "DACLTSDK.dll" (ByVal ServerHandle As Long, ByVal callback As Long) As Long
'// prototype for the callback function is as follows:
'//      void CALLBACK EXPORT ShutDownProc(HANDLE ServerHandle)
'//  Param:  HANDLE ServerHandle             --  HANDLE of connected opc server
Declare Function ASDAC_SetShutdownProc Lib "DACLTSDK.dll" (ByVal ServerHandle As Long, ByVal callback As Long) As Long




















