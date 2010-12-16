#if !defined(AFX_GETPIC_H__C5DE7F28_6033_11D6_889B_000B2B0F84B6__INCLUDED_)
#define AFX_GETPIC_H__C5DE7F28_6033_11D6_889B_000B2B0F84B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DGlobal.h"
#include "Indices.h"
#include "Sactbls.h"
#include "GetBlk.h"
#include "GetVlc.h"
#include "Idctref.h"
#include "Idct.h"

/* public */
void getpicture (int *framenum);
void putlast (int framenum);



/* private */

static void getMBs (int framenum);
static void clearblock (int comp);
static int motion_decode (int vec,int pmv);
static int find_pmv (int x, int y, int block, int comp);
static void addblock (int comp, int bx, int by,int addflag);
static void reconblock_b (int comp,int bx,int by,int mode,int bdx, int bdy);
static void find_bidir_limits (int vec, int *start, int*stop, int nhv);
static void find_bidir_chroma_limits (int vec, int *start, int*stop);
static void make_edge_image  (unsigned char *src, unsigned char *dst, int width, int height, int edge);
void interpolate_image (unsigned char *in, unsigned char *out, int width, int height);


#endif // !defined(AFX_GETPIC_H__C5DE7F28_6033_11D6_889B_000B2B0F84B6__INCLUDED_)
