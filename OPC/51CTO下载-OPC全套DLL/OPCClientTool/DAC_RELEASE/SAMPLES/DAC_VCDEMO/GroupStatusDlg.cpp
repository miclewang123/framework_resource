// GroupStatusDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DAC_VCDEMO.h"
#include "GroupStatusDlg.h"
#include "DACLTSDK.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// GroupStatusDlg dialog


GroupStatusDlg::GroupStatusDlg(CWnd* pParent /*=NULL*/)
	: CDialog(GroupStatusDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(GroupStatusDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void GroupStatusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(GroupStatusDlg)
	DDX_Control(pDX, IDC_EDIT4, m_Edit4);
	DDX_Control(pDX, IDC_EDIT3, m_Edit3);
	DDX_Control(pDX, IDC_EDIT2, m_Edit2);
	DDX_Control(pDX, IDC_EDIT1, m_Edit1);
	DDX_Control(pDX, IDC_CHECK, m_Check);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(GroupStatusDlg, CDialog)
	//{{AFX_MSG_MAP(GroupStatusDlg)
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// GroupStatusDlg message handlers

void GroupStatusDlg::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	Refresh();
	
}

void GroupStatusDlg::Refresh()
{
	DWORD UpdateRate, TimeBias, LCID;
	BOOL Active;
	float DeadBand;
	if(ASDAC_GetGroupStat(ServerHandle, GroupHandle, &UpdateRate, &Active, &TimeBias, &DeadBand, &LCID))
	{
		CString strText;
		strText.Format(TEXT("%f"),DeadBand);
		m_Edit1.SetWindowText(GroupName);
		m_Edit2.SetWindowText(IntToString(UpdateRate));
		m_Edit3.SetWindowText(strText);
		m_Edit4.SetWindowText(IntToString(TimeBias));
		if(Active)
			m_Check.SetCheck(1);
		else
			m_Check.SetCheck(0);
	}	
}

void GroupStatusDlg::OnOK() 
{
	CString strText;
	m_Edit1.GetWindowText(GroupName);	
	m_Edit2.GetWindowText(strText);
	TimeBias=atoi(strText);
	m_Edit3.GetWindowText(strText);
	UpdateRate=atoi(strText);
	m_Edit4.GetWindowText(strText);
	DeadBand= float(atof(strText));
	if(m_Check.GetCheck()==0)
		Active=false;
	else
		Active=true;
	CDialog::OnOK();
}
