#if !defined _CODER_H
#define _CODER_H

#include "Global.h"


void ZeroMBlock(MB_Structure *data);
void CodeIntraH263(CParam *params, Bits *bits);
void CodeInterH263(CParam *params, Bits *bits);
//__inline__ void Clip(MB_Structure *data);
void Clip(MB_Structure *data);

int *MB_EncodeAndFindCBP(MB_Structure *mb_orig, int QP, int I, int *CBP);
int MB_Decode(int *qcoeff, MB_Structure *mb_recon, int QP, int I);
void FullMotionEstimatePicture(unsigned int *curr, unsigned int *prev, 
			       unsigned int *prev_ipol, int seek_dist, 
			       MotionVector *MV_ptr,
			       int advanced_method,
			       int *EncodeThisBlock);
void ReconCopyImage(int i, int j, unsigned int *recon, unsigned int *prev_recon);
void ReconImage (int i, int j, MB_Structure *data, unsigned int *recon);
void InterpolateImage(unsigned int *image,
			       unsigned int *ipol_image, 
			       int w, int h);
void FillLumBlock( int x, int y, unsigned int *image, MB_Structure *data);
void FillChromBlock(int x_curr, int y_curr, unsigned int *image,
		    MB_Structure *data);

#endif
