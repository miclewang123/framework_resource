// ItemBrowserDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DAC_VCDEMO.h"
#include "ItemBrowserDlg.h"
#include "DAC_VCDEMODlg.h"
#include "DACLTSDK.h"
#include "ItemStatusDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ItemBrowserDlg dialog


ItemBrowserDlg::ItemBrowserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ItemBrowserDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ItemBrowserDlg)
	//}}AFX_DATA_INIT
}


void ItemBrowserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ItemBrowserDlg)
	DDX_Control(pDX, IDC_LIST, m_List);
	DDX_Control(pDX, IDC_EDIT2, m_Edit2);
	DDX_Control(pDX, IDC_EDIT1, m_Edit1);
	DDX_Control(pDX, IDC_TREE1, m_Tree);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ItemBrowserDlg, CDialog)
	//{{AFX_MSG_MAP(ItemBrowserDlg)
	ON_BN_CLICKED(IDRefresh, OnRefresh)
	ON_BN_CLICKED(IDAdd, OnAdd)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, OnSelchanged)
	ON_LBN_SELCHANGE(IDC_LIST, OnSelchange)
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ItemBrowserDlg message handlers

void ItemBrowserDlg::OnRefresh() 
{
	m_Edit1.GetWindowText(ItemName);
	ItemStatusDlg Status;
	Status.DoModal();
}

void ItemBrowserDlg::OnAdd() 
{
	CString name;
	CDAC_VCDEMODlg *pWnd;
	pWnd = (CDAC_VCDEMODlg *)AfxGetMainWnd();

	m_Edit1.GetWindowText(name);
	name.TrimLeft();
	name.TrimRight();
	pWnd->AddItem(name);
}

void ItemBrowserDlg::BrowseItems()
{
	VARIANT ItemNames;
	VariantInit(&ItemNames);
	DWORD I, Count;
	HTREEITEM hItem= m_Tree.GetSelectedItem();
	if(hItem==NULL)return; 
	m_List.ResetContent();

    Count = ASDAC_BrowseItems(ServerHandle, 2, "*", 0, 0, &ItemNames);
    if(Count>0)
	{
		COleSafeArray Names;
		BSTR *pbName;
		Names.Attach(ItemNames);
		Names.AccessData((LPVOID*)&pbName);
	
		for(I=0;I<Count;I++)
		{
			CString name=pbName[I];
			m_List.AddString(name);
		}
		Names.Detach();
    }
	m_Tree.Expand(hItem,TVE_EXPAND);
	
	/*
	char Name[128];
	int Count;
    Count = ASDAC_BrowseItems(ServerHandle, 2);
    for(int i=0; i<Count; i++)
	{
        AS_GetItemName(m_pView->m_hConnect,i,Name,127);
		m_List.AddString(Name);
    }
*/
}

void ItemBrowserDlg::BrowseBranch()
{
	HTREEITEM hItem= m_Tree.GetSelectedItem();
	if(hItem==NULL)return; 
		
    ChangeBrowsePosition(hItem);

    BrowseItems();
	if(!m_Tree.ItemHasChildren(hItem))
	{
		int I, Count;
		VARIANT ItemNames;
		VariantInit(&ItemNames);
        Count = ASDAC_BrowseItems(ServerHandle, 1,"*",0,0,&ItemNames);
        if(Count>0)
		{
			COleSafeArray Names;
			BSTR *pbName;
			Names.Attach(ItemNames);
			Names.AccessData((LPVOID*)&pbName);
		
			for(I=0;I<Count;I++)
			{
				CString name=pbName[I];
				m_Tree.InsertItem(name,hItem,NULL);
			}
			Names.Detach();
        }
		m_Tree.Expand(hItem,TVE_EXPAND);
    }
}

void ItemBrowserDlg::ChangeBrowsePosition(HTREEITEM hItem)
{
	HTREEITEM root;
	root=m_Tree.GetRootItem();
	CString name;
	if(hItem==root)
	{
		ASDAC_ChangeBrowsePosition(ServerHandle,1, "");
	}
	else
	{
		ChangeBrowsePosition(m_Tree.GetParentItem(hItem));
		name=m_Tree.GetItemText(hItem);
		ASDAC_ChangeBrowsePosition(ServerHandle,2, name);
	}
}

void ItemBrowserDlg::OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	BrowseBranch();
	*pResult = 0;
}

void ItemBrowserDlg::OnSelchange() 
{
	int nIndex = m_List.GetCurSel();
	if(nIndex!=LB_ERR)
	{
		CString name;
		char buf[128];
		m_List.GetText(nIndex, name);
		if(ASDAC_GetItemFullName(ServerHandle, name, buf, 128))
		{
			m_Edit1.SetWindowText(buf);
		}
	}
}


void ItemBrowserDlg::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	HTREEITEM Item=m_Tree.InsertItem("ROOT");
	m_Tree.SetItemState(Item, TVIS_SELECTED ,TVIS_STATEIMAGEMASK);
	BrowseBranch();
	
}
