// TrackerDoc.cpp : implementation of the CTrackerDoc class
//

#include "stdafx.h"
#include "Tracker.h"

#include "WS_RectTracker.h"
#include "TrackerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTrackerDoc

IMPLEMENT_DYNCREATE(CTrackerDoc, CDocument)

BEGIN_MESSAGE_MAP(CTrackerDoc, CDocument)
	//{{AFX_MSG_MAP(CTrackerDoc)
	ON_COMMAND(ID_HOWTO, OnHowTo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTrackerDoc construction/destruction

CTrackerDoc::CTrackerDoc()
{
}

CTrackerDoc::~CTrackerDoc()
{
}

BOOL CTrackerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTrackerDoc serialization

void CTrackerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTrackerDoc diagnostics

#ifdef _DEBUG
void CTrackerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTrackerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTrackerDoc commands

void CTrackerDoc::OnHowTo() 
{
   // I format my long messages like this only so the IDE
   // aligns nicely, and so the message may be easily read.
   CString msg1 = _T("A poly line is used to give us something to work with.\n");
   CString msg2 = _T("Left mouse down, hold and move (tracker rubber band) to create a poly line.\n");
   CString msg3 = _T("Rubber band an existing poly line to begin a resize operation.\n");
   CString msg4 = _T("Double click anywhere to end a tracker operation.\n");

   CString msg = msg1 + msg2 + msg3 + msg4;
   AfxMessageBox(msg);
}
