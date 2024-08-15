// DAC_VCDEMO.h : main header file for the DAC_VCDEMO application
//

#if !defined(AFX_DAC_VCDEMO_H__BAE2330F_2E0D_4756_A448_CAD27B34E39B__INCLUDED_)
#define AFX_DAC_VCDEMO_H__BAE2330F_2E0D_4756_A448_CAD27B34E39B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDAC_VCDEMOApp:
// See DAC_VCDEMO.cpp for the implementation of this class
//

class CDAC_VCDEMOApp : public CWinApp
{
public:
	CDAC_VCDEMOApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDAC_VCDEMOApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDAC_VCDEMOApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAC_VCDEMO_H__BAE2330F_2E0D_4756_A448_CAD27B34E39B__INCLUDED_)
