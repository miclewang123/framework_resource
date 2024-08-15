// TrackerView.cpp : implementation of the CTrackerView class

#include "stdafx.h"
#include "Tracker.h"

#include "WS_RectTracker.h"
#include "TrackerDoc.h"
#include "TrackerView.h"
#include "WS_PolyLine.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTrackerView

IMPLEMENT_DYNCREATE(CTrackerView, CView)

BEGIN_MESSAGE_MAP(CTrackerView, CView)
	//{{AFX_MSG_MAP(CTrackerView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_CLEAR, OnClear)
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTrackerView construction/destruction

CTrackerView::CTrackerView()
{
   pTracker  = NULL;
   pPolyLine = NULL;
}

CTrackerView::~CTrackerView()
{
   CWS_PolyLine* ppolyline;
   vector < CWS_PolyLine* >::const_iterator iter;
   for (iter = m_PolyLinesVec.begin(); iter != m_PolyLinesVec.end(); ++iter)
   {
      ppolyline = *iter;
      ASSERT_VALID(ppolyline);
      delete ppolyline;
   }
   m_PolyLinesVec.clear();  // Un-necessary

   if (pTracker)
   {
      delete pTracker;
      pTracker = NULL;  // Un-necessary
   }
}

/////////////////////////////////////////////////////////////////////////////
// CTrackerView drawing

void CTrackerView::OnDraw(CDC* pDC)
{
	CTrackerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

   CWS_PolyLine* ppolyline;
   vector < CWS_PolyLine* >::const_iterator iter;
   for (iter = m_PolyLinesVec.begin(); iter != m_PolyLinesVec.end(); ++iter)
   {
      ppolyline = *iter;
      ASSERT_VALID(ppolyline);
      ppolyline->Draw(pDC);
	  TRACE("OnDraw\n");
   }
   if (pTracker)
   {
      pTracker->Draw(pDC);
   }
}

/////////////////////////////////////////////////////////////////////////////
// CTrackerView diagnostics

#ifdef _DEBUG
void CTrackerView::AssertValid() const
{
	CView::AssertValid();
}

void CTrackerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTrackerDoc* CTrackerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTrackerDoc)));
	return (CTrackerDoc*)m_pDocument;
}

// Nice little fuction to look at a bit map
void CTrackerView::DEBUG_Display32Bits(unsigned __int32 value, CString from)
{
   int saveTraceFlags = afxTraceFlags;
   afxTraceFlags = 0;
   
   if (!from.IsEmpty())
   {
      TRACE("--- %s ---:  ", from);
   }
   
   char chars[31];
   CString str;
   unsigned int inx, displayMask = 1 << 31;
   unsigned int mask;
   mask = value;
   
   if (value > 0xffffffff || value < 0)
   {
      TRACE("Limited to poitive intiger > 0 and < 0xFFFFFFFF (4294967295)\n");
      return;
   }
   
   //TRACE("value [%x]\n", value);
   
   for (inx = 0; inx <= 31; inx++)
      chars[inx] = '0';
   
   for (inx = 0; inx <= 31; inx++)
   {
      chars[inx] = (displayMask & mask) ? '1': '0';
      mask <<= 1;
   }
   //str.Format("Input (dec, hex, oct, bin): [%d]...[%o]...[%X]...[%c%c%c%c %c%c%c%c %c%c%c%c %c%c%c%c %c%c%c%c %c%c%c%c %c%c%c%c %c%c%c%c]\n",
   // value, value,value,
   //chars[ 0],chars[ 1],chars[ 2],chars[ 3],chars[ 4],chars[ 5],chars[ 6],chars[ 7],
   //chars[ 8],chars[ 9],chars[10],chars[11],chars[12],chars[13],chars[14],chars[15],
   //chars[16],chars[17],chars[18],chars[19],chars[20],chars[21],chars[22],chars[23],
   //chars[24],chars[25],chars[26],chars[27],chars[28],chars[29],chars[30],chars[31]);
   str.Format("[%c%c%c%c %c%c%c%c %c%c%c%c %c%c%c%c %c%c%c%c %c%c%c%c %c%c%c%c %c%c%c%c]",
      chars[ 0],chars[ 1],chars[ 2],chars[ 3],chars[ 4],chars[ 5],chars[ 6],chars[ 7],
      chars[ 8],chars[ 9],chars[10],chars[11],chars[12],chars[13],chars[14],chars[15],
      chars[16],chars[17],chars[18],chars[19],chars[20],chars[21],chars[22],chars[23],
      chars[24],chars[25],chars[26],chars[27],chars[28],chars[29],chars[30],chars[31]);
   TRACE("%s", str);
   
   if (!from.IsEmpty())
   {
      TRACE("  ----\n");
   }
   else
   {
      TRACE("\n");
   }
   afxTraceFlags = saveTraceFlags;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTrackerView message handlers

void CTrackerView::OnMouseMove(UINT nFlags, CPoint point) 
{
   // Begin a tracker rubber band effect if the left button is down.
   // Tracker rubber band is use to:
   //    1)  Select an existing poly line for resize
   //    2)  Insert a new poly line.

   if (nFlags & MK_LBUTTON)
   {
      // Insure the user has put the button down and is holding it.
      CWS_RectTracker tracker;
      // last argument: if false could rubber band only right and down
      if (tracker.TrackRubberBand(this, point, true))
      {
         // Point of interest:  The tracker class captures all mouse move
         // messages and does not return to here until the mouse button
         // is released.

         // Determine if the rubber band rectangle intersects with an existing poly line.
         // If so -- resize.
         // else create a new poly line
         
         CWS_PolyLine* pPolyLine = CheckIntersection(tracker.m_rect);
         if (pPolyLine)
         {
            MessageBeep(0); // beep indicates TRUE
            CreateTracker(pPolyLine);
            RedrawWindow();
         }
         else
         {
            // Poly line is a useless item class
            // it just gives us something to work with in this demo
            CreatePolyLine(tracker.m_rect);
            RedrawWindow();
         }
      }
   }
   CView::OnMouseMove(nFlags, point);
}


void CTrackerView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
   // For reference: The order of messages are:  down, up, dblclk, up

   // A Double Click (anywhere) turns tracker off
   if (pTracker)
   {
      delete pTracker;
      pTracker  = NULL;
      pPolyLine = NULL;
   }
   RedrawWindow();
   
   CView::OnLButtonDblClk(nFlags, point);
}


