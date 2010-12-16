// MySocket.cpp : implementation file
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
// MySocket

unsigned char MySocket::buffer[10];
unsigned int MySocket::buflength=10;

MySocket::MySocket()
{
}

MySocket::~MySocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(MySocket, CSocket)
	//{{AFX_MSG_MAP(MySocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// MySocket member functions

void MySocket::OnReceive(int nErrorCode) 
{
	unsigned int retvalue;
	int n=sizeof(D_remoteAddr);

//	retvalue=this->ReceiveFrom(buffer, buflength,
//		(struct sockaddr *)&D_remoteAddr, &n, 0);
		
	retvalue = ReceiveFrom(buffer, buflength,
		(struct sockaddr *)&D_remoteAddr, &n, 0);

	parent->str_remoteAddr=inet_ntoa(D_remoteAddr.sin_addr);
	
	switch(buffer[0])
	{
			
		case D_CONNECT:
		parent->ProcessConnect();
		return;

		case D_DISCONNECT:
		parent->ProcessDisconnect();
		return;

		case D_MOVELEFT:
		parent->ProcessMoveLeft();
		return;

		case D_MOVERIGHT:
		parent->ProcessMoveRight();
		return;

		default:
		return;
	}

}


void MySocket::OpenDataSocket(CProjServerDlg *dlg)
{
	parent=dlg;

	D_localAddr.sin_family = AF_INET;
	D_localAddr.sin_port = htons(DATA_PORT_S);
	D_localAddr.sin_addr.s_addr = htonl(INADDR_ANY);

//  Create(DATA_PORT, SOCK_DGRAM, "216.211.39.81"); //Bind(DATA_PORT, "127.0.0.1");
	Create(DATA_PORT_S, SOCK_DGRAM, NULL);
	Bind((struct sockaddr *)&D_localAddr, sizeof(D_localAddr));
//unsigned int tport;
//CString tname;

//GetSockName(tname, tport);

}


void MySocket::OpenVideoSocket(CProjServerDlg *dlg)
{
	parent=dlg;
//	CString temp;

//	temp=inet_ntoa(D_remoteAddr.sin_addr);
//	V_remoteAddr = D_remoteAddr;
	V_remoteAddr.sin_family = AF_INET;
	V_remoteAddr.sin_port = htons(VIDEO_PORT_C);
//	V_remoteAddr.sin_addr.s_addr = D_remoteAddr.sin_addr.s_addr;
//	V_remoteAddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	V_remoteAddr.sin_addr.s_addr = inet_addr(parent->str_remoteAddr);

	Create(VIDEO_PORT_S, SOCK_DGRAM, NULL);

}


void MySocket::SendData(int data)
{
	char temp[5];
	temp[0]=data;				
	
	SendTo(temp, 1, (struct sockaddr *)&D_remoteAddr,
		sizeof(D_remoteAddr), 0);
}


void MySocket::SendVideo(unsigned char *frame, int length)
{
	SendTo(frame, length, (struct sockaddr *)&V_remoteAddr,
		sizeof(V_remoteAddr), 0);

//	SendTo(frame, length, VIDEO_PORT_C, "127.0.0.1", 0);
}