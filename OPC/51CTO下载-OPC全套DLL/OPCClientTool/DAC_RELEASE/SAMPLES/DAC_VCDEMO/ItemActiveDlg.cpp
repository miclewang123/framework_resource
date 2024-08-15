// ItemActiveDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DAC_VCDEMO.h"
#include "ItemActiveDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ItemActiveDlg dialog


ItemActiveDlg::ItemActiveDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ItemActiveDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ItemActiveDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void ItemActiveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ItemActiveDlg)
	DDX_Control(pDX, IDC_CHECK, m_Check);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ItemActiveDlg, CDialog)
	//{{AFX_MSG_MAP(ItemActiveDlg)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_CHECK, OnCheck)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ItemActiveDlg message handlers

void ItemActiveDlg::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	if(Active)
		m_Check.SetCheck(1);
	else
		m_Check.SetCheck(0);
}

void ItemActiveDlg::OnCheck() 
{
	if(m_Check.GetCheck()==0)
		Active=false;
	else
		Active=true;
	
}
