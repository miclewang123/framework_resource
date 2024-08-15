// resizeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "resize.h"
#include "resizeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CResizeDlg dialog

CResizeDlg::CResizeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CResizeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CResizeDlg)
	m_cText = _T("Click The Start button to resize me !");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_tracker = NULL;
}

void CResizeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CResizeDlg)
	DDX_Control(pDX, IDC_STOP, m_cmdStop);
	DDX_Control(pDX, IDC_START, m_cmdStart);
	DDX_Text(pDX, IDC_EDIT1, m_cText);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CResizeDlg, CDialog)
	//{{AFX_MSG_MAP(CResizeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, OnStart)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_WM_SETCURSOR()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CResizeDlg message handlers

BOOL CResizeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CResizeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CResizeDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		if (m_tracker)
		{
			CDC* pDC = GetDC();
			m_tracker->Draw(pDC);
		}
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CResizeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CResizeDlg::OnStart() 
{
	CDC* pDC = GetDC();
	if (m_tracker)
	{
		delete m_tracker;
		m_tracker = NULL;
	}
	LPRECT rect = new RECT;
	CWnd* wnd = (CWnd*)(GetDlgItem(IDC_EDIT1));
	
	wnd->GetWindowRect(rect) ;
	ScreenToClient(rect) ;
	//pDC->LPtoDP(rect); 
	m_tracker = new CRectTracker(rect,CRectTracker::dottedLine  | CRectTracker::resizeOutside | CRectTracker::hatchedBorder );
	m_tracker->Draw(pDC)  ;
	delete rect;
	rect = NULL;
	
}

void CResizeDlg::OnStop() 
{
	if (m_tracker)
	{
		delete m_tracker;
		m_tracker = NULL;
		Invalidate(TRUE);
	}
	
}

BOOL CResizeDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	if (m_tracker)
		if (pWnd == this && m_tracker->SetCursor(this, nHitTest))
			return TRUE;

	
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}

void CResizeDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{

	if (m_tracker)
	{
		m_tracker->Track(this, point, TRUE);
		Invalidate(FALSE);		
		CDC* pDC = GetDC();
		m_tracker->Draw(pDC);

		LPRECT rect = new RECT;
		CWnd* wnd = (CWnd*)(GetDlgItem(IDC_EDIT1));
		rect = LPRECT(m_tracker->m_rect); 
		wnd->MoveWindow(rect,TRUE) ;
		rect = NULL;
		delete rect;
		rect = NULL;	
	}
	CDialog::OnLButtonDown(nFlags, point);
}
