
#if !defined(AFX_IDCT_H__C5DE7F30_6033_11D6_889B_000B2B0F84B6__INCLUDED_)
#define AFX_IDCT_H__C5DE7F30_6033_11D6_889B_000B2B0F84B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DGlobal.h"

#define W1 2841 /* 2048*sqrt(2)*cos(1*pi/16) */
#define W2 2676 /* 2048*sqrt(2)*cos(2*pi/16) */
#define W3 2408 /* 2048*sqrt(2)*cos(3*pi/16) */
#define W5 1609 /* 2048*sqrt(2)*cos(5*pi/16) */
#define W6 1108 /* 2048*sqrt(2)*cos(6*pi/16) */
#define W7 565  /* 2048*sqrt(2)*cos(7*pi/16) */

/* global declarations */
void init_idct ();
void idct (short *block);

/* private data */
static short iclip[1024]; /* clipping table */
static short *iclp;

/* private prototypes */
static void idctrow(short *blk);
static void idctcol(short *blk);

#endif // !defined(AFX_IDCT_H__C5DE7F30_6033_11D6_889B_000B2B0F84B6__INCLUDED_)
