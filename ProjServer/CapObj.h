#ifndef _CAPOBJ_H
#define _CAPOBJ_H

#include<vfw.h>


class CapObj 
{
public:
	
	HWND vWndCap;
	CDialog *vWndParent;
	BITMAPINFOHEADER m_bmpheader;
	BITMAPINFO m_bmpinfo;

	CapObj();
	int vInit(CDialog *parent);
	void vStopCap();
	int vStartCap();

	//Callback
    friend LRESULT CALLBACK OnCaptureVideo(HWND hWnd, LPVIDEOHDR lpheader) ;


};


#endif