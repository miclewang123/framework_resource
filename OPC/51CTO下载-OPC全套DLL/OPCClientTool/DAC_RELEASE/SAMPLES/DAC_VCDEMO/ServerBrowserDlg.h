#if !defined(AFX_SERVERBROWSERDLG_H__47B7BD22_6042_4933_AEB8_475C75D39972__INCLUDED_)
#define AFX_SERVERBROWSERDLG_H__47B7BD22_6042_4933_AEB8_475C75D39972__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ServerBrowserDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ServerBrowserDlg dialog
class ServerBrowserDlg : public CDialog
{
// Construction
public:
	CString CID[128], CNM[128];
	ServerBrowserDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ServerBrowserDlg)
	enum { IDD = IDD_ServerBrowser };
	CButton	m_Check;
	CEdit	m_Edit3;
	CEdit	m_Edit2;
	CEdit	m_Edit1;
	CListBox	m_List;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ServerBrowserDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ServerBrowserDlg)
	afx_msg void OnRefresh();
	afx_msg void OnSelChange();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERBROWSERDLG_H__47B7BD22_6042_4933_AEB8_475C75D39972__INCLUDED_)
