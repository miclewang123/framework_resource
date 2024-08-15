// DAC_VCDEMODlg.h : header file
//

#if !defined(AFX_DAC_VCDEMODLG_H__1AB96D79_C532_4C42_B01F_2945A9A45D2D__INCLUDED_)
#define AFX_DAC_VCDEMODLG_H__1AB96D79_C532_4C42_B01F_2945A9A45D2D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


/////////////////////////////////////////////////////////////////////////////
// CDAC_VCDEMODlg dialog

class CDAC_VCDEMODlg : public CDialog
{
// Construction
public:
	void ShutDown(DWORD hServer);
	void Refresh(DWORD ItemHandle, VARIANT v, WORD quality,_FILETIME ft);
	void AddItem(CString name);
	CDAC_VCDEMODlg(CWnd* pParent = NULL);	// standard constructor
// Dialog Data
	//{{AFX_DATA(CDAC_VCDEMODlg)
	enum { IDD = IDD_DAC_VCDEMO_DIALOG };
	CListCtrl	m_List;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDAC_VCDEMODlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDAC_VCDEMODlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMENUExit();
	afx_msg void OnMENUAbout();
	afx_msg void OnMENUConnect();
	afx_msg void OnMENUDisconnect();
	afx_msg void OnMENUGroupRefresh();
	afx_msg void OnMENUGroupStatus();
	afx_msg void OnMENUItemAdd();
	afx_msg void OnMENUITEMProperties();
	afx_msg void OnMENUITEMRead();
	afx_msg void OnMENUITEMRemove();
	afx_msg void OnMENUITEMWrite();
	afx_msg void OnMENUServerStatus();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnItemchanged(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMENUItemActive();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAC_VCDEMODLG_H__1AB96D79_C532_4C42_B01F_2945A9A45D2D__INCLUDED_)
