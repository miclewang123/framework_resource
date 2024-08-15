// WS_PolyLine.cpp : implementation of the CWS_PolyLine class
//

#include "stdafx.h"
#include "Tracker.h"

#include "WS_PolyLine.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWS_PolyLine

// Useful -- so as to use VERIFY
//-----------------------------------------
IMPLEMENT_DYNAMIC(CWS_PolyLine, CObject) 
//-----------------------------------------

/////////////////////////////////////////////////////////////////////////////
// CWS_PolyLine construction/destruction

CWS_PolyLine::CWS_PolyLine(CPoint pnt, CSize size)
{
   //TRACE("CWS_PolyLine::CWS_PolyLine() pnt (%d, %d), size (%d, %d)\n",
   //   pnt.x, pnt.y, size.cx, size.cy);

   CreatePolyLine(pnt, size);

   // Translate the poly line from (0,0) (as created) to pnt (as drawn)
   Translate(pnt);
}

CWS_PolyLine::~CWS_PolyLine()
{
   m_PolyLineVec.clear();
}
//-------------------------------------------------------------------------

void CWS_PolyLine::Draw(CDC *pDC)
{
   bool first = true;
   CPoint pnt;
   vector < CPoint >::const_iterator iter;
   for (iter = m_PolyLineVec.begin(); iter != m_PolyLineVec.end(); ++iter)
   {
      pnt = *iter;
      if (first)
      {
         pDC->MoveTo(pnt);
         first = false;
      }
      else
      {
         pDC->LineTo(pnt);
      }
   }

   // If you would like to see the bounds of each PolyLine
   //DrawBounds(pDC);
}

// Create a random number of points (quantity limits > 5 and < 15)
// within a range of > 0 and < size.cx (or size.cy).  
// Output PolyLine origin is zero  and will be translated.
void CWS_PolyLine::CreatePolyLine(CPoint pnt, CSize size)
{
   // Create a vector with a minimum of 5 points and not more than 15
   // (Add one element of the point to the seed (time(0)) to help
   // randomize -- to solve a problem of identical poly lines being created.)
   int seed = time(0) + pnt.x;     
   srand(seed);
   int vecsize;
   do
   {
      vecsize = rand() % 15;
   } while (vecsize < 5);

   //TRACE("vecsize = %d\n", vecsize);

   // Create vecsize number of random points limited to no greater
   // than size[cx, cy].  

   // Note:  The rectangle defined by CSize is not necessarily filled.  
   // Rather, more likely, the bounds of the lines within the CSize 
   // rectangle will be smaller than the given CSize.
   seed = time(0) + pnt.y;
   srand(seed);
   for (int inx = 0; inx < vecsize; inx++)
   {
      CPoint pnt((rand() % size.cx), (rand() % size.cy));
      //TRACE("pnt (%d, %d)\n", pnt.x, pnt.y);
      m_PolyLineVec.push_back(pnt);
   }

#ifdef _DEBUG_CUT
   TRACE("-------------------- CWS_PolyLine::CreatePolyLine() ---------------\n");
   int saveTraceFlags = afxTraceFlags;
   afxTraceFlags = 0;
   vector < CPoint >::const_iterator iter;
   for (iter = m_PolyLineVec.begin(); iter != m_PolyLineVec.end(); ++iter)
   {
      TRACE("(%d, %d) ", (*iter).x, (*iter).y);
   }
   TRACE("\n");
   TRACE("-------------------------------------------------------------------\n");
   afxTraceFlags = saveTraceFlags;
#endif // _DEBUG

   // The created polyline is translated about (0,0).  Such that
   // the center of the poly line is the center of the bounds.
   CenterTranslate();
}

// Called only by CreatePolyLine().

