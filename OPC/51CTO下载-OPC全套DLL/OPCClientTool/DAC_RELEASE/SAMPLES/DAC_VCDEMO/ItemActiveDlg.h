#if !defined(AFX_ITEMACTIVEDLG_H__BD398BC0_422A_4777_AD34_4CB62B6E5A07__INCLUDED_)
#define AFX_ITEMACTIVEDLG_H__BD398BC0_422A_4777_AD34_4CB62B6E5A07__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ItemActiveDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ItemActiveDlg dialog

class ItemActiveDlg : public CDialog
{
// Construction
public:
	ItemActiveDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ItemActiveDlg)
	enum { IDD = IDD_ItemActive };
	CButton	m_Check;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ItemActiveDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ItemActiveDlg)
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnCheck();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ITEMACTIVEDLG_H__BD398BC0_422A_4777_AD34_4CB62B6E5A07__INCLUDED_)
