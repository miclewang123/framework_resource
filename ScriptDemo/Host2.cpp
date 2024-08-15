// Host2.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "Host2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHost2

IMPLEMENT_DYNCREATE(CHost2, CCmdTarget)

CHost2::CHost2()
{
	EnableAutomation();
}

BEGIN_MESSAGE_MAP(CHost2, CCmdTarget)
	//{{AFX_MSG_MAP(CHost2)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CHost2, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CHost2)
	DISP_FUNCTION(CHost2, "Test", Test, VT_I4, VTS_BSTR)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()


BEGIN_INTERFACE_MAP(CHost2, CCmdTarget)
	INTERFACE_PART(CHost2, IID_IHost2, Dispatch)
END_INTERFACE_MAP()


long CHost2::Test(LPCTSTR strCmd) 
{
	// TODO: Add your dispatch handler code here
	if(strcmp(strCmd,"Show")==0)
	{
		AfxGetMainWnd()->GetDlgItem(IDC_SWITCH)->ShowWindow(SW_SHOW);
		return 1;
	}
	else if(strcmp(strCmd,"Hide")==0)
	{
		AfxGetMainWnd()->GetDlgItem(IDC_SWITCH)->ShowWindow(SW_HIDE);
		return 2;
	}
	else
	{
		AfxGetMainWnd()->MessageBox("不能识别的命令！只支持\"Show\"和\"Hide\"!","提示");
		return 0;
	}
}
