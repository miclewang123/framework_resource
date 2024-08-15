// MFCScriptHost.h : main header file for the MFCSCRIPTHOST application
//

#if !defined(AFX_MFCSCRIPTHOST_H__8EEED16C_92F9_49EB_A5DF_FEFBD4A72639__INCLUDED_)
#define AFX_MFCSCRIPTHOST_H__8EEED16C_92F9_49EB_A5DF_FEFBD4A72639__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCScriptHostApp:
// See MFCScriptHost.cpp for the implementation of this class
//

class CMFCScriptHostApp : public CWinApp
{
public:
	CMFCScriptHostApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCScriptHostApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFCScriptHostApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCSCRIPTHOST_H__8EEED16C_92F9_49EB_A5DF_FEFBD4A72639__INCLUDED_)
