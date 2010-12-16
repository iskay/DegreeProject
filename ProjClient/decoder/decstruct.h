#if !defined DEC_STRUCT_H
#define DEC_STRUCT_H


 struct ld 
 {
  
  /* bit input */
  unsigned char rdbfr[2051];
  unsigned char *rdptr;
  unsigned char inbfr[16];
  int incnt;
  int bitcnt;
  
  /* block data */
  short block[12][64];

 };


typedef struct 
{
  int val, len;
} VLCtab;

typedef struct 
{
  char run, level, len;
} DCTtab;


typedef struct 
{
  int val, len;
} VLCtabI;


typedef struct 
{
  int val, run, sign;
} RunCoef;


#endif
