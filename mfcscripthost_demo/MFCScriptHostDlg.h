// MFCScriptHostDlg.h : header file
//
//{{AFX_INCLUDES()
#include "commandbutton.h"
#include "webbrowser2.h"
#include "richtext.h"
//}}AFX_INCLUDES

#if !defined(AFX_MFCSCRIPTHOSTDLG_H__8BDE4776_BD4E_43E9_96B6_1D6A37C3B2B2__INCLUDED_)
#define AFX_MFCSCRIPTHOSTDLG_H__8BDE4776_BD4E_43E9_96B6_1D6A37C3B2B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Host_Proxy.h"

/////////////////////////////////////////////////////////////////////////////
// CMFCScriptHostDlg dialog

class CMFCScriptHostDlg : public CDialog
{
// Construction
public:
	CMFCScriptHostDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFCScriptHostDlg)
	enum { IDD = IDD_MFCSCRIPTHOST_DIALOG };
	CEdit	m_ctlScriptText;
	CCommandButton	m_btnGo;
	CWebBrowser2	m_webBrowser;
	CRichText	m_txtAddress;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCScriptHostDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CHost_Proxy	m_ScriptProxy;

	// Generated message map functions
	//{{AFX_MSG(CMFCScriptHostDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCSCRIPTHOSTDLG_H__8BDE4776_BD4E_43E9_96B6_1D6A37C3B2B2__INCLUDED_)
