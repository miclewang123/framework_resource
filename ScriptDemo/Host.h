#if !defined(AFX_HOST_H__DC5877E6_6FB7_4460_9FD4_8E87344FCDE1__INCLUDED_)
#define AFX_HOST_H__DC5877E6_6FB7_4460_9FD4_8E87344FCDE1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Host.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CHost command target

class CHost : public CCmdTarget
{
	DECLARE_DYNCREATE(CHost)


// Attributes
public:
	CHost();           // protected constructor used by dynamic creation

// Operations
public:
	void test();
	virtual ~CHost();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHost)
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHost)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOST_H__DC5877E6_6FB7_4460_9FD4_8E87344FCDE1__INCLUDED_)
