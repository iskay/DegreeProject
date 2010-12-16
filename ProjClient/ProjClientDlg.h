// ProjClientDlg.h : header file
//

#if !defined(AFX_PROJCLIENTDLG_H__878F4354_CB8A_11DB_A27A_00045A62F712__INCLUDED_)
#define AFX_PROJCLIENTDLG_H__878F4354_CB8A_11DB_A27A_00045A62F712__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CProjClientDlg dialog
#include "MySocket.h"
#include "Encoder/libr263.h"
#include "Decoder/tmndec.h"
#include <vfw.h>

class CProjClientDlg : public CDialog
{
// Construction
public:
	CProjClientDlg(CWnd* pParent = NULL);	// standard constructor

	void PostStatus(char *string);
	void ProcessConfirm();
	void ProcessAbort();
	void CProjClientDlg::DisplayFrame(BYTE *data,int size);

	MySocket sckData, sckVideo;
	PBITMAPINFO m_bmpinfo;
	HDC m_hdc;
	HWND hwnd;
	HDRAWDIB hdib;

// Dialog Data
	//{{AFX_DATA(CProjClientDlg)
	enum { IDD = IDD_PROJCLIENT_DIALOG };
	CString	m_strStatus;
	CString	m_strRemote;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProjClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CProjClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnConnectBut();
	afx_msg void OnDisconnectBut();
	afx_msg void OnLeftBut();
	afx_msg void OnRightBut();
	afx_msg void OnExitBut();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROJCLIENTDLG_H__878F4354_CB8A_11DB_A27A_00045A62F712__INCLUDED_)
