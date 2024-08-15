// ItemWriteDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DAC_VCDEMO.h"
#include "ItemWriteDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ItemWriteDlg dialog


ItemWriteDlg::ItemWriteDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ItemWriteDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ItemWriteDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void ItemWriteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ItemWriteDlg)
	DDX_Control(pDX, IDC_CHECK, m_Check);
	DDX_Control(pDX, IDC_EDIT1, m_Edit1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ItemWriteDlg, CDialog)
	//{{AFX_MSG_MAP(ItemWriteDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ItemWriteDlg message handlers

void ItemWriteDlg::OnOK() 
{
	m_Edit1.GetWindowText(ItemWriteValue);
	CDialog::OnOK();
}
