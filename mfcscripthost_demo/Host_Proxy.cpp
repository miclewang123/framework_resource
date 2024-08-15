// Host_Proxy.cpp : implementation file
//

#include "stdafx.h"
#include "MFCScriptHost.h"
#include "Host_Proxy.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// Note: we add support for IID_IHost_Proxy to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {BC810D88-1564-46CF-960A-6BD3653E91D7}
static const GUID CLSID_Host_Proxy = 
{ 0xBC810D88, 0x1564, 0x46CF, { 0x96, 0x0A, 0x6B, 0xD3, 0x65, 0x3E, 0x91, 0xD7 } };

// {F8235A29-C576-439D-A070-6E7980C9C3F6}
static const IID IID_IHost_Proxy =
{ 0xF8235A29, 0xC576, 0x439D, { 0xA0, 0x70, 0x6E, 0x79, 0x80, 0xC9, 0xC3, 0xF6 } };

// {740C1C2D-692F-43F8-85FF-38DEE1742819}
static const IID IID_IHostEvent =
{ 0x740c1c2d, 0x692f, 0x43f8, { 0x85, 0xff, 0x38, 0xde, 0xe1, 0x74, 0x28, 0x19 } };

// {E662E9C0-01DB-4A0C-9AF9-06F8FFB7ACBE}
static const GUID _tlid = 
{ 0xE662E9C0, 0x01DB, 0x4A0C, { 0x9A, 0xF9, 0x06, 0xF8, 0xFF, 0xB7, 0xAC, 0xBE } };

const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;


/////////////////////////////////////////////////////////////////////////////
// CHost_Proxy

IMPLEMENT_DYNCREATE(CHost_Proxy, CActiveScriptHost)

CHost_Proxy::CHost_Proxy()
{
	InitializeIIDs(&IID_IHost_Proxy, &IID_IHostEvent);
	m_bInitialized = TRUE;
}

CHost_Proxy::~CHost_Proxy()
{
}

HRESULT CHost_Proxy::GetClassID( LPCLSID pclsid )
{
	*pclsid = CLSID_Host_Proxy;
	return S_OK;
}

void CHost_Proxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CActiveScriptHost::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CHost_Proxy, CActiveScriptHost)
	//{{AFX_MSG_MAP(CHost_Proxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CHost_Proxy, CActiveScriptHost)
	//{{AFX_DISPATCH_MAP(CHost_Proxy)
	DISP_FUNCTION(CHost_Proxy, "CreateActiveX", CreateActiveX, VT_DISPATCH, VTS_BSTR)
	DISP_FUNCTION(CHost_Proxy, "QuitApp", QuitApp, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CHost_Proxy, "Display", Display, VT_EMPTY, VTS_BSTR)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CHost_Proxy, _tlid, _wVerMajor, _wVerMinor)

BEGIN_INTERFACE_MAP(CHost_Proxy, CActiveScriptHost)
	INTERFACE_PART(CHost_Proxy, IID_IHost_Proxy, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CHost_Proxy, CActiveScriptHost)
	//{{AFX_EVENT_MAP(CHost_Proxy)
	EVENT_CUSTOM("OnRun", FireOnRun, VTS_NONE)
	EVENT_CUSTOM("OnAppExit", FireOnAppExit, VTS_NONE)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHost_Proxy message handlers

LPDISPATCH CHost_Proxy::CreateActiveX(LPCTSTR szProgID) 
{
	CString strProgID = szProgID;
	BSTR bstrProgID = strProgID.AllocSysString();
	LPDISPATCH pxObject = CreateObjectHelper( bstrProgID );
	SysFreeString(bstrProgID);
	return pxObject;
}

void CHost_Proxy::QuitApp()
{
	FireOnAppExit();

	PostQuitMessage( 0L );
}

void CHost_Proxy::Display(LPCTSTR strMessage) 
{
	AfxMessageBox( strMessage, MB_OK);
}
