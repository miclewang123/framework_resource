#if !defined(AFX_GROUPSTATUSDLG_H__E702BDF5_9791_41F1_9837_861A177EB8BE__INCLUDED_)
#define AFX_GROUPSTATUSDLG_H__E702BDF5_9791_41F1_9837_861A177EB8BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GroupStatusDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// GroupStatusDlg dialog

class GroupStatusDlg : public CDialog
{
// Construction
public:
	void Refresh();
	GroupStatusDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(GroupStatusDlg)
	enum { IDD = IDD_GroupStatus };
	CEdit	m_Edit4;
	CEdit	m_Edit3;
	CEdit	m_Edit2;
	CEdit	m_Edit1;
	CButton	m_Check;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(GroupStatusDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(GroupStatusDlg)
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GROUPSTATUSDLG_H__E702BDF5_9791_41F1_9837_861A177EB8BE__INCLUDED_)