void CTrackerView::OnLButtonDown(UINT nFlags, CPoint point) 
{
   if (pTracker)
   {
      if ((pTracker->HitTest(point)) == CWS_RectTracker::hitNothing)
      {  
         // This test is not used -- just here to show it exists.
         // Perhaps one would want to turn tracker off.
         ;
      }
      else
      {
         // The user is on a tracker handle
         // From here, MFC will capture the messages

         int trackerhandle = pTracker->HitTest(point);
         if (pTracker->Track(this, point, false))
         {
            // Point of interest:  coordinates of point do
            // not change between entry and exit of tracker as OnMouseMove()
            // is not called while CRectTracker is capturing messages.
            // The new location of the cursor is NOT immediately available.
            // (here) upon the return from pTracker;
            
            TRACE("OnLButtonDown() HitTest() TrackerHandle %d\n", trackerhandle);
            // The user must have hit our tracker and may have resized
            // or translated our poly line.
            
            // This is where this example program actually does what is 
            // advertised -- change the mask.  (The rest, inserting a poly line,
            // drawing the tracker frame, translating the poly line, and
            // reproportionalize the poly line were all necessary window dressing,
            // just to have something to do and have some result to display.)

            // Translate (hitMiddle) is so simple, DoSomethingSilly() actually
            // translates the existing poly line.  So, don't limit the masks
            // if simply translating.
            if (trackerhandle != CWS_RectTracker::hitMiddle)
            {
               LimitTracker(trackerhandle);
            }
            
            // Some silly result
            
            // (Authors Note:
            // In my real code -- where I really needed to limit the user
            // to further resize work through this CRectTracker pointer
            // I proportionalized the points of my figure (not a poly line)
            // within the tracker rectangle.  It is not code I am proud of,
            // nor code I wish to be scorned for.  Furthermore, it is
            // un-necessary for the demo at hand.  Thus -- in this demo --
            // I merely delete the old poly line and fill the rectangle
            // with a new poly line.  Of course, you will have to figure out
            // why you would want to use this limit anyway -- so why bother
            // you with my silly reproportionalize code.)
            
            DoSomethingSilly(trackerhandle);
            
            RedrawWindow();
         }
      }
   }
   
   CView::OnLButtonDown(nFlags, point);
}

// Turn all tracker handles off, except that of trackerhandle
void CTrackerView::LimitTracker(int trackerhandle)
{
   if (pTracker)
   {
      unsigned int handlemask = 0x0000;
      switch (trackerhandle)
      {
      case CWS_RectTracker::hitTopLeft:
         handlemask |= 0x01;
         break;
         
      case CWS_RectTracker::hitTopRight:
         handlemask |= 0x02;
         break;
         
      case CWS_RectTracker::hitBottomRight:
         handlemask |= 0x04;
         break;
         
      case CWS_RectTracker::hitBottomLeft:
         handlemask |= 0x08;
         break;
         
      case CWS_RectTracker::hitTop:
         handlemask |= 0x10;
         break;
         
      case CWS_RectTracker::hitRight:
         handlemask |= 0x20;
         break;
         
      case CWS_RectTracker::hitBottom:
         handlemask |= 0x40;
         break;
         
      case CWS_RectTracker::hitLeft:
         handlemask |= 0x80;
         break;
         
      case CWS_RectTracker::hitMiddle:
         handlemask |= 0x100;
         break;
         
      case CWS_RectTracker::hitNothing:
      default:
         handlemask |= 0x00;
      }   
      
#ifdef _DEBUG
      //DEBUG_Display32Bits(pTracker->GetHandleMask(), " Pre Limit the mask");
#endif

      pTracker->SetHandleMask(handlemask);

#ifdef _DEBUG
      //DEBUG_Display32Bits(pTracker->GetHandleMask(), "Post Limit the mask");
#endif
   }
}

