// Host.cpp : implementation file
//

#include "stdafx.h"
#include "ScriptDemo.h"
#include "Host.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHost

IMPLEMENT_DYNCREATE(CHost, CCmdTarget)

CHost::CHost()
{
}

CHost::~CHost()
{
}


BEGIN_MESSAGE_MAP(CHost, CCmdTarget)
	//{{AFX_MSG_MAP(CHost)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHost message handlers

void CHost::test()
{
	AfxMessageBox(CString(_T("\"")) + GetDispatchMap()->lpEntries->lpszName + _T("\" method call of the \"") + RUNTIME_CLASS(CHost)->m_lpszClassName + _T("\" class"), MB_ICONASTERISK);
}
