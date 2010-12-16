// ProjClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ProjClient.h"
#include "ProjClientDlg.h"
#include "Globals.h"

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
// CProjClientDlg dialog


//globals used by decompressor
unsigned char rgb_data[80000];
int buffersize=80000;


CProjClientDlg::CProjClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProjClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProjClientDlg)
	m_strStatus = _T("");
	m_strRemote = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProjClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProjClientDlg)
	DDX_Text(pDX, IDC_STATUSBOX, m_strStatus);
	DDX_Text(pDX, IDC_REMOTE, m_strRemote);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CProjClientDlg, CDialog)
	//{{AFX_MSG_MAP(CProjClientDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNECT, OnConnectBut)
	ON_BN_CLICKED(IDC_DISCONNECT, OnDisconnectBut)
	ON_BN_CLICKED(IDC_LEFT, OnLeftBut)
	ON_BN_CLICKED(IDC_RIGHT, OnRightBut)
	ON_BN_CLICKED(IDCANCEL, OnExitBut)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProjClientDlg message handlers

BOOL CProjClientDlg::OnInitDialog()
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
	

	
///////////////////////Initialization

	//initialize decoder
	InitH263Decoder();

	m_strRemote = "127.0.0.1";
	UpdateData(FALSE);
	PostStatus("Ready...");
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CProjClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CProjClientDlg::OnPaint() 
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
HCURSOR CProjClientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CProjClientDlg::OnConnectBut() 
{
	PostStatus("Connecting...");
	sckData.Close();
	sckData.OpenDataSocket(this);
	sckData.SendData(D_CONNECT);
	
}

void CProjClientDlg::ProcessConfirm()
{
	PostStatus("Receiving video.");

	//Prepare for DIB drawing:
	m_hdc=this->GetDC()->m_hDC;

	m_bmpinfo=new BITMAPINFO;
	m_bmpinfo->bmiHeader.biSize=sizeof(BITMAPINFOHEADER);
	m_bmpinfo->bmiHeader.biWidth=IMAGE_WIDTH;
	m_bmpinfo->bmiHeader.biHeight=IMAGE_HEIGHT;
	m_bmpinfo->bmiHeader.biPlanes=1;
	m_bmpinfo->bmiHeader.biBitCount=24;
	m_bmpinfo->bmiHeader.biCompression=0;
	m_bmpinfo->bmiHeader.biSizeImage=0;
	m_bmpinfo->bmiHeader.biXPelsPerMeter=0;
	m_bmpinfo->bmiHeader.biYPelsPerMeter=0;
	m_bmpinfo->bmiHeader.biClrUsed=0;
	m_bmpinfo->bmiHeader.biClrImportant=0;

	hdib=::DrawDibOpen();
	if(hdib!=NULL)
	{
		::DrawDibBegin(hdib, m_hdc, -1, -1,	&m_bmpinfo->bmiHeader,
			IMAGE_WIDTH, IMAGE_HEIGHT, 0);	
	}

	sckVideo.Close();
	sckVideo.OpenVideoSocket(this);
}

void CProjClientDlg::ProcessAbort()
{
	PostStatus("Connection closed.");
	Invalidate(TRUE);
}

void CProjClientDlg::OnDisconnectBut() 
{
	sckData.SendData(D_DISCONNECT);
	PostStatus("Disconnecting...");

	//close DIB functions
	if(hdib!=NULL)
	{
	::DrawDibEnd(hdib);
	::DrawDibClose(hdib);
	}
	
	delete m_bmpinfo;

	Invalidate(TRUE); //redraw window

	sckData.Close();
	sckVideo.Close();
}


void CProjClientDlg::DisplayFrame(BYTE *data,int size)
{
	int retvalue;
	//Decompress
	retvalue=DecompressFrame(data,size,rgb_data,buffersize);

	//Draw
	::DrawDibDraw(hdib, m_hdc, 12, 12, -1, -1, &m_bmpinfo->bmiHeader,
		rgb_data, 0, 0, IMAGE_WIDTH, IMAGE_HEIGHT, DDF_SAME_DRAW);

}


void CProjClientDlg::PostStatus(char *string)
{
	UpdateData();
	m_strStatus += string;
	m_strStatus += "\r\n";
	UpdateData(FALSE);
}

void CProjClientDlg::OnLeftBut() 
{
	sckData.SendData(D_MOVELEFT);
	
}

void CProjClientDlg::OnRightBut() 
{
	sckData.SendData(D_MOVERIGHT);
	
}

void CProjClientDlg::OnExitBut() 
{
	//close sockets
	sckVideo.Close();
	sckData.Close();

	PostQuitMessage(0);
}
