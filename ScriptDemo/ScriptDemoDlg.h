// ScriptDemoDlg.h : header file
//

#if !defined(AFX_SCRIPTDEMODLG_H__ED20D0A8_8DDF_11D6_917A_000086436E72__INCLUDED_)
#define AFX_SCRIPTDEMODLG_H__ED20D0A8_8DDF_11D6_917A_000086436E72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ScriptObject.h"
#include "host2.h"
/////////////////////////////////////////////////////////////////////////////
// CScriptDemoDlg dialog

class CScriptDemoDlg : public CDialog
{
// Construction
public:
	CScriptDemoDlg(CWnd* pParent = NULL);	// standard constructor
	CHost2	m_host;
// Dialog Data
	//{{AFX_DATA(CScriptDemoDlg)
	enum { IDD = IDD_SCRIPTDEMO_DIALOG };
	CEdit	m_ctlFilename;
	CEdit	m_ctlScript;
	CEdit	m_ctlResult;
	CEdit	m_ctlParameter;
	CComboBox	m_ctlFunctions;
	CComboBox	m_ctlLanguage;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScriptDemoDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	CScriptObject	m_ScriptObj;

	void FillFunctionsList();

	// Generated message map functions
	//{{AFX_MSG(CScriptDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnBrowse();
	afx_msg void OnBtnAddcode();
	afx_msg void OnBtnExecute();
	afx_msg void OnSelchangeCmbLanguage();
	afx_msg void OnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCRIPTDEMODLG_H__ED20D0A8_8DDF_11D6_917A_000086436E72__INCLUDED_)
