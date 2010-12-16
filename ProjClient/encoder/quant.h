#if !defined _QUANT_H
#define _QUANT_H

#include "Global.h"


void Dequant(int *qcoeff, int *rcoeff, int QP, int I);
int QuantAndFindCBP(int *coeff, int *qcoeff, int QP, int I, int CBP_Mask);




#endif
