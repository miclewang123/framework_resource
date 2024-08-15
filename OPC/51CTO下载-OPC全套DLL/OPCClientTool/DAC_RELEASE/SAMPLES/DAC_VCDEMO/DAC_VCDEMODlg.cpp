// DAC_VCDEMODlg.cpp : implementation file
//

#include "stdafx.h"
#include "DAC_VCDEMO.h"
#include "DAC_VCDEMODlg.h"
#include "DACLTSDK.h"
#include "ServerBrowserDlg.h"
#include "ServerStatusDlg.h"
#include "GroupStatusDlg.h"
#include "ItemBrowserDlg.h"
#include "ItemStatusDlg.h"
#include "ItemActiveDlg.h"
#include "ItemWriteDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


void WINAPI ShutdownProc(DWORD hServer)
{
	CDAC_VCDEMODlg *pWnd;
	pWnd = (CDAC_VCDEMODlg *)AfxGetMainWnd();
	pWnd->ShutDown(hServer);
}

void WINAPI DataChangeProc(DWORD hServer, DWORD hGroup, DWORD hItem, VARIANT pVar, _FILETIME timestamp, WORD quality)
{
	CDAC_VCDEMODlg *pWnd;
	pWnd = (CDAC_VCDEMODlg *)AfxGetMainWnd();
	pWnd->Refresh(hItem, pVar, quality, timestamp);
}

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDAC_VCDEMODlg dialog

CDAC_VCDEMODlg::CDAC_VCDEMODlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDAC_VCDEMODlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDAC_VCDEMODlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDAC_VCDEMODlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDAC_VCDEMODlg)
	DDX_Control(pDX, IDC_LIST, m_List);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDAC_VCDEMODlg, CDialog)
	//{{AFX_MSG_MAP(CDAC_VCDEMODlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_MENUExit, OnMENUExit)
	ON_COMMAND(ID_MENUAbout, OnMENUAbout)
	ON_COMMAND(ID_MENUConnect, OnMENUConnect)
	ON_COMMAND(ID_MENUDisconnect, OnMENUDisconnect)
	ON_COMMAND(ID_MENUGroupRefresh, OnMENUGroupRefresh)
	ON_COMMAND(ID_MENUGroupStatus, OnMENUGroupStatus)
	ON_COMMAND(ID_MENUItemAdd, OnMENUItemAdd)
	ON_COMMAND(ID_MENUItemStatus, OnMENUITEMProperties)
	ON_COMMAND(ID_MENUItemRead, OnMENUITEMRead)
	ON_COMMAND(ID_MENUItemRemove, OnMENUITEMRemove)
	ON_COMMAND(ID_MENUItemWrite, OnMENUITEMWrite)
	ON_COMMAND(ID_MENUServerStatus, OnMENUServerStatus)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST, OnItemchanged)
	ON_COMMAND(ID_MENUItemActive, OnMENUItemActive)
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDAC_VCDEMODlg message handlers

BOOL CDAC_VCDEMODlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	m_List.InsertColumn(0,"Name",LVCFMT_LEFT,200,-1);
	m_List.InsertColumn(1,"Value",LVCFMT_LEFT,120,-1);
	m_List.InsertColumn(2,"Quality",LVCFMT_LEFT,80,-1);
	m_List.InsertColumn(3,"TimeStamp",LVCFMT_LEFT,200,-1);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDAC_VCDEMODlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDAC_VCDEMODlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDAC_VCDEMODlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDAC_VCDEMODlg::OnMENUExit() 
{
	DestroyWindow();
}

void CDAC_VCDEMODlg::OnMENUAbout() 
{
	CAboutDlg About;
	About.DoModal()	;
}

void CDAC_VCDEMODlg::OnMENUConnect() 
{
	int nRet = -1;
	ServerBrowserDlg Browser;
    nRet=Browser.DoModal();
	if(nRet==IDOK)
	{
		if(!ServerClassID.IsEmpty())
		{
			CMenu* mmenu = GetMenu();
			
			mmenu->EnableMenuItem(ID_MENUConnect, MF_GRAYED);
			mmenu->EnableMenuItem(ID_MENUDisconnect, MF_ENABLED);
			mmenu->EnableMenuItem(ID_MENUServerStatus, MF_ENABLED);
			mmenu->EnableMenuItem(ID_MENUGroupStatus, MF_ENABLED);
			mmenu->EnableMenuItem(ID_MENUGroupRefresh, MF_ENABLED);
			mmenu->EnableMenuItem(ID_MENUItemAdd, MF_ENABLED);

			ServerHandle=ASDAC_Connect(ComputerName, ServerClassID, Version);
			if(ServerHandle>0)
			{
				ASDAC_SetDataChangeProc(ServerHandle, DataChangeProc);
				ASDAC_SetShutdownProc(ServerHandle, ShutdownProc);
				GroupHandle = ASDAC_AddGroup(ServerHandle, GroupName, true, 1000, -480, 0, 0);
				if(GroupHandle>0)
				{
				}
			}
		}

	}
}

