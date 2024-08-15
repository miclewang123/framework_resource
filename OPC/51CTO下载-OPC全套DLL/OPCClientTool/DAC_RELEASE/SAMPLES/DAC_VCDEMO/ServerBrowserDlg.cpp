// ServerBrowserDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DAC_VCDEMO.h"
#include "ServerBrowserDlg.h"
#include "DACLTSDK.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ServerBrowserDlg dialog


ServerBrowserDlg::ServerBrowserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ServerBrowserDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ServerBrowserDlg)
	//}}AFX_DATA_INIT
}


void ServerBrowserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ServerBrowserDlg)
	DDX_Control(pDX, IDC_CHECK1, m_Check);
	DDX_Control(pDX, IDC_EDIT3, m_Edit3);
	DDX_Control(pDX, IDC_EDIT2, m_Edit2);
	DDX_Control(pDX, IDC_EDIT1, m_Edit1);
	DDX_Control(pDX, IDC_LIST, m_List);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ServerBrowserDlg, CDialog)
	//{{AFX_MSG_MAP(ServerBrowserDlg)
	ON_BN_CLICKED(IDRefresh, OnRefresh)
	ON_LBN_SELCHANGE(IDC_LIST, OnSelChange)
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ServerBrowserDlg message handlers

void ServerBrowserDlg::OnRefresh() 
{
	VARIANT ServerNames;
	VARIANT ServerClassIDs;
	DWORD dwCount, I;
	m_Edit3.GetWindowText(ComputerName);
	m_List.ResetContent();
	if(m_Check.GetCheck()==0)
	{
		Version=1;
	}
	else
	{
		Version=2;
	}
	VariantInit(&ServerNames);
	VariantInit(&ServerClassIDs);

	dwCount=ASDAC_GetServers(ComputerName, Version, &ServerNames, &ServerClassIDs);
	if(dwCount>0)
	{
		COleSafeArray Names, ClassIDs;
		BSTR *pbName, *pbClassID;

		Names.Attach(ServerNames);
		Names.AccessData((LPVOID*)&pbName);
		ClassIDs.Attach(ServerClassIDs);
		ClassIDs.AccessData((LPVOID*)&pbClassID);
		
		for(I=0;I<dwCount;I++)
		{
			CNM[I]= pbName[I];
			CID[I]= pbClassID[I];
			m_List.AddString(CNM[I]);
		}
		
		Names.Detach();
		ClassIDs.Detach();
	}
}

void ServerBrowserDlg::OnSelChange() 
{
	int nIndex = m_List.GetCurSel();
	if(nIndex!=LB_ERR)
	{
		m_Edit1.SetWindowText(CNM[nIndex]);
		m_Edit2.SetWindowText(CID[nIndex]);
		ServerClassID=CID[nIndex];
		ServerName=CNM[nIndex];
	}
}

void ServerBrowserDlg::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	m_Edit1.SetWindowText(ServerName);
	m_Edit2.SetWindowText(ServerClassID);
	m_Edit3.SetWindowText(ComputerName);
	OnRefresh();
	if(Version=2)
		m_Check.SetCheck(1);
	else
		m_Check.SetCheck(0);
	
}
