// TrackerView.h : interface of the CTrackerView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRACKERVIEW_H__031A9743_5D17_4140_A614_15B44AB46DF2__INCLUDED_)
#define AFX_TRACKERVIEW_H__031A9743_5D17_4140_A614_15B44AB46DF2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// On compiling STL one need std namespace and receives
// many warning that can be ignored via pragma disable warning
// (I use SLT rather that MFC for no reason other than I learned it first.)
#pragma warning(disable:4786)
#include <vector>
using namespace std;

class CWS_PolyLine;

class CTrackerView : public CView
{
protected: // create from serialization only
	CTrackerView();
	DECLARE_DYNCREATE(CTrackerView)

// Attributes
public:
	CTrackerDoc*     GetDocument();
	CWS_RectTracker* pTracker;
	CWS_PolyLine*    pPolyLine;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrackerView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
public:
   void CreatePolyLine(CRect rc);
	void CreateTracker(CWS_PolyLine* ppolyline);
	CWS_PolyLine* CheckIntersection(CRect rc);
	virtual ~CTrackerView();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;

   void DEBUG_Display32Bits(unsigned __int32 value, CString from = _T(""));
#endif

protected:
   // Where poly lines are stored
   typedef vector < CWS_PolyLine* > m_PolyLinesType;
   m_PolyLinesType m_PolyLinesVec;

// Generated message map functions
protected:
	//{{AFX_MSG(CTrackerView)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnClear();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void DoSomethingSilly(int trackerhandle);
	void LimitTracker(int trackerhandle);
};

#ifndef _DEBUG  // debug version in TrackerView.cpp
inline CTrackerDoc* CTrackerView::GetDocument()
   { return (CTrackerDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRACKERVIEW_H__031A9743_5D17_4140_A614_15B44AB46DF2__INCLUDED_)
