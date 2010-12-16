// MySocket.cpp : implementation file
//

#include "stdafx.h"
#include "ProjClient.h"
#include "ProjClientDlg.h"
#include "MySocket.h"
#include "Globals.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// MySocket

unsigned char MySocket::buffer[2048];
unsigned int MySocket::buflength=2048;


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
	int n;
	
	if (sckPort==DATA_PORT_C)
	{
		n=sizeof(D_remoteAddr);
		retvalue=ReceiveFrom(buffer, buflength,
			(struct sockaddr *)&D_remoteAddr, &n, 0);

		switch(buffer[0])
		{
			
			case D_CONFIRM:
			parent->ProcessConfirm();
			return;

			case D_ABORT:
			parent->ProcessAbort();
			return;

			default:
			return;
		}
	}
	
	if (sckPort==VIDEO_PORT_C)
	{
		n=sizeof(V_remoteAddr);
		retvalue=ReceiveFrom(buffer, buflength,
			(struct sockaddr *)&V_remoteAddr, &n, 0);
		
		parent->DisplayFrame(buffer,retvalue);
	}
}

void MySocket::OpenDataSocket(CProjClientDlg *dlg)
{
	parent=dlg;

	D_remoteAddr.sin_family = AF_INET;
	D_remoteAddr.sin_port = htons(DATA_PORT_S);
	D_remoteAddr.sin_addr.s_addr = inet_addr(parent->m_strRemote);

	Create(DATA_PORT_C, SOCK_DGRAM, NULL);
	sckPort=DATA_PORT_C;

}


void MySocket::OpenVideoSocket(CProjClientDlg *dlg)
{
	parent=dlg;

	V_remoteAddr.sin_family = AF_INET;
	V_remoteAddr.sin_port = htons(VIDEO_PORT_S);
	V_remoteAddr.sin_addr.s_addr = D_remoteAddr.sin_addr.s_addr;

	Create(VIDEO_PORT_C, SOCK_DGRAM, NULL);
//	Create(VIDEO_PORT_C, SOCK_DGRAM, "127.0.0.1");
	sckPort=VIDEO_PORT_C;
}


void MySocket::SendData(int data)
{
	char temp[5];
	temp[0]=data;				
	
	SendTo(temp, 1, (struct sockaddr *)&D_remoteAddr,
		sizeof(D_remoteAddr), 0);
//	SendTo(temp, 1, DATA_PORT, "127.0.0.1", 0);
}
