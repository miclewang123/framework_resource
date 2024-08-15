// WS_RectTracker.cpp: implementation of the CWS_RectTracker class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFXExt.h"

#ifdef WS_DESIGNS_CONTAINER
#include "WSDesigns.h"
#endif
#ifdef WS_DESIGNS_SERVER
#include "WSPatterns.h"
#endif

#include "WS_RectTracker.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// Created to override GetHandleMask so as to turn off resize handles


CWS_RectTracker::CWS_RectTracker()
{
   m_HandleMask = 0x0000;
}


// Contents copied from CRectTracker constructor
CWS_RectTracker::CWS_RectTracker(LPCRECT lpSrcRect, UINT nStyle)
{
   ASSERT(AfxIsValidAddress(lpSrcRect, sizeof(RECT), FALSE));
   CRectTracker::Construct();
   CRectTracker::m_rect.CopyRect(lpSrcRect);
   CRectTracker::m_nStyle = nStyle;
   m_HandleMask = 0x0000;
}

CWS_RectTracker::~CWS_RectTracker()
{
   CRectTracker::~CRectTracker();
}


unsigned int CWS_RectTracker::GetHandleMask() const
{
   //-----------------------------------------------------------
   // Once one handle is used, that becomes the ONLY handle available.
   
   // This is one of the rare cases where I knowingly short the user
   // to avoid programming problems.  But to allow the user to move
   // other handles and maintain a resonable proprotional object
   // was beyond my reach.

   // In DemoTracker(), the call
   //    pTracker->SetHandleMask(handlemask); sets m_HandleMask
   // And here, from CTrackerView::OnDraw() which calls pTracker->Draw()
   // which calls this overriden GetHandleMask(), and the mask is changed.
   // Specifically:  once the user has resized via one handle, that handle 
   // becomes the ONLY available handle.
   if (m_HandleMask)
   {
      if (m_HandleMask & 0x0100)
      {
         // This is a special bit for CWS_RectTracker::hitMiddle (Translate)
         // Turn off ALL handles
         return 0x0000;
      }
      // Else return the one handle set in CWS_Edits::ResizeSpline()

      return m_HandleMask;
   }
   else
   {
      // Original code from MFC CRectTracke::GetHandleMask()
      
      // 0x00 0000 0000 is no handles (translate)
      // 0x0F 0000 1111 is the 4 corners
      // 0x50 0101 0000 is the right and left sides
      // 0xA0 1010 0000 is the top and bottom
      
      UINT mask = 0x0F;   // always have 4 corner handles
      int size = m_nHandleSize*3;
      if (abs(m_rect.Width()) - size > 4)
         mask |= 0x50;
      if (abs(m_rect.Height()) - size > 4)
         mask |= 0xA0;
      return mask;
   }
}