// Used to center the created poly line about the input point
// Thus to make rc.Center() the origin of the poly line
// Input is m_PolyLineVec as created
// Output is a filled m_0_PolyLineVec (centered about (0,0)
// (All future transfers are done from m_0_PolyLineVec)
void CWS_PolyLine::CenterTranslate()
{
   // The poly line is drawn within the bounds of a rectangle
   // top left at (0,0).  But we want he center of the rectangle
   // to be (0,0).

   CPoint pnt = CalcBounds().CenterPoint();
   int pntx = -1 * pnt.x;
   int pnty = -1 * pnt.y;

   int inx;
   CPoint point;
   m_PolyLineType::const_iterator iter;
   for (iter = m_PolyLineVec.begin(), inx = 0; iter != m_PolyLineVec.end(); ++iter, inx++)
   {
      point = *iter;
      point.Offset(pntx, pnty);

      m_0_PolyLineVec.push_back(point);
   }

#ifdef _DEBUG_CUT
   int saveTraceFlags = afxTraceFlags;
   afxTraceFlags = 0;
   TRACE("-------------------- CWS_PolyLine::CenterTranslate() ---------------\n");
   //vector < CPoint >::const_iterator iter;
   for (iter = m_0_PolyLineVec.begin(); iter != m_0_PolyLineVec.end(); ++iter)
   {
      TRACE("(%d, %d) ", (*iter).x, (*iter).y);
   }
   TRACE("\n");
   TRACE("--------------------------------------------------------------------\n");
   afxTraceFlags = saveTraceFlags;
#endif // _DEBUG

}

void CWS_PolyLine::Translate(CPoint pnt)
{
   // Translate via CPoint class function Offset
   // and points of the existed vector are replace.

   //TRACE("CWS_PolyLine::Translate()  pnt (%d, %d)\n", pnt.x, pnt.y);

   int inx;
   CPoint point;
   m_PolyLineType::const_iterator iter;
   for (iter = m_0_PolyLineVec.begin(), inx = 0; iter != m_0_PolyLineVec.end(); ++iter, inx++)
   {
      point = *iter;
      point.Offset(pnt);

      TRY
      {
         m_PolyLineVec.at(inx) = point;
      }
      CATCH_ALL(error)
      {
         AfxMessageBox("Internal error -- no poly line created.");
         m_PolyLineVec.clear();
         return;
      }
      END_CATCH_ALL
   }

#ifdef _DEBUG_CUT
   int saveTraceFlags = afxTraceFlags;
   afxTraceFlags = 0;
   TRACE("-------------------- CWS_PolyLine::Translate() ---------------\n");
   //vector < CPoint >::const_iterator iter;
   for (iter = m_PolyLineVec.begin(); iter != m_PolyLineVec.end(); ++iter)
   {
      TRACE("(%d, %d) ", (*iter).x, (*iter).y);
   }
   TRACE("\n");
   TRACE("--------------------------------------------------------------\n");
   afxTraceFlags = saveTraceFlags;
#endif // _DEBUG

}

// Calculate the bounding rectangle of the polyline
CRect CWS_PolyLine::CalcBounds()
{
   CPoint tl;
   CPoint br;
   CRect bounds;
   
   // Initalize points used to find the min/max points used
   tl.x = INT_MAX;
   tl.y = INT_MAX;
   br.x = INT_MIN;
   br.y = INT_MIN;

   CPoint pnt;
   m_PolyLineType::const_iterator veciter;
   for (veciter = m_PolyLineVec.begin(); veciter != m_PolyLineVec.end(); ++ veciter)
   {
      pnt = *veciter;

      // Collect the min/max x's and y's to define a rectangle that
      // totally contains the polyline
      tl.x = __min(pnt.x, tl.x);
      tl.y = __min(pnt.y, tl.y);
      br.x = __max(pnt.x, br.x);
      br.y = __max(pnt.y, br.y);
   }
   bounds.SetRect(tl.x, tl.y, br.x, br.y);

   //TRACE("CWS_PolyLine::CalcBounds() top, right, bottom, left: %d, %d, %d, %d\n",
   //   bounds.top, bounds.right, bounds.bottom, bounds.left);

   return bounds;
}

#ifdef _DEBUG
void CWS_PolyLine::DEBUG_DrawBounds(CDC* pDC)
{
   // Draw a rectangle as lines so as not to hide 
   // any previous vectors.

   CRect rc = CalcBounds();
   pDC->MoveTo(rc.TopLeft());
   pDC->LineTo(rc.right, rc.top);
   pDC->LineTo(rc.BottomRight());
   pDC->LineTo(rc.left, rc.bottom);
   pDC->LineTo(rc.TopLeft());
}
#endif

