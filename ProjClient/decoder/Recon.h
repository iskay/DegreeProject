#if !defined(AFX_RECON_H__C5DE7F2C_6033_11D6_889B_000B2B0F84B6__INCLUDED_)
#define AFX_RECON_H__C5DE7F2C_6033_11D6_889B_000B2B0F84B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DGlobal.h"

/* private prototypes */
static void recon_comp (unsigned char *src, unsigned char *dst,int lx, int lx2, int w, int h, int x, int y, int dx, int dy, int flag);
static void recon_comp_obmc (unsigned char *src, unsigned char *dst,int lx,int lx2,int comp,int w,int h,int x,int y);
static void rec (unsigned char *s, unsigned char *d, int lx, int lx2, int h);
static void recc (unsigned char *s, unsigned char *d, int lx, int lx2, int h);
static void reco (unsigned char *s, int *d, int lx, int lx2, int addflag,int c, int xa, int xb, int ya, int yb);
static void rech (unsigned char *s, unsigned char *d, int lx, int lx2, int h);
static void rechc (unsigned char *s, unsigned char *d, int lx, int lx2, int h);
static void recho (unsigned char *s, int *d, int lx, int lx2, int addflag,int c, int xa, int xb, int ya, int yb);
static void recv (unsigned char *s, unsigned char *d, int lx, int lx2, int h);
static void recvc (unsigned char *s, unsigned char *d, int lx, int lx2, int h);
static void recvo (unsigned char *s, int *d, int lx, int lx2, int addflag,int c, int xa, int xb, int ya, int yb);
static void rec4 (unsigned char *s, unsigned char *d, int lx, int lx2, int h);
static void rec4c (unsigned char *s, unsigned char *d, int lx, int lx2, int h);
static void rec4o (unsigned char *s, int *d, int lx, int lx2, int addflag,int c, int xa, int xb, int ya, int yb);


#endif // !defined(AFX_RECON_H__C5DE7F2C_6033_11D6_889B_000B2B0F84B6__INCLUDED_)
