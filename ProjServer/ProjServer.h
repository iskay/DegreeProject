// ProjServer.h : main header file for the PROJSERVER application
//

#if !defined(AFX_PROJSERVER_H__878F4344_CB8A_11DB_A27A_00045A62F712__INCLUDED_)
#define AFX_PROJSERVER_H__878F4344_CB8A_11DB_A27A_00045A62F712__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CProjServerApp:
// See ProjServer.cpp for the implementation of this class
//

class CProjServerApp : public CWinApp
{
public:
	CProjServerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProjServerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CProjServerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROJSERVER_H__878F4344_CB8A_11DB_A27A_00045A62F712__INCLUDED_)
