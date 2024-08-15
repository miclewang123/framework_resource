#if !defined(AFX_SERVERSTATUSDLG_H__7E00B532_4ACA_4A69_A03B_CC47E41CDCFD__INCLUDED_)
#define AFX_SERVERSTATUSDLG_H__7E00B532_4ACA_4A69_A03B_CC47E41CDCFD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ServerStatusDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ServerStatusDlg dialog

class ServerStatusDlg : public CDialog
{
// Construction
public:
	void Refresh();
	ServerStatusDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ServerStatusDlg)
	enum { IDD = IDD_ServerStatus };
	CEdit	m_Edit9;
	CEdit	m_Edit8;
	CEdit	m_Edit7;
	CEdit	m_Edit6;
	CEdit	m_Edit5;
	CEdit	m_Edit4;
	CEdit	m_Edit3;
	CEdit	m_Edit2;
	CEdit	m_Edit1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ServerStatusDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ServerStatusDlg)
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERSTATUSDLG_H__7E00B532_4ACA_4A69_A03B_CC47E41CDCFD__INCLUDED_)
