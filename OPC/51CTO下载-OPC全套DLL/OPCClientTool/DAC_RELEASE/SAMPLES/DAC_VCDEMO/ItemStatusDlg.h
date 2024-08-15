#if !defined(AFX_ITEMSTATUSDLG_H__1307B4BA_0796_46C7_9F54_7A5962A66FCD__INCLUDED_)
#define AFX_ITEMSTATUSDLG_H__1307B4BA_0796_46C7_9F54_7A5962A66FCD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ItemStatusDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ItemStatusDlg dialog

class ItemStatusDlg : public CDialog
{
// Construction
public:
	ItemStatusDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ItemStatusDlg)
	enum { IDD = IDD_ItemStatus };
	CListCtrl	m_List;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ItemStatusDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ItemStatusDlg)
	afx_msg void OnRefresh();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ITEMSTATUSDLG_H__1307B4BA_0796_46C7_9F54_7A5962A66FCD__INCLUDED_)
