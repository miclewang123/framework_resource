#if !defined(AFX_ITEMBROWSERDLG_H__8C8F3F63_D6FD_4B72_9CB2_F98AEE4A9571__INCLUDED_)
#define AFX_ITEMBROWSERDLG_H__8C8F3F63_D6FD_4B72_9CB2_F98AEE4A9571__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ItemBrowserDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ItemBrowserDlg dialog

class ItemBrowserDlg : public CDialog
{
// Construction
public:
	void ChangeBrowsePosition(HTREEITEM hItem);
	void BrowseBranch();
	void BrowseItems();
	ItemBrowserDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ItemBrowserDlg)
	enum { IDD = IDD_ItemBrowser };
	CListBox	m_List;
	CEdit	m_Edit2;
	CEdit	m_Edit1;
	CTreeCtrl	m_Tree;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ItemBrowserDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ItemBrowserDlg)
	afx_msg void OnRefresh();
	afx_msg void OnAdd();
	afx_msg void OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchange();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ITEMBROWSERDLG_H__8C8F3F63_D6FD_4B72_9CB2_F98AEE4A9571__INCLUDED_)