void CDAC_VCDEMODlg::OnMENUDisconnect() 
{
	if(ServerHandle>0)
	{
		if(ASDAC_Disconnect(ServerHandle))
		{
			ServerHandle=0;
			GroupHandle=0;
			GroupName="GROUP";
			m_List.DeleteAllItems();
			CMenu* mmenu = GetMenu();
			mmenu->EnableMenuItem(ID_MENUConnect, MF_ENABLED);
			mmenu->EnableMenuItem(ID_MENUDisconnect, MF_GRAYED);
			mmenu->EnableMenuItem(ID_MENUServerStatus, MF_GRAYED);
			mmenu->EnableMenuItem(ID_MENUGroupStatus, MF_GRAYED);
			mmenu->EnableMenuItem(ID_MENUGroupRefresh, MF_GRAYED);
			mmenu->EnableMenuItem(ID_MENUItemAdd, MF_GRAYED);
			mmenu->EnableMenuItem(ID_MENUItemRemove, MF_GRAYED);
			mmenu->EnableMenuItem(ID_MENUItemRead, MF_GRAYED);
			mmenu->EnableMenuItem(ID_MENUItemWrite, MF_GRAYED);
			mmenu->EnableMenuItem(ID_MENUItemActive, MF_GRAYED);
			mmenu->EnableMenuItem(ID_MENUItemStatus, MF_GRAYED);
		}
	}
}

void CDAC_VCDEMODlg::OnMENUGroupRefresh() 
{
	if((ServerHandle>0)&&(GroupHandle>0))
	{
		ASDAC_RefreshGroup(ServerHandle, GroupHandle, 1);
	}
	
}

void CDAC_VCDEMODlg::OnMENUGroupStatus() 
{
	int nRet=-1;
	CString OldGroupName=GroupName;
	GroupStatusDlg StatusDlg;
	nRet=StatusDlg.DoModal();
	if(nRet=IDOK)
	{	
		if(!ASDAC_SetGroupName(ServerHandle, GroupHandle, GroupName))
		{
			GroupName=OldGroupName;
		}
		ASDAC_SetGroupStat(ServerHandle, GroupHandle, UpdateRate, Active, TimeBias, DeadBand, 0);
	}	
}

void CDAC_VCDEMODlg::OnMENUItemAdd() 
{
	ItemBrowserDlg Browser;
	Browser.DoModal();
}

void CDAC_VCDEMODlg::OnMENUITEMProperties() 
{
	int nIndex=m_List.GetNextItem(-1, LVNI_FOCUSED);
	if(nIndex>-1)
	{
		ItemName=m_List.GetItemText(nIndex,0);
		ItemStatusDlg Status;
		Status.DoModal();
	}
}

void CDAC_VCDEMODlg::OnMENUITEMRead() 
{
	VARIANT v;
	_FILETIME ft;
	WORD quality;
	int nIndex=m_List.GetNextItem(-1, LVNI_FOCUSED);
	if(nIndex>-1)
	{
		CString strText;
		DWORD data=m_List.GetItemData(nIndex);
		VariantInit(&v);
		if(ASDAC_ReadItem(ServerHandle, GroupHandle, data, &v, &ft, &quality))
		{
			strText.Format(TEXT("%d"),quality);
			m_List.SetItemText(nIndex,1,VariantToString(v));
			m_List.SetItemText(nIndex,2,strText);
			m_List.SetItemText(nIndex,3,FileTimeToString(ft));
		}
	}	
}

void CDAC_VCDEMODlg::OnMENUITEMRemove() 
{
	int nIndex=m_List.GetNextItem(-1, LVNI_FOCUSED);
	if(nIndex>-1)
	{
		DWORD data=m_List.GetItemData(nIndex);
		if(ASDAC_RemoveItem(ServerHandle, GroupHandle, data))
		{
			m_List.DeleteItem(nIndex);
		}
	}
}

