// ServerStatusDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DAC_VCDEMO.h"
#include "ServerStatusDlg.h"
#include "DACLTSDK.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ServerStatusDlg dialog


ServerStatusDlg::ServerStatusDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ServerStatusDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ServerStatusDlg)
	//}}AFX_DATA_INIT
}


void ServerStatusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ServerStatusDlg)
	DDX_Control(pDX, IDC_EDIT9, m_Edit9);
	DDX_Control(pDX, IDC_EDIT8, m_Edit8);
	DDX_Control(pDX, IDC_EDIT7, m_Edit7);
	DDX_Control(pDX, IDC_EDIT6, m_Edit6);
	DDX_Control(pDX, IDC_EDIT5, m_Edit5);
	DDX_Control(pDX, IDC_EDIT4, m_Edit4);
	DDX_Control(pDX, IDC_EDIT3, m_Edit3);
	DDX_Control(pDX, IDC_EDIT2, m_Edit2);
	DDX_Control(pDX, IDC_EDIT1, m_Edit1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ServerStatusDlg, CDialog)
	//{{AFX_MSG_MAP(ServerStatusDlg)
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ServerStatusDlg message handlers

void ServerStatusDlg::Refresh()
{
	_FILETIME StartTime,CurrentTime,LastUpdateTime;
	WORD State, MajorVersion, MinorVersion, BuildNum;
	DWORD BandWidth, GroupCount;
	char Vendor[128];
	if(ASDAC_GetServerStatus(ServerHandle, &StartTime,&CurrentTime,&LastUpdateTime,&State,&BandWidth, &GroupCount, &MajorVersion, &MinorVersion, &BuildNum, Vendor, 128))
	{
		m_Edit1.SetWindowText(FileTimeToString(StartTime));
		m_Edit2.SetWindowText(FileTimeToString(CurrentTime));
		m_Edit3.SetWindowText(FileTimeToString(LastUpdateTime));
		m_Edit4.SetWindowText(IntToString(BandWidth));
		m_Edit5.SetWindowText(IntToString(State));
		m_Edit6.SetWindowText(IntToString(GroupCount));
		m_Edit7.SetWindowText(IntToString(MajorVersion));
		m_Edit8.SetWindowText(IntToString(MinorVersion));
		m_Edit9.SetWindowText(IntToString(BuildNum));
	}
}

void ServerStatusDlg::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	Refresh();
	
}
