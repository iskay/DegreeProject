// ProjServerDlg.h : header file
//

#if !defined(AFX_PROJSERVERDLG_H__878F4346_CB8A_11DB_A27A_00045A62F712__INCLUDED_)
#define AFX_PROJSERVERDLG_H__878F4346_CB8A_11DB_A27A_00045A62F712__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CProjServerDlg dialog
#include "MySocket.h"
#include "CapObj.h"
#include "Encoder/libr263.h"
#include "Decoder/tmndec.h"
#include "Globals.h"


class CProjServerDlg : public CDialog
{
// Construction
public:
	CProjServerDlg(CWnd* pParent = NULL);	// standard constructor

	void PostStatus(char *string);
	void PrepareVideo();
	void SendFrame(BYTE *data,int size);
	void ProcessConnect();
	void ProcessDisconnect();
	void ProcessMoveRight();
	void ProcessMoveLeft();
	int PrepareSerialPort();

	MySocket sckData, sckVideo;		//data, video sockets
	CString str_remoteAddr;
	HANDLE hComm;					//handle to serial port
	COMMTIMEOUTS commTimeout;		//struct for serial port timeouts
	DCB dcb;						//struct for serial port settings
	CapObj *MyCap;
	CParam cparams;
	unsigned int yuv[IMAGE_WIDTH*IMAGE_HEIGHT+(IMAGE_WIDTH*IMAGE_HEIGHT)/2];

// Dialog Data
	//{{AFX_DATA(CProjServerDlg)
	enum { IDD = IDD_PROJSERVER_DIALOG };
	CString	m_strStatus;
	CString	m_strRemote;
	CString	m_strPort;
	BOOL	m_SerialEnabled;
	BOOL	m_VideoEnabled;
	int		m_FrameSkip;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProjServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CProjServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnExitBut();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROJSERVERDLG_H__878F4346_CB8A_11DB_A27A_00045A62F712__INCLUDED_)
