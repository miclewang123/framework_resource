// ScriptDemo.h : main header file for the SCRIPTDEMO application
//

#if !defined(AFX_SCRIPTDEMO_H__ED20D0A6_8DDF_11D6_917A_000086436E72__INCLUDED_)
#define AFX_SCRIPTDEMO_H__ED20D0A6_8DDF_11D6_917A_000086436E72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CScriptDemoApp:
// See ScriptDemo.cpp for the implementation of this class
//

class CScriptDemoApp : public CWinApp
{
public:
	void test();
	CScriptDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScriptDemoApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CScriptDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CScriptDemoApp theApp;

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCRIPTDEMO_H__ED20D0A6_8DDF_11D6_917A_000086436E72__INCLUDED_)
