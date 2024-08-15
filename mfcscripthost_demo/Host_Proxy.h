#if !defined(AFX_HOST_PROXY_H__F6E8B54C_8BF9_49AD_940D_AC6C08B4BC97__INCLUDED_)
#define AFX_HOST_PROXY_H__F6E8B54C_8BF9_49AD_940D_AC6C08B4BC97__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Host_Proxy.h : header file
//
#include "ActiveScriptHost.h"


/////////////////////////////////////////////////////////////////////////////
// CHost_Proxy command target

class CHost_Proxy : public CActiveScriptHost
{
	DECLARE_DYNCREATE(CHost_Proxy)

// Attributes
public:
	CHost_Proxy();
	virtual ~CHost_Proxy();
	virtual HRESULT GetClassID( LPCLSID pclsid );
	DECLARE_OLETYPELIB(CHost_Proxy)

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHost_Proxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHost_Proxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CHost_Proxy)
	afx_msg LPDISPATCH CreateActiveX(LPCTSTR szProgID);
	afx_msg void QuitApp();
	afx_msg void Display(LPCTSTR strMessage);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
public:
// Event maps
	//{{AFX_EVENT(CHost_Proxy)
	void FireOnRun()
		{FireEvent(eventidOnRun,EVENT_PARAM(VTS_NONE));}
	void FireOnAppExit()
		{FireEvent(eventidOnAppExit,EVENT_PARAM(VTS_NONE));}
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

public:
	enum {
	//{{AFX_DISP_ID(CHost_Proxy)
	dispidCreateActiveX = 1L,
	dispidQuitApp = 2L,
	dispidDisplay = 3L,
	eventidOnRun = 1L,
	eventidOnAppExit = 2L,
	//}}AFX_DISP_ID
	};

	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOST_PROXY_H__F6E8B54C_8BF9_49AD_940D_AC6C08B4BC97__INCLUDED_)
