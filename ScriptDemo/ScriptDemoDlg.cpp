// ScriptDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ScriptDemo.h"
#include "SafeArrayHelper.h"
#include "ScriptDemoDlg.h"
#include "host2.h"
#include "hyperlink.h"

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
	CHyperLink	m_hlHomeSite;
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
	DDX_Control(pDX, IDC_HOMESITE, m_hlHomeSite);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScriptDemoDlg dialog

CScriptDemoDlg::CScriptDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CScriptDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScriptDemoDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CScriptDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScriptDemoDlg)
	DDX_Control(pDX, IDC_TXT_FILENAME, m_ctlFilename);
	DDX_Control(pDX, IDC_TXT_SCRIPT, m_ctlScript);
	DDX_Control(pDX, IDC_TXT_RESULT, m_ctlResult);
	DDX_Control(pDX, IDC_TXT_PARAMETER, m_ctlParameter);
	DDX_Control(pDX, IDC_CMB_FUNCTIONS, m_ctlFunctions);
	DDX_Control(pDX, IDC_CMB_LANGUAGE, m_ctlLanguage);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CScriptDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CScriptDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_BROWSE, OnBtnBrowse)
	ON_BN_CLICKED(IDC_BTN_ADDCODE, OnBtnAddcode)
	ON_BN_CLICKED(IDC_BTN_EXECUTE, OnBtnExecute)
	ON_CBN_SELCHANGE(IDC_CMB_LANGUAGE, OnSelchangeCmbLanguage)
	ON_BN_CLICKED(IDC_ABOUT, OnHelp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScriptDemoDlg message handlers

BOOL CScriptDemoDlg::OnInitDialog()
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
	
	// TODO: Add extra initialization here
	m_ctlLanguage.SelectString(0, m_ScriptObj.GetLanguage() );

	//将m_host暴露给脚本
	BOOL bOK=m_ScriptObj.AddObject("app",m_host.GetIDispatch(FALSE),TRUE);
	m_ScriptObj.SetTimeout(-1);
	//示例脚本
	SetDlgItemText(IDC_TXT_SCRIPT,"function test(strCmd)\r\n{\r\n\tapp.test(strCmd);\r\n}");
	SetDlgItemText(IDC_TXT_PARAMETER,"Hide");
	return TRUE;  // return TRUE  unless you set the focus to a control
}


BOOL CScriptDemoDlg::PreTranslateMessage(MSG* pMsg) 
{
	if (pMsg->message == WM_KEYDOWN)
	{
		int nVirtKey = (int) pMsg->wParam;
		if (nVirtKey == VK_ESCAPE)
			return TRUE;
		if (nVirtKey == VK_RETURN )
		{
			return FALSE;
		}
	}
	
	return CDialog::PreTranslateMessage(pMsg);
}


void CScriptDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CScriptDemoDlg::OnPaint() 
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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CScriptDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CScriptDemoDlg::FillFunctionsList()
{
	m_ctlFunctions.ResetContent();

	int nCount = m_ScriptObj.GetMethodsCount();
	for(int index=0; index<nCount; index++)
	{
		CString strFunc = m_ScriptObj.GetNameAt( index );
		m_ctlFunctions.AddString( strFunc );
	}
}


void CScriptDemoDlg::OnBtnBrowse() 
{
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		_T("Script Files (*.js; *.vbs)|*.js;*.vbs|Text Files (*.txt)|*.txt|All Files (*.*)|*.*||"));
	if (dlg.DoModal() == IDOK)
	{
		m_ScriptObj.Reset();
		m_ctlFilename.SetWindowText( dlg.GetPathName() );
		m_ScriptObj.LoadScript( dlg.GetPathName() );
		FillFunctionsList();
		char *pszBuf=NULL;
		CFile f;
		f.Open(dlg.GetPathName(),CFile::modeRead|CFile::typeBinary);
		int nSize=f.GetLength();
		pszBuf=new char[nSize+1];
		f.Read(pszBuf,nSize);
		pszBuf[nSize]=0;
		f.Close();

		m_ctlScript.SetWindowText(pszBuf);
		delete []pszBuf;
	}
}

void CScriptDemoDlg::OnBtnAddcode() 
{
	CString strCode;
	m_ctlScript.GetWindowText( strCode );
	if (!m_ScriptObj.AddScript( strCode ))
	{
		CString strError = m_ScriptObj.GetErrorString();
		m_ctlResult.SetWindowText( strError );
	}
	else
		m_ctlResult.SetWindowText( _T("") );

	FillFunctionsList();
}

void CScriptDemoDlg::OnBtnExecute() 
{
	CString strParam, strProc;
	m_ctlParameter.GetWindowText( strParam );
	m_ctlFunctions.GetWindowText( strProc );

	CSafeArrayHelper sfHelper;
	try{
		_variant_t var;
		if (strParam.IsEmpty())
		{
			sfHelper.Create(VT_VARIANT, 1, 0, 0);	// (void) parameter
		}else
		{

			sfHelper.Create(VT_VARIANT, 1, 0, 1);	// 1 parameter
			var = _bstr_t(strParam);
		}
		sfHelper.PutElement(0, (void*)&var);	// parameter1 -> index 0
		LPSAFEARRAY sa =  sfHelper.GetArray();
		_variant_t varRet;
		if (m_ScriptObj.RunProcedure(strProc, &sa, &varRet))
			m_ctlResult.SetWindowText( (LPCTSTR)(_bstr_t(varRet)) );
		else
		{
			CString strError = m_ScriptObj.GetErrorString();
			m_ctlResult.SetWindowText( strError );
		}
	}
	catch(...)
	{
		CString strError = m_ScriptObj.GetErrorString();
		m_ctlResult.SetWindowText( strError );
	}
}

void CScriptDemoDlg::OnSelchangeCmbLanguage() 
{
	CString sLanguage;
	m_ctlLanguage.GetWindowText( sLanguage );
	m_ScriptObj.SetLanguage( sLanguage );

	FillFunctionsList();
}



void CScriptDemoDlg::OnHelp() 
{
	PostMessage(WM_SYSCOMMAND,IDM_ABOUTBOX);
}
