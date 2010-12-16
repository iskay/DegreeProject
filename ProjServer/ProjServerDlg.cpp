// ProjServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ProjServer.h"
#include "ProjServerDlg.h"
#include "MySocket.h"
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
// CProjServerDlg dialog


//globals that are used by the compressor
int cbyte=0;
unsigned char cdata[10000];
int cbuffer_size=10000;
int frame_count=0;


//compressor callback (writes compressed data into cdata[])
void OwnWriteFunction(int byte)
{
	if(cbyte<cbuffer_size)
	cdata[cbyte]=(unsigned char)byte;	
	cbyte++;
}


CProjServerDlg::CProjServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProjServerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProjServerDlg)
	m_strStatus = _T("");
	m_strRemote = _T("");
	m_strPort = _T("");
	m_SerialEnabled = FALSE;
	m_VideoEnabled = FALSE;
	m_FrameSkip = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProjServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProjServerDlg)
	DDX_Text(pDX, IDC_STATUSBOX, m_strStatus);
	DDX_Text(pDX, IDC_REMOTE, m_strRemote);
	DDX_Text(pDX, IDC_PORT, m_strPort);
	DDX_Check(pDX, IDC_CHECKSERIAL, m_SerialEnabled);
	DDX_Check(pDX, IDC_CHECKVIDEO, m_VideoEnabled);
	DDX_Text(pDX, IDC_FRAME_SKIP, m_FrameSkip);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CProjServerDlg, CDialog)
	//{{AFX_MSG_MAP(CProjServerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDCANCEL, OnExitBut)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProjServerDlg message handlers

BOOL CProjServerDlg::OnInitDialog()
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
	
	
	
/////////////////////////////Initialization

	MyCap = NULL;
	sckData.OpenDataSocket(this);
	hComm = NULL;

	m_strPort = "Com2";
	m_VideoEnabled = TRUE;
	m_SerialEnabled = TRUE;
	m_FrameSkip = 5;
	UpdateData(FALSE);
	PostStatus("Ready...");

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CProjServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CProjServerDlg::OnPaint() 
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
HCURSOR CProjServerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CProjServerDlg::PrepareVideo()
{
	//new capture instance
	MyCap = new CapObj;

	//lookup table for RGB to YUV conversion
	InitLookupTable();

	//initialize the compressor
	cparams.format = CPARAM_QCIF;
	InitH263Encoder(&cparams);  

	//set compressor callback function
	WriteByteFunction = OwnWriteFunction;
}

int CProjServerDlg::PrepareSerialPort()
{
//	CString name;
//	name="Com2";

	//open port
	hComm = CreateFile(m_strPort, GENERIC_READ | GENERIC_WRITE, 0, NULL, 
                    OPEN_EXISTING, 0, NULL);

	if (hComm == NULL) return 0;

	SetupComm(hComm, 128, 128);
	
	//dcb = {0};

	//initialize port settings
	GetCommState(hComm, &dcb);
	dcb.BaudRate = BAUD_RATE;
	dcb.ByteSize = 8;
	dcb.Parity = NOPARITY;
	dcb.StopBits = ONESTOPBIT;
	dcb.fAbortOnError = TRUE;
	SetCommState(hComm, &dcb);

	//initialize port timeouts
	//values are in milliseconds
	commTimeout.ReadIntervalTimeout = 5000;
    commTimeout.ReadTotalTimeoutConstant = 5000;
    commTimeout.ReadTotalTimeoutMultiplier = 0;
    commTimeout.WriteTotalTimeoutConstant = 5000;
    commTimeout.WriteTotalTimeoutMultiplier = 0;

	SetCommTimeouts(hComm, &commTimeout);

	return 1;
}

void CProjServerDlg::ProcessConnect()
{
	PostStatus("Connection request...");

	//start video capture if video is enabled
	UpdateData();
	if (m_VideoEnabled == TRUE)
	{
		PrepareVideo();

		if(!MyCap->vInit(this))
		{
			PostStatus("Couldn't initalize video!");
			return;
		}
	
		if(!MyCap->vStartCap())
		{
			PostStatus("Couldn't initalize video!");
			return;
		}
	
		sckVideo.OpenVideoSocket(this);
		frame_count=0;
		PostStatus("Sending video...");
	}


	//open serial port if enabled
	if (m_SerialEnabled == TRUE)
	{
		if (!PrepareSerialPort())
		{
			PostStatus("Couldn't initalize serial port!");
		}
	}
	
	m_strRemote = str_remoteAddr;
	UpdateData(FALSE);
	sckData.SendData(D_CONFIRM);
}


void CProjServerDlg::ProcessDisconnect()
{
	//stop video
	if (MyCap != NULL)
	{
		MyCap->vStopCap();
		MyCap = NULL;
	}
	sckVideo.Close();

	//close serial port
	if (hComm != NULL)
	{
		CloseHandle(hComm);
		hComm = NULL;
	}

	sckData.SendData(D_ABORT);
	PostStatus("Connection closed.");
	m_strRemote = "";
	UpdateData(FALSE);
}

void CProjServerDlg::ProcessMoveLeft()
{
	if (hComm == NULL) return;
	
	DWORD retvalue=0;
	WriteFile(hComm, SERIAL_MOVELEFT, 1, &retvalue, NULL);
	if (retvalue != 0) PostStatus("Moving left.");
}

void CProjServerDlg::ProcessMoveRight()
{
	if (hComm == NULL) return;

	DWORD retvalue=0;
	WriteFile(hComm, SERIAL_MOVERIGHT, 1, &retvalue, NULL);
	if (retvalue != 0) PostStatus("Moving right.");
}

void CProjServerDlg::SendFrame(BYTE *data,int size)
{
	if (frame_count < m_FrameSkip)
	{
		frame_count++;
		return;
	}

	Bits bits;	//used by compressor

	//convert image to YUV	
	ConvertRGB2YUV(IMAGE_WIDTH,IMAGE_HEIGHT,data,yuv);

	//byte counter
	cbyte=0;

	//compress
	cparams.format=CPARAM_QCIF;
	cparams.inter=CPARAM_INTRA;  
	cparams.Q_intra=8;
	cparams.data=yuv;
	CompressFrame(&cparams, &bits);

	sckVideo.SendVideo(cdata, cbyte);
	
	frame_count = 0;
}


void CProjServerDlg::PostStatus(char *string)
{
	//Post a message to status text box
	UpdateData();
	m_strStatus += string;
	m_strStatus += "\r\n";
	UpdateData(FALSE);
}

void CProjServerDlg::OnButton1()	//Abort Video button
{
	if (MyCap == NULL) return;

	MyCap->vStopCap();
	MyCap = NULL;
	sckData.SendData(D_ABORT);
	PostStatus("Video aborted locally.");	
}

void CProjServerDlg::OnExitBut() 
{
	//close sockets
	sckVideo.Close();
	sckData.Close();

	//if video capture is active, abort
	if (MyCap != NULL) OnButton1();

	//close serial port
	if (hComm != NULL)
	{
		CloseHandle(hComm);
		hComm = NULL;
	}

	PostQuitMessage(0);

}
