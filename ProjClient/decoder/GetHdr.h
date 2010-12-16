#if !defined(AFX_GETHDR_H__C5DE7F26_6033_11D6_889B_000B2B0F84B6__INCLUDED_)
#define AFX_GETHDR_H__C5DE7F26_6033_11D6_889B_000B2B0F84B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "DGlobal.h"
#include "GetBits.h"


int getheader ();
void startcode ();
void storeframe (unsigned char *src[], int frame);

static void getpicturehdr ();


#endif // !defined(AFX_GETHDR_H__C5DE7F26_6033_11D6_889B_000B2B0F84B6__INCLUDED_)
