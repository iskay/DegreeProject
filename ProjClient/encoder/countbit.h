#if !defined _COUNTBIT_H
#define _COUNTBIT_H


#include "Global.h"
#include"huffman.h"
//#include"indices.h"


void ZeroBits(Bits *bits);
void ZeroRes(Results *res);
int FindCBP(int *qcoeff, int Mode, int ncoeffs);
void CountBitsVectors(MotionVector *MV_ptr, Bits *bits, 
		      int x, int y, int Mode, int newgob, Pict *pic);
void FindPMV(MotionVector *MV_ptr, int x, int y, 
	     int *p0, int *p1, int block, int newgob, int half_pel);
void CountBitsCoeff(int *qcoeff, int I, int CBP, Bits *bits, int ncoeffs);
int CodeCoeff(int Mode, int *qcoeff, int block, int ncoeffs);
int CountBitsPicture(Pict *pic);
void AddBitsPicture(Bits *bits);
void CountBitsMB(int Mode, int COD, int CBP, int CBPB, Pict *pic, Bits *bits);
int CountBitsSlice(int slice, int quant);
void ZeroVec(MotionVector *MV);
void MarkVec(MotionVector *MV);
void CopyVec(MotionVector *MV1, MotionVector *MV2);
int EqualVec(MotionVector *MV2, MotionVector *MV1);


#endif
