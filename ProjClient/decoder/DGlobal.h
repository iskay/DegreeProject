// DGlobal.h: interface for the DGlobal class.

#if !defined(AFX_DGLOBAL_H__C5DE7F24_6033_11D6_889B_000B2B0F84B6__INCLUDED_)
#define AFX_DGLOBAL_H__C5DE7F24_6033_11D6_889B_000B2B0F84B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "decdef.h"
#include "decstruct.h"
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <math.h>




 

  extern int quiet;
  extern int trace;
  extern char errortext[256];
  extern unsigned char *refframe[3],*oldrefframe[3],*bframe[3],*newframe[3];
  extern unsigned char *edgeframe[3], *edgeframeorig[3], *exnewframe[3];
  extern int MV[2][5][MBR+1][MBC+2];
  extern int modemap[MBR+1][MBC+2];
  extern unsigned char *clp;
  extern int horizontal_size,vertical_size,mb_width,mb_height;
  extern int coded_picture_width, coded_picture_height;
  extern int chrom_width,chrom_height,blk_cnt;
  extern int pict_type,newgob;
  extern int mv_outside_frame,syntax_arith_coding,adv_pred_mode,pb_frame;
  extern int long_vectors;
  extern int fault,expand;
  extern int verbose;
  extern int refidct;
  extern int matrix_coefficients;
  extern int temp_ref, prev_temp_ref, quant, source_format;
  extern int framerate;
  extern unsigned char *cframe;
  extern int csize;
  extern int cindex;
  extern struct ld  base,*ld;
  extern unsigned char *yp,*up,*vp;

  extern FILE *dlog;
  
  
  #ifndef WIN32
  extern struct timeval tftarget;
  #else
  extern unsigned int targetTime;
  #endif


  extern int roundtab[16];
  
  //output
  extern int outtype;


  extern struct ld  base,*ld;


  extern int trd, trb, bscan, bquant;
  extern int bscan_tab[];
  extern int bquant_tab[];


  extern char version[200]; 

  
// zig-zag scan 
  extern unsigned char zig_zag_scan[64];
 

 // /*color space conversion coefficients
// *
// * entries are {crv,cbu,cgu,cgv}
// *
// * crv=(255/224)*65536*(1-cr)/0.5
// * cbu=(255/224)*65536*(1-cb)/0.5
// * cgu=(255/224)*65536*(cb/cg)*(1-cb)/0.5
// * cgv=(255/224)*65536*(cr/cg)*(1-cr)/0.5
// *
// * where Y=cr*R+cg*G+cb*B (cr+cg+cb=1)
// 

  extern int convmat[8][4];

  extern int OM[5][8][8];

  extern VLCtabI DCT3Dtab0[],DCT3Dtab1[],DCT3Dtab2[];



/// Function prototypes....

/* recon.c */
void reconstruct (int bx, int by, int P, int bdx, int bdy);


/* sac.c */
int decode_a_symbol (int cumul_freq[ ]);
void decoder_reset( );



void init_dither_tab();



#endif // !defined(AFX_DGLOBAL_H__C5DE7F24_6033_11D6_889B_000B2B0F84B6__INCLUDED_)
