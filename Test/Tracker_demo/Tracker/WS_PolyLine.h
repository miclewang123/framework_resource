// CWS_PolyLine.h

// A PolyLine is random set of points within a specified CSize (rectangle).
// The created polyline, as it is random, does not necessarily fill the
// bounds of the provided CSize.  This caused problems with a random 
// displacement from the creation point (when TopLeft was used) and offest 
// problems when translated. The solution was to make the origin of the 
// polyline the center of the true bounds of the lines created.

// First the polyline is genereated in CreatePolyLine() which fills 
// m_PolyLineVec with initial data (which is corrected later). Then 
// the polyline is translated, via CenterTranslate() to (0,0) centered
// about the true bounds.  CenterTranslate() fills m_0_PolyLineVec().  
// All further translations are done using m_0_PolyLineVec data.
// Finally the data in m_PolylineVec is corrected via Translate().
// Thus the polyline is drawn centered about the users cursor.

// The polyline is drawn with data contained in m_PolyLineVec, and translated 
// with data contained in m_0_PolyLineVec.


#if !defined(CWS_POLYLINE_H__6E37C1D3_32FA_4AD0_ADB5_9A567CF8864E__INCLUDED_)
#define CWS_POLYLINE_H__6E37C1D3_32FA_4AD0_ADB5_9A567CF8864E__INCLUDED_

// On compiling STL one need std namespace and one receives
// many warning that can be ignored via pragma disable warning
// (I use SLT rather that MFC for no reason other than I learned it first.)
#pragma warning(disable:4786)
#include <vector>
using namespace std;

// A generic MFC class
class CWS_PolyLine : public CObject
{
   // useful so as to be able to use VERIFY (see IMPLEMENT_DYNAMIC in cpp)
   DECLARE_DYNAMIC( CWS_PolyLine )

public:
	CRect CalcBounds();
	void Translate(CPoint pnt);
	void Draw(CDC* pDC);

   //ctor/dtor
   CWS_PolyLine(CPoint pnt, CSize size);
   virtual ~CWS_PolyLine();

#ifdef _DEBUG
	void DEBUG_DrawBounds(CDC* pDC);
#endif

private:
	void CenterTranslate();
	void CreatePolyLine(CPoint pnt, CSize size);
   
   typedef vector < CPoint > m_PolyLineType;
   m_PolyLineType m_PolyLineVec;     // as visual data (about user location)
   m_PolyLineType m_0_PolyLineVec;   // as translation data (about (0,0)

};

#endif //!defined(CWS_POLYLINE_H__6E37C1D3_32FA_4AD0_ADB5_9A567CF8864E__INCLUDED_)


