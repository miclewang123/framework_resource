#if !defined(AFX_HOST2_H__FEE87F03_2009_4DB1_AF74_FED3C0352030__INCLUDED_)
#define AFX_HOST2_H__FEE87F03_2009_4DB1_AF74_FED3C0352030__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Host2.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CHost2 command target

class CHost2 : public CCmdTarget
{
	DECLARE_DYNCREATE(CHost2)

	CHost2();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHost2)
	public:
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CHost2)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CHost2)
	afx_msg long Test(LPCTSTR strCmd);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

// Note: we add support for IID_IHost2 to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {BBD4DAF6-616A-4BF6-A920-F90A5C7E2B39}
static const IID IID_IHost2 =
{ 0xbbd4daf6, 0x616a, 0x4bf6, { 0xa9, 0x20, 0xf9, 0xa, 0x5c, 0x7e, 0x2b, 0x39 } };

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOST2_H__FEE87F03_2009_4DB1_AF74_FED3C0352030__INCLUDED_)
