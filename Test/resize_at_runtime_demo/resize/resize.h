// resize.h : main header file for the RESIZE application
//

#if !defined(AFX_RESIZE_H__D86683C5_A897_11D4_B093_005004FEF14D__INCLUDED_)
#define AFX_RESIZE_H__D86683C5_A897_11D4_B093_005004FEF14D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CResizeApp:
// See resize.cpp for the implementation of this class
//

class CResizeApp : public CWinApp
{
public:
	CResizeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CResizeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CResizeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESIZE_H__D86683C5_A897_11D4_B093_005004FEF14D__INCLUDED_)
