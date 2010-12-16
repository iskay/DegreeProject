#if !defined _DCT_H
#define _DCT_H

#include "Global.h"


/* dct.c prototypes */
int Dct( int *block, int *coeff);
int idct(int *coeff,int *block);



#endif
