// DAC_VCDEMO.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "DAC_VCDEMO.h"
#include "DAC_VCDEMODlg.h"
#include "DACLTSDK.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDAC_VCDEMOApp

BEGIN_MESSAGE_MAP(CDAC_VCDEMOApp, CWinApp)
	//{{AFX_MSG_MAP(CDAC_VCDEMOApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDAC_VCDEMOApp construction

CDAC_VCDEMOApp::CDAC_VCDEMOApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CDAC_VCDEMOApp object

CDAC_VCDEMOApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CDAC_VCDEMOApp initialization

BOOL CDAC_VCDEMOApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
	if(!InitOPCDef())
	{
		return false;
	}
	
	CDAC_VCDEMODlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();
	return false;
}

int CDAC_VCDEMOApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	FreeOPCDef();
	return CWinApp::ExitInstance();
}