void CDAC_VCDEMODlg::OnMENUITEMWrite() 
{
	int nIndex=m_List.GetNextItem(-1, LVNI_FOCUSED);
	if(nIndex>-1)
	{
		DWORD ItemHandle=m_List.GetItemData(nIndex);
		int nRet;
		ItemWriteDlg WriteDlg;
		nRet=WriteDlg.DoModal();
		if(nRet==IDOK)
		{
			VARIANT v;
			VariantInit(&v);
			v.vt=VT_BSTR;
			v.bstrVal=ItemWriteValue.AllocSysString();
			if(ASDAC_WriteItem(ServerHandle, ServerHandle, ItemHandle, v, ASync))
			{
				m_List.SetItemText(nIndex,1,ItemWriteValue);
			}
		}
	}
}

void CDAC_VCDEMODlg::OnMENUServerStatus() 
{
	ServerStatusDlg Status;
	Status.DoModal();
}


int CDAC_VCDEMODlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	CMenu* mmenu = GetMenu();
	mmenu->EnableMenuItem(ID_MENUDisconnect, MF_GRAYED);
	mmenu->EnableMenuItem(ID_MENUServerStatus, MF_GRAYED);
	mmenu->EnableMenuItem(ID_MENUGroupStatus, MF_GRAYED);
	mmenu->EnableMenuItem(ID_MENUGroupRefresh, MF_GRAYED);
	mmenu->EnableMenuItem(ID_MENUItemAdd, MF_GRAYED);
	mmenu->EnableMenuItem(ID_MENUItemRemove, MF_GRAYED);
	mmenu->EnableMenuItem(ID_MENUItemRead, MF_GRAYED);
	mmenu->EnableMenuItem(ID_MENUItemWrite, MF_GRAYED);
	mmenu->EnableMenuItem(ID_MENUItemStatus, MF_GRAYED);
	mmenu->EnableMenuItem(ID_MENUItemActive, MF_GRAYED);
	GroupName="GROUP";

	ASDAC_Init();
	return 0;
}

void CDAC_VCDEMODlg::OnDestroy() 
{
	CDialog::OnDestroy();
	ASDAC_Uninit();	
	
}

void CDAC_VCDEMODlg::AddItem(CString name)
{
	DWORD ItemHandle=ASDAC_AddItem(ServerHandle, GroupHandle, name);
	if(ItemHandle>0)
	{
		int nIndex=m_List.InsertItem(0xFFFF,name);
		if(nIndex>-1)
		{
			m_List.SetItemData(nIndex, ItemHandle);
			m_List.SetItemText(nIndex,1,"Bad");
		}
	}
}


void CDAC_VCDEMODlg::Refresh(DWORD ItemHandle, VARIANT v, WORD quality, _FILETIME ft)
{
	int I;
	for(I=0;I<m_List.GetItemCount();I++)
	{
		if(m_List.GetItemData(I)==ItemHandle)
		{
			CString strText;
			strText.Format(TEXT("%d"),quality);
			m_List.SetItemText(I,1,VariantToString(v));
			m_List.SetItemText(I,2,strText);
			m_List.SetItemText(I,3,FileTimeToString(ft));
		}
	}	
}

void CDAC_VCDEMODlg::ShutDown(DWORD hServer)
{
	OnMENUDisconnect();
}

void CDAC_VCDEMODlg::OnItemchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	int nIndex=m_List.GetNextItem(-1, LVNI_FOCUSED);
	if(nIndex>-1)
	{
		CMenu* mmenu = GetMenu();
		mmenu->EnableMenuItem(ID_MENUItemRead, MF_ENABLED);
		mmenu->EnableMenuItem(ID_MENUItemWrite, MF_ENABLED);
		mmenu->EnableMenuItem(ID_MENUItemStatus, MF_ENABLED);
		mmenu->EnableMenuItem(ID_MENUItemRemove, MF_ENABLED);
		mmenu->EnableMenuItem(ID_MENUItemActive, MF_ENABLED);
	}
	*pResult = 0;
}

void CDAC_VCDEMODlg::OnMENUItemActive() 
{
	int nIndex=m_List.GetNextItem(-1, LVNI_FOCUSED);
	if(nIndex>-1)
	{
		int nRet;
		DWORD ItemHandle=m_List.GetItemData(nIndex);
		ItemActiveDlg ActiveDlg;
		nRet=ActiveDlg.DoModal();
		if(nRet==IDOK)
			ASDAC_ActiveItem(ServerHandle, GroupHandle, ItemHandle, Active);
	}
}
