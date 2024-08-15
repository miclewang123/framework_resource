// TrackerDoc.h : interface of the CTrackerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRACKERDOC_H__CC74347D_8CAE_4178_952F_C868BD94760D__INCLUDED_)
#define AFX_TRACKERDOC_H__CC74347D_8CAE_4178_952F_C868BD94760D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CWS_RectTracker;

class CTrackerDoc : public CDocument
{
protected: // create from serialization only
	CTrackerDoc();
	DECLARE_DYNCREATE(CTrackerDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrackerDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTrackerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTrackerDoc)
	afx_msg void OnHowTo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRACKERDOC_H__CC74347D_8CAE_4178_952F_C868BD94760D__INCLUDED_)
