#if !defined(AFX_GETBLK_H__C5DE7F27_6033_11D6_889B_000B2B0F84B6__INCLUDED_)
#define AFX_GETBLK_H__C5DE7F27_6033_11D6_889B_000B2B0F84B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DGlobal.h"
#include "GetBits.h"
#include "TmnDec.h"


//#define SACTABLES
#include "Sactbls.h"


/* local prototypes */
RunCoef vlc_word_decode (int symbol_word, int *last); 
RunCoef Decode_Escape_Char (int intra, int *last);
int DecodeTCoef (int position, int intra);

void getblock (int comp, int mode);
void get_sac_block (int comp, int mode);



#endif // !defined(AFX_GETBLK_H__C5DE7F27_6033_11D6_889B_000B2B0F84B6__INCLUDED_)
