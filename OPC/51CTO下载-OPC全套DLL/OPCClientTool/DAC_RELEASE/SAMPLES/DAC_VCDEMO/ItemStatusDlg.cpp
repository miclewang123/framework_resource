// ItemStatusDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DAC_VCDEMO.h"
#include "ItemStatusDlg.h"
#include "DACLTSDK.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ItemStatusDlg dialog


ItemStatusDlg::ItemStatusDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ItemStatusDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ItemStatusDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void ItemStatusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ItemStatusDlg)
	DDX_Control(pDX, IDC_LIST, m_List);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ItemStatusDlg, CDialog)
	//{{AFX_MSG_MAP(ItemStatusDlg)
	ON_BN_CLICKED(IDRefresh, OnRefresh)
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ItemStatusDlg message handlers

void ItemStatusDlg::OnRefresh() 
{
	int Count,I;
	VARIANT IDList, DatatypeList, DescList;

	m_List.DeleteAllItems();

	VariantInit(&IDList);
	VariantInit(&DatatypeList);
	VariantInit(&DescList);

	Count=ASDAC_GetItemProperties(ServerHandle, ItemName, &IDList, &DatatypeList, &DescList);
	if(Count>0)
	{
		COleSafeArray ID, DESC;
		BSTR *pbDesc;
		DWORD *pbID;

		ID.Attach(IDList);
		ID.AccessData((LPVOID*)&pbID);
		DESC.Attach(DescList);
		DESC.AccessData((LPVOID*)&pbDesc);
		
		for(I=0;I<Count;I++)
		{
			VARIANT v;
			VariantInit(&v);
			if(ASDAC_GetItemPropertyValue(ServerHandle, ItemName, pbID[I], &v))
			{
				CString strText=pbDesc[I];
				int nIndex=m_List.InsertItem(0xFFFF, strText);
				if(nIndex>-1)
				{
					m_List.SetItemText(nIndex,1,VariantToString(v));
				}
			}
		}
		ID.Detach();
		DESC.Detach();
	}
}

void ItemStatusDlg::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	m_List.InsertColumn(0,"Name",LVCFMT_LEFT,200,-1);
	m_List.InsertColumn(1,"Value",LVCFMT_LEFT,120,-1);
	OnRefresh();
	
}
