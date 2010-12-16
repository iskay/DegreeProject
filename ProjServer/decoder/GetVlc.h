#if !defined(AFX_GETVLC_H__C5DE7F29_6033_11D6_889B_000B2B0F84B6__INCLUDED_)
#define AFX_GETVLC_H__C5DE7F29_6033_11D6_889B_000B2B0F84B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DGlobal.h"
#include "GetBits.h"
#include "TmnDec.h"



int getTMNMV ();
int getMCBPC ();
int getMODB ();
int getMCBPCintra ();
int getCBPY ();




extern VLCtab TMNMVtab0[];

extern VLCtab TMNMVtab1[];
extern VLCtab TMNMVtab2[];

extern VLCtab MCBPCtab[];

extern VLCtab MCBPCtabintra[];

extern VLCtab CBPYtab[48];

#endif // !defined(AFX_GETVLC_H__C5DE7F29_6033_11D6_889B_000B2B0F84B6__INCLUDED_)
