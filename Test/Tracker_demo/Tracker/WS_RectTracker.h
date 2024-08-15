// WS_RectTracker.h: interface for the CWS_RectTracker class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WSRECTTRACKER_H__616B1973_E946_459C_9C66_56DF3F8E3775__INCLUDED_)
#define AFX_WSRECTTRACKER_H__616B1973_E946_459C_9C66_56DF3F8E3775__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CWS_RectTracker : public CRectTracker  
{
public:
   CWS_RectTracker();
	CWS_RectTracker(LPCRECT lpSrcRect, UINT nStyle);
	virtual ~CWS_RectTracker();

   unsigned int GetHandleMask( ) const; // Override
   void SetHandleMask(unsigned int mask) { m_HandleMask = mask; }

private:
   unsigned int m_HandleMask;
};

#endif // !defined(AFX_WSRECTTRACKER_H__616B1973_E946_459C_9C66_56DF3F8E3775__INCLUDED_)
