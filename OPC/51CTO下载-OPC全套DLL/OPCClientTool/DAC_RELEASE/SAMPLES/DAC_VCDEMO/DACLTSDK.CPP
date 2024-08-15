#include "stdafx.h"
#include "DACLTSDK.h"

ASDAC_SETDATACHANGEPROC ASDAC_SetDataChangeProc;
ASDAC_SETSHUTDOWNPROC ASDAC_SetShutdownProc;
ASDAC_GETVERSION ASDAC_GetVersion;
ASDAC_INIT ASDAC_Init;
ASDAC_UNINIT ASDAC_Uninit;
ASDAC_ACTIVECODE ASDAC_ActiveCode;
ASDAC_GETSERVERS ASDAC_GetServers;
ASDAC_CONNECT ASDAC_Connect;
ASDAC_DISCONNECT ASDAC_Disconnect;
ASDAC_GETSERVERSTATUS ASDAC_GetServerStatus;

ASDAC_ADDGROUP ASDAC_AddGroup;
ASDAC_REMOVEGROUP ASDAC_RemoveGroup;
ASDAC_SETGROUPNAME ASDAC_SetGroupName;
ASDAC_SETGROUPSTAT ASDAC_SetGroupStat; 
ASDAC_GETGROUPSTAT ASDAC_GetGroupStat; 
ASDAC_REFRESHGROUP ASDAC_RefreshGroup;

ASDAC_ADDITEM ASDAC_AddItem;
ASDAC_REMOVEITEM ASDAC_RemoveItem; 
ASDAC_WRITEITEM ASDAC_WriteItem;
ASDAC_READITEM ASDAC_ReadItem;
ASDAC_ACTIVEITEM ASDAC_ActiveItem;
ASDAC_VALIDATEITEM ASDAC_ValidateItem;

ASDAC_GETNAMESPACE ASDAC_GetNameSpace;
ASDAC_CHANGEBROWSEPOSITION ASDAC_ChangeBrowsePosition;
ASDAC_BROWSEITEMS ASDAC_BrowseItems;
ASDAC_GETITEMFULLNAME ASDAC_GetItemFullName;
ASDAC_GETITEMPROPERTIES ASDAC_GetItemProperties;
ASDAC_GETITEMPROPERTYVALUE ASDAC_GetItemPropertyValue;

BOOL InitOPCDef()
{
	hLibrary=LoadLibrary(TEXT("DACLTSDK.DLL"));
	if(hLibrary)
	{
		ASDAC_SetDataChangeProc=(ASDAC_SETDATACHANGEPROC)GetProcAddress(hLibrary,TEXT("ASDAC_SetDataChangeProc"));
		ASDAC_SetShutdownProc=(ASDAC_SETSHUTDOWNPROC)GetProcAddress(hLibrary,TEXT("ASDAC_SetShutdownProc"));

		ASDAC_GetVersion=(ASDAC_GETVERSION )GetProcAddress(hLibrary,TEXT("ASDAC_GetVersion"));
		ASDAC_Init=(ASDAC_INIT )GetProcAddress(hLibrary,TEXT("ASDAC_Init"));
		ASDAC_Uninit=(ASDAC_UNINIT )GetProcAddress(hLibrary,TEXT("ASDAC_Uninit"));
		ASDAC_ActiveCode=(ASDAC_ACTIVECODE )GetProcAddress(hLibrary,TEXT("ASDAC_ActiveCode"));
		ASDAC_GetServers=(ASDAC_GETSERVERS )GetProcAddress(hLibrary,TEXT("ASDAC_GetServers"));
		ASDAC_Connect=(ASDAC_CONNECT )GetProcAddress(hLibrary,TEXT("ASDAC_Connect"));
		ASDAC_Disconnect=(ASDAC_DISCONNECT )GetProcAddress(hLibrary,TEXT("ASDAC_Disconnect"));
		ASDAC_GetServerStatus=(ASDAC_GETSERVERSTATUS )GetProcAddress(hLibrary,TEXT("ASDAC_GetServerStatus"));

		ASDAC_AddGroup=(ASDAC_ADDGROUP )GetProcAddress(hLibrary,TEXT("ASDAC_AddGroup"));
		ASDAC_RemoveGroup=(ASDAC_REMOVEGROUP )GetProcAddress(hLibrary,TEXT("ASDAC_RemoveGroup"));
		ASDAC_SetGroupName=(ASDAC_SETGROUPNAME )GetProcAddress(hLibrary,TEXT("ASDAC_SetGroupName"));
		ASDAC_SetGroupStat=(ASDAC_SETGROUPSTAT )GetProcAddress(hLibrary,TEXT("ASDAC_SetGroupStat")); 
		ASDAC_GetGroupStat=(ASDAC_GETGROUPSTAT )GetProcAddress(hLibrary,TEXT("ASDAC_GetGroupStat")); 
		ASDAC_RefreshGroup=(ASDAC_REFRESHGROUP )GetProcAddress(hLibrary,TEXT("ASDAC_RefreshGroup")); 
		
		ASDAC_AddItem=(ASDAC_ADDITEM )GetProcAddress(hLibrary,TEXT("ASDAC_AddItem"));
		ASDAC_RemoveItem=(ASDAC_REMOVEITEM )GetProcAddress(hLibrary,TEXT("ASDAC_RemoveItem")); 
		ASDAC_WriteItem=(ASDAC_WRITEITEM )GetProcAddress(hLibrary,TEXT("ASDAC_WriteItem"));
		ASDAC_ReadItem=(ASDAC_READITEM )GetProcAddress(hLibrary,TEXT("ASDAC_ReadItem"));
		ASDAC_ActiveItem=(ASDAC_ACTIVEITEM )GetProcAddress(hLibrary,TEXT("ASDAC_ActiveItem"));
		ASDAC_ValidateItem=(ASDAC_VALIDATEITEM )GetProcAddress(hLibrary,TEXT("ASDAC_ValidateItem"));

		ASDAC_GetNameSpace=(ASDAC_GETNAMESPACE )GetProcAddress(hLibrary,TEXT("ASDAC_GetNameSpace"));
		ASDAC_ChangeBrowsePosition = (ASDAC_CHANGEBROWSEPOSITION)GetProcAddress(hLibrary,TEXT("ASDAC_ChangeBrowsePosition"));
		ASDAC_BrowseItems=(ASDAC_BROWSEITEMS )GetProcAddress(hLibrary,TEXT("ASDAC_BrowseItems"));
		ASDAC_GetItemFullName=(ASDAC_GETITEMFULLNAME )GetProcAddress(hLibrary,TEXT("ASDAC_GetItemFullName"));
		ASDAC_GetItemProperties=(ASDAC_GETITEMPROPERTIES )GetProcAddress(hLibrary,TEXT("ASDAC_GetItemProperties"));
		ASDAC_GetItemPropertyValue=(ASDAC_GETITEMPROPERTYVALUE )GetProcAddress(hLibrary,TEXT("ASDAC_GetItemPropertyValue"));
	
		return true;
	}
	else return false;
}

BOOL FreeOPCDef()
{
	if(hLibrary)
		return FreeLibrary(hLibrary);
	else
		return FALSE;
}
