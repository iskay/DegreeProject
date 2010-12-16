#if !defined(AFX_MYSOCKET_H__878F436C_CB8A_11DB_A27A_00045A62F712__INCLUDED_)
#define AFX_MYSOCKET_H__878F436C_CB8A_11DB_A27A_00045A62F712__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MySocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// MySocket command target

class CProjClientDlg;

class MySocket : public CSocket
{
// Attributes
public:
	sockaddr_in D_localAddr, D_remoteAddr;
	sockaddr_in V_localAddr, V_remoteAddr;
	static unsigned char buffer[2048];
	static unsigned int buflength;
	CProjClientDlg *parent;
	int sckPort;

// Operations
public:
	MySocket();
	virtual ~MySocket();

	void OpenDataSocket(CProjClientDlg *dlg);
	void OpenVideoSocket(CProjClientDlg *dlg);
	void SendData(int data);

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MySocket)
	public:
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(MySocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSOCKET_H__878F436C_CB8A_11DB_A27A_00045A62F712__INCLUDED_)
