#include "Stdafx.h"
#include "ProjServer.h"
#include "ProjServerDlg.h"
#include "CapObj.h"
#include "Globals.h"
#include <vfw.h>


CapObj::CapObj()
{
	vWndParent = NULL;
	vWndCap = NULL;
}


int CapObj::vInit(CDialog *parent)
{

	vWndParent = parent;
	vWndCap = capCreateCaptureWindow("Capture",WS_POPUP,0,0,1,1,0,0);

	//if error setting up capture
	if(vWndCap==NULL) return 0;	

	capSetUserData(vWndCap,this);

	//callback for when a frame is ready
    capSetCallbackOnVideoStream(vWndCap,OnCaptureVideo);
 
	//connect to webcam driver
	if(!capDriverConnect(vWndCap,0)) return 0;

	//set the capture parameters
	CAPTUREPARMS CapParms={0};	
	capCaptureGetSetup(vWndCap,&CapParms,sizeof(CapParms));

	CapParms.fAbortLeftMouse = FALSE;
	CapParms.fAbortRightMouse = FALSE;
	CapParms.fYield = TRUE;
	CapParms.fCaptureAudio = FALSE;
	CapParms.wPercentDropForError = 50;	//error when 50% frame drop

	if(!capCaptureSetSetup(vWndCap,&CapParms,sizeof(CapParms)))
		return 0;

	capGetVideoFormat(vWndCap,&m_bmpinfo,sizeof(m_bmpinfo));

	m_bmpinfo.bmiHeader.biWidth=IMAGE_WIDTH;
	m_bmpinfo.bmiHeader.biHeight=IMAGE_HEIGHT;

	if(!capSetVideoFormat(vWndCap,&m_bmpinfo,sizeof(m_bmpinfo)))
		return 0;

	return 1;
}


int CapObj::vStartCap()
{
	//don't capture to file
	if(capCaptureSequenceNoFile(vWndCap)==FALSE) return 0;
	return 1;
}


void CapObj::vStopCap()
{
	capCaptureAbort(vWndCap);

	//clear callback
	capSetCallbackOnVideoStream(vWndCap, NULL);

	Sleep(500);
	
	capDriverDisconnect(vWndCap);
	DestroyWindow(vWndCap);

}


LRESULT CALLBACK OnCaptureVideo(HWND mwnd,LPVIDEOHDR lphdr)
{

	CapObj *temp=(CapObj *)capGetUserData(mwnd);

	if(temp!=NULL )
	{
		((CProjServerDlg*) (temp->vWndParent))->SendFrame(lphdr->lpData,lphdr->dwBytesUsed);
	}

	return TRUE;

}


