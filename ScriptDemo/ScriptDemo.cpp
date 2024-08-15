// ScriptDemo.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ScriptDemo.h"
#include "ScriptDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScriptDemoApp

BEGIN_MESSAGE_MAP(CScriptDemoApp, CWinApp)
	//{{AFX_MSG_MAP(CScriptDemoApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScriptDemoApp construction

CScriptDemoApp::CScriptDemoApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CScriptDemoApp object

CScriptDemoApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CScriptDemoApp initialization

BOOL CScriptDemoApp::InitInstance()
{
	// Initialize COM
	CoInitialize(NULL);

	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	try {
		CScriptDemoDlg dlg;
		m_pMainWnd = &dlg;
		int nResponse = dlg.DoModal();
		if (nResponse == IDOK)
		{
			// TODO: Place code here to handle when the dialog is
			//  dismissed with OK
		}
		else if (nResponse == IDCANCEL)
		{
			// TODO: Place code here to handle when the dialog is
			//  dismissed with Cancel
		}
	}
	catch(_com_error& e)
	{
		CString strMsg = _T("Apparently you don't have script object installed\nDownload it here at:www.microsoft.com/scripting/");
		AfxMessageBox( strMsg, MB_OK);
		TRACE1("Error: %s\n", (LPSTR) e.ErrorMessage());
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

int CScriptDemoApp::ExitInstance() 
{
	//CoUninitialize();
	
	return CWinApp::ExitInstance();
}

void CScriptDemoApp::test()
{
	AfxGetMainWnd()->MessageBox("test");
//	AfxMessageBox("test","test",MB_OK);
}
