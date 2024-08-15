#if !defined(AFX_ITEMWRITEDLG_H__8118BE3E_9D4A_4A94_A579_4F75936D6222__INCLUDED_)
#define AFX_ITEMWRITEDLG_H__8118BE3E_9D4A_4A94_A579_4F75936D6222__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ItemWriteDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ItemWriteDlg dialog

class ItemWriteDlg : public CDialog
{
// Construction
public:
	ItemWriteDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ItemWriteDlg)
	enum { IDD = IDD_ItemWrite };
	CButton	m_Check;
	CEdit	m_Edit1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ItemWriteDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ItemWriteDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ITEMWRITEDLG_H__8118BE3E_9D4A_4A94_A579_4F75936D6222__INCLUDED_)
