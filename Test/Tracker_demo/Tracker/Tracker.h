// Tracker.h : main header file for the TRACKER application
//

#if !defined(AFX_TRACKER_H__C1BAFF34_1638_4431_B128_32B43FC48FA2__INCLUDED_)
#define AFX_TRACKER_H__C1BAFF34_1638_4431_B128_32B43FC48FA2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTrackerApp:
// See Tracker.cpp for the implementation of this class
//

class CTrackerApp : public CWinApp
{
public:
	CTrackerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrackerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTrackerApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRACKER_H__C1BAFF34_1638_4431_B128_32B43FC48FA2__INCLUDED_)
