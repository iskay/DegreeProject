#if !defined _MOT_EST_H
#define _MOT_EST_H


#include "Global.h"


void FindMB(int x, int y, unsigned int *image, unsigned int MB[16][16]);
void FullMotionEstimation(unsigned int *curr, unsigned int *prev_ipol, 
		     int seek_dist, MotionVector *current_MV, int x_curr, 
		     int y_curr);

int SAD_HalfPixelMacroblock(unsigned int *ii,
			    unsigned int *curr,
			    int pixels_on_line, int Min_SAD);

int SAD_HalfPixelMacroblock2(unsigned int *ii,
			    unsigned int *curr,
			    int pixels_on_line, int Min_SAD);
unsigned int *LoadArea(unsigned int *im, int x, int y, 
			int x_size, int y_size, int lx);


#endif
