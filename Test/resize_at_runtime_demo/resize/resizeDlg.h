// resizeDlg.h : header file
//

#if !defined(AFX_RESIZEDLG_H__D86683C7_A897_11D4_B093_005004FEF14D__INCLUDED_)
#define AFX_RESIZEDLG_H__D86683C7_A897_11D4_B093_005004FEF14D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CResizeDlg dialog

class CResizeDlg : public CDialog
{
// Construction
public:
	CResizeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CResizeDlg)
	enum { IDD = IDD_RESIZE_DIALOG };
	CButton	m_cmdStop;
	CButton	m_cmdStart;
	CString	m_cText;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CResizeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CRectTracker*	m_tracker;	

	// Generated message map functions
	//{{AFX_MSG(CResizeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStart();
	afx_msg void OnStop();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESIZEDLG_H__D86683C7_A897_11D4_B093_005004FEF14D__INCLUDED_)