// Some silly something to show some result
void CTrackerView::DoSomethingSilly(int trackerhandle)
{
   // Repeated note from OnLButtonDown()
   
   // (Authors Note:
   // In my real code -- where I really needed to limit the user
   // to further resize work through this CRectTracker pointer
   // I proportionalized the points of my figure (not a poly line)
   // within the tracker rectangle.  It is not code I am proud of,
   // nor code I wish to be scorned for.  Furthermore, it is
   // un-necessary for the demo at hand.  Thus -- in this demo --
   // I mearly delete the old poly line and fill the rectangle
   // with a new poly line.  Of course, you will have to figure out
   // why you would want to use this limit anyway -- so why bother
   // you with my silly reporotionalization code.)
   
   // pPolyLine was set in OnMouseMove() if a poly line has
   // been selected and a CWS_RectTracker instance allocated.
   if (pPolyLine)
   {
      CWS_PolyLine* ppolyline;
      int inx;
      m_PolyLinesType::const_iterator iter;

      CRect rc = pTracker->m_rect;
      rc.NormalizeRect();

      switch (trackerhandle)
      {
         // Translation
      case CWS_RectTracker::hitMiddle:
         // Translation is so easy -- I go ahead and translate
         pPolyLine->Translate(rc.CenterPoint());
         break;
         
      case CWS_RectTracker::hitNothing:
         // do nothing
         break;

      default:
         // hit some other handle
         // (We ASSUME (make an ASS out of yoU and ME :-)) that there
         // isn't something other than a good handle hit, or one of the
         // two above.)
         
         // Here I would actually porotionalize the old to the new.
         // But for this demo -- just delete the old and create a new poly line.
         
         // Find our poly line -- in this real code -- where I have LOTS of objects
         // I actually use a STL map rather than a vector and use the map find function.
         // for effciency.  Here, I simply do a liner search (few objects and only
         // one to find)
         for (iter = m_PolyLinesVec.begin(), inx = 0; iter != m_PolyLinesVec.end(); ++iter, inx++)
         {
            ppolyline = *iter;
            ASSERT_VALID(ppolyline);
            if (ppolyline == pPolyLine)
            {
               CWS_PolyLine* pPL = new CWS_PolyLine(rc.CenterPoint(), rc.Size());
               TRY
               {
                  m_PolyLinesVec.at(inx) = pPL;
               }
               CATCH_ALL(error)
               {
                  AfxMessageBox("Internal error -- start over again.");
                  delete pPL;
                  OnClear();
                  return;
               }
               END_CATCH_ALL
                  
               delete pPolyLine;
               pPolyLine = pPL;
               break;
            }
         }
      }
   }
}

// If input rc intersects any existing poly line, return the
// first poly line found.  If not return NULL.
CWS_PolyLine* CTrackerView::CheckIntersection(CRect rc)
{
   m_PolyLinesType::const_iterator iter;
   for (iter = m_PolyLinesVec.begin(); iter != m_PolyLinesVec.end(); ++iter)
   {
      pPolyLine = *iter;
      ASSERT_VALID(pPolyLine);
      CRect bounds = pPolyLine->CalcBounds();
      
      if (bounds.IntersectRect(bounds, rc))
      {  
         // Returns the first found
         // (Can only select for resize one poly line at a time.)
         return pPolyLine;
      }
   }
   return NULL;
}

void CTrackerView::CreateTracker(CWS_PolyLine *ppolyline)
{
   // If an old pointer -- get rid of it
   if (pTracker)
   {
      delete pTracker;
   }
   
   // Set the style (see MSDN CRectTracker documentation)
   // and define the tracker rectangle
   unsigned int style = 0x0000;
   style = CWS_RectTracker::resizeOutside | CWS_RectTracker::solidLine;
   pTracker = new CWS_RectTracker(pPolyLine->CalcBounds(), style);
   ASSERT(pTracker);
}

void CTrackerView::CreatePolyLine(CRect rc)
{
   CWS_PolyLine* pPolyLine = new CWS_PolyLine(rc.CenterPoint(), rc.Size());
   ASSERT_VALID(pPolyLine);
   m_PolyLinesVec.push_back(pPolyLine);
}

void CTrackerView::OnClear() 
{
   CWS_PolyLine* ppolyline;
   vector < CWS_PolyLine* >::const_iterator iter;
   for (iter = m_PolyLinesVec.begin(); iter != m_PolyLinesVec.end(); ++iter)
   {
      ppolyline = *iter;
      ASSERT_VALID(ppolyline);
      delete ppolyline;
   }
   m_PolyLinesVec.clear();

   if (pTracker)
   {
      delete pTracker;
      pTracker = NULL;
   }
   pPolyLine = NULL;
   RedrawWindow();
}

BOOL CTrackerView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
   // Set the tracker cursor on resize
   if (pTracker)
   {
      if (pWnd == this && pTracker->SetCursor(this, nHitTest))
      {
         return TRUE;
      }
   }
	
	return CView::OnSetCursor(pWnd, nHitTest, message);
}
