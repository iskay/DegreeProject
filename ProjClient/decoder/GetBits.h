#if !defined(AFX_GETBITS_H__C5DE7F25_6033_11D6_889B_000B2B0F84B6__INCLUDED_)
#define AFX_GETBITS_H__C5DE7F25_6033_11D6_889B_000B2B0F84B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "DGlobal.h"


#ifdef WIN32
#include <io.h>
#endif


void initbits ();
void fillbfr ();
unsigned int showbits(int n);
unsigned int getbits1();
void flushbits (int n);
unsigned int getbits (int n);

#endif // !defined(AFX_GETBITS_H__C5DE7F25_6033_11D6_889B_000B2B0F84B6__INCLUDED_)
