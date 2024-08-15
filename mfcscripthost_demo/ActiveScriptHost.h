/************************************************************
* FILENAME : ActiveScriptHost.h
* INITIAL CODING : Ernest Laurentin (EL)
*************************************************************/

#ifndef ACTIVESCRIPT_HOST
#define ACTIVESCRIPT_HOST
#include <afxctl.h>
#include <dispex.h>
#include <activscp.h>

#define LANG_ENGLISH_NEUTRAL	(MAKELANGID(LANG_ENGLISH, SUBLANG_NEUTRAL))
#define LOCALE_SCRIPT_DEFAULT	(MAKELCID(LANG_ENGLISH_NEUTRAL, SORT_DEFAULT))

#define ACTIVS_HOST		L"ScriptHost"
#define SCRIPTITEM_NAMEDITEM		(SCRIPTITEM_ISSOURCE | \
									 SCRIPTITEM_ISVISIBLE | \
									 SCRIPTITEM_GLOBALMEMBERS)

class CActiveScriptHost : public COleControl
{
	DECLARE_DYNAMIC(CActiveScriptHost)

public:
// Constructors
	CActiveScriptHost();
	virtual ~CActiveScriptHost();

// Operations
	BOOL SetHostWindow(HWND hWnd);
	BOOL CreateEngine(LPCOLESTR pstrProgID);
	BOOL AddScriptItem(LPCOLESTR pstrNamedItem, LPUNKNOWN lpUnknown, DWORD dwFlags = SCRIPTITEM_NAMEDITEM);
	BOOL AddScriptCode(LPCOLESTR pstrScriptCode);
	BOOL AddScriptlet(LPCOLESTR pstrDefaultName, LPCOLESTR pstrCode,
						LPCOLESTR pstrItemName, LPCOLESTR pstrEventName);
	// Helper functions
	LPDISPATCH CreateObjectHelper(LPCOLESTR bstrProgID);
	WCHAR*	ReadTextFileHelper(LPCOLESTR strFileName);
	void	DestroyDataHelper(LPVOID lpvData);
	HRESULT InvokeFuncHelper(LPCOLESTR lpszName, VARIANT* pvarParams, int nParams, VARIANT* pvarRet = NULL);

protected:
	void CommonConstruct();
	void ReleaseObjects();
	CMapStringToPtr		mapNamedItems;	// Named items
	IActiveScriptParse* m_pAxsParse;	// Active Script parse object
	IActiveScript*		m_pAxsScript;	// Active Script
	HWND				m_hHostWnd;		// Host Window

// Interface Maps
public:
	DECLARE_OLECTLTYPE(CActiveScriptHost)		// Type name and misc status
	DECLARE_INTERFACE_MAP()

	BEGIN_INTERFACE_PART(ActiveScriptSite, IActiveScriptSite)
		STDMETHOD(GetLCID)(LCID*);
		STDMETHOD(GetItemInfo)(LPCOLESTR, DWORD, LPUNKNOWN*, LPTYPEINFO*);
        STDMETHOD(GetDocVersionString)(BSTR*);
        STDMETHOD(OnScriptTerminate)(const VARIANT*, const EXCEPINFO*);
        STDMETHOD(OnStateChange)(SCRIPTSTATE);
        STDMETHOD(OnScriptError)(IActiveScriptError*);
        STDMETHOD(OnEnterScript)();
        STDMETHOD(OnLeaveScript)();
	END_INTERFACE_PART(ActiveScriptSite)

	BEGIN_INTERFACE_PART(ActiveScriptSiteWindow, IActiveScriptSiteWindow)
		STDMETHOD(EnableModeless)(BOOL);
		STDMETHOD(GetWindow)(HWND*);
	END_INTERFACE_PART(ActiveScriptSiteWindow)

	// IProvideMultipleClassInfo
	BEGIN_INTERFACE_PART_DERIVE(ProvideMultipleClassInfo, IProvideMultipleClassInfo)
		INIT_INTERFACE_PART(COleControl, ProvideMultipleClassInfo)
		STDMETHOD(GetClassInfo)(LPTYPEINFO* ppTypeInfo);
		STDMETHOD(GetGUID)(DWORD dwGuidKind, GUID* pGUID);
		STDMETHOD(GetMultiTypeInfoCount)(ULONG*);
		STDMETHOD(GetInfoOfIndex)(ULONG, DWORD, ITypeInfo **, DWORD*, ULONG*, IID*, IID*);
	END_INTERFACE_PART_STATIC(ProvideMultipleClassInfo)

	DECLARE_DISPATCH_MAP()
};

#endif // ACTIVESCRIPT_HOST
