// Definition of all constants......

#if !defined DEC_DEF_H
#define DEC_DEF_H


#define PSC        1
#define PSC_LENGTH        17
#define SE_CODE                         31

#define MODE_INTER                      0
#define MODE_INTER_Q                    1
#define MODE_INTER4V                    2
#define MODE_INTRA                      3
#define MODE_INTRA_Q                    4

#define PBMODE_NORMAL                   0
#define PBMODE_MVDB                     1
#define PBMODE_CBPB_MVDB                2

#define ESCAPE                          7167
#define ESCAPE_INDEX                    102

#define PCT_INTER                       1
#define PCT_INTRA                       0
#define ON                              1
#define OFF                             0

// Source Format 
#define SF_SQCIF                        1  /* 001 */
#define SF_QCIF                         2  /* 010 */
#define SF_CIF                          3  /* 011 */
#define SF_4CIF                         4  /* 100 */
#define SF_16CIF                        5  /* 101 */


/* this is necessary for the max resolution 16CIF */
#define MBC                             88
#define MBR                             72

#define NO_VEC                          999



/* Some macros */
#define mmax(a, b)        ((a) > (b) ? (a) : (b))
#define mmin(a, b)        ((a) < (b) ? (a) : (b))
#define mnint(a)        ((a) < 0 ? (int)(a - 0.5) : (int)(a + 0.5))
#define sign(a)         ((a) < 0 ? -1 : 1)


// Output types
#define T_YUV      0
#define T_SIF      1
#define T_TGA      2
#define T_PPM      3
#define T_X11      4
#define T_YUV_CONC 5
#define T_WIN      6


#endif
