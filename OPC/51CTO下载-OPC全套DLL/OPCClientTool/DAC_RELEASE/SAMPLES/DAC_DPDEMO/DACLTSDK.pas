unit DACLTSDK;

interface

uses Windows, Classes, ActiveX, SysUtils;

const SDK='DACLTSDK.DLL';

type
  OPCBROWSETYPE = TOleEnum;
const
  OPC_BRANCH = 1;
  OPC_LEAF   = 2;
  OPC_FLAT   = 3;

type
  OPCNAMESPACETYPE = TOleEnum;
const
  OPC_NS_HIERARCHIAL = 1;
  OPC_NS_FLAT        = 2;

type
  OPCBROWSEDIRECTION = TOleEnum;
const
  OPC_BROWSE_UP   = 1;
  OPC_BROWSE_DOWN = 2;
  OPC_BROWSE_TO   = 3;

type
  OPCSERVERSTATE = TOleEnum;
const
  OPC_STATUS_RUNNING   = 1;
  OPC_STATUS_FAILED    = 2;
  OPC_STATUS_NOCONFIG  = 3;
  OPC_STATUS_SUSPENDED = 4;
  OPC_STATUS_TEST      = 5;

type
  TDATACHANGEPROC=procedure(ServerHandle,GroupHandle,ItemHandle:DWORD; pVar:Variant; timestamp:TFILETIME; quality:WORD); stdcall;
  TSHUTDOWNPROC=procedure(ServerHandle: DWORD); stdcall;

  OPCSERVERSTATUS = record
    ftStartTime:          TFileTime;
    ftCurrentTime:        TFileTime;
    ftLastUpdateTime:     TFileTime;
    dwServerState:        OPCSERVERSTATE;
    dwGroupCount:         DWORD;
    dwBandWidth:          DWORD;
    wMajorVersion:        Word;
    wMinorVersion:        Word;
    wBuildNumber:         Word;
    wReserved:            Word;
    szVendorInfo:         POleStr;
  end;
  POPCSERVERSTATUS = ^OPCSERVERSTATUS;
  //base info
  function  ASDAC_GetVersion: DWORD;stdcall; external SDK;
  //init or uninit package
  function ASDAC_Init: BOOL; stdcall; external SDK;
  function ASDAC_Uninit: BOOL; stdcall; external SDK;
  function ASDAC_ActiveCode(UserName: LPCSTR; Password: LPCSTR): BOOL; stdcall; external SDK;
  function ASDAC_GetServers(ComputerName: LPCSTR; Version: DWORD; ServerNames, ServerClassIDs: PVariant): Integer; stdcall; external SDK;
  //server manager
  function ASDAC_Connect(ComputerName,ClassID: LPCSTR; Version: DWORD): DWORD; stdcall; external SDK;
  function ASDAC_Disconnect(ServerHandle: DWORD): BOOL; stdcall; external SDK;
  function ASDAC_GetServerStatus(ServerHandle: DWORD; StartTime, CurrentTime, UpdateTime: PFileTIme;
    State: PWORD; BandWidth, GroupCount: PDWORD; MajorVersion, MinorVersion, BuildNum: PWORD;
    vendor: PChar; Size: DWORD): BOOL; stdcall; external SDK;
  function ASDAC_AddGroup(ServerHandle: DWORD; Name:LPCSTR; Active:BOOL; Rate:DWORD; TimeBias: DWORD; DeadBand: Single; dwLCID:DWORD): DWORD; stdcall; external SDK;
  function ASDAC_RemoveGroup(ServerHandle, GroupHandle: DWORD): BOOL;stdcall; external SDK;
  function ASDAC_SetGroupName(ServerHandle, GroupHandle: DWORD; Name: LPCSTR): BOOL;stdcall; external SDK;
  function ASDAC_SetGroupStat(ServerHandle, GroupHandle: DWORD; Rate: DWORD; Active: BOOL; TimeBias: LongInt; DeadBand:Single; dwLCID:DWORD): BOOL; stdcall; external SDK;
  function ASDAC_GetGroupStat(ServerHandle,GroupHandle: DWORD;  pRate: PDWORD; pActive:PBOOL; pTimeBias: PLONGINT; pDeadBand: PSingle; dwLCID:PDWORD):BOOL;stdcall; external SDK;
  function ASDAC_RefreshGroup(ServerHandle,GroupHandle: DWORD; DataSource: WORD): BOOL;stdcall; external SDK;
  //item manager
  function ASDAC_AddItem(ServerHandle,GroupHandle: DWORD; ItemName:LPCSTR): DWORD;stdcall; external SDK;
  function ASDAC_RemoveItem(ServerHandle,GroupHandle, ItemHandle: DWORD): BOOL; stdcall; external SDK;
  function ASDAC_WriteItem(ServerHandle, GroupHandle,ItemHandle: DWORD; Value: VARIANT; DoAsync: BOOL): BOOL;stdcall; external SDK;
  function ASDAC_ReadItem(ServerHandle,GroupHandle,ItemHandle: DWORD; pVar: PVARIANT; pTimeStamp: PFILETIME; pQuality:PDWORD): BOOL; stdcall; external SDK;
  function ASDAC_ActiveItem(ServerHandle,GroupHandle,ItemHandle: DWORD; Active:BOOL): BOOL;stdcall; external SDK;
  function ASDAC_ValidateItem(ServerHandle,GroupHandle: DWORD; Name: LPCSTR; DataType: WORD; pAccessRights: DWORD): BOOL;stdcall; external SDK;
  //address space browser
  function ASDAC_GetNameSpace(ServerHandle: DWORD; pNameSpace: PWORD):BOOL;stdcall; external SDK;
  function ASDAC_ChangeBrowsePosition(ServerHandle: THANDLE; Direction: WORD; NodeName: PChar): BOOL; stdcall; external SDK;
  function ASDAC_BrowseItems(ServerHandle: DWORD; FilterType: WORD; FilterString: LPCSTR; FilterDataType: TVARTYPE; FilterAccessRights:DWORD; ItemNames: PVariant):Integer;stdcall; external SDK;
  function ASDAC_GetItemFullName(ServerHandle:DWORD; ItemName: LPCSTR; pQualifiedName: LPCSTR; Size: Integer): BOOL; stdcall; external SDK;
  function ASDAC_GetItemProperties(ServerHandle:DWORD; ItemName: LPCSTR; IDList, DataTypeList, DescList: PVariant): Integer; stdcall; external SDK;
  function ASDAC_GetItemPropertyValue(ServerHandle: DWORD; ItemName: LPCSTR; ID: DWORD; pValue: PVARIANT): BOOL; stdcall; external SDK;
  // set callback procedure
  function ASDAC_SetDataChangeProc(ServerHandle: DWORD; lpCallback: TDATACHANGEPROC): BOOL; stdcall; external SDK;
  function ASDAC_SetShutdownProc(ServerHandle: DWORD; lpCallback: TSHUTDOWNPROC): BOOL; stdcall; external SDK;

implementation

end.
