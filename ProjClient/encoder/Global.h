#if !defined(AFX_GLOBAL_H__8D36A381_5D0B_11D6_889B_000B2B0F84B6__INCLUDED_)
#define AFX_GLOBAL_H__8D36A381_5D0B_11D6_889B_000B2B0F84B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "def.h"
#include "struct.h"


typedef void (*WriteByte) (int);

// Global variable 
extern WriteByte WriteByteFunction;


class Global  
{
public:
	
static int headerlength; /* Global variables */
static int pels;
static int cpels;
static int uskip;
static int vskip;
static size_t sizeof_frame;
static int lines;
static int trace;
static int advanced;
static int pb_frames;
static int mv_outside_frame;
static int long_vectors;
static int mbr;
static int mbc;

static float target_framerate;
static FILE *tf;

//#ifdef PRINT_DEBUG
//static FILE *debugf;
//#endif


static int search_p_frames;		/* internal variable for exh/log search */
static FILE *mv_file;



static  Pict *pic;
	
	

};

#endif // !defined(AFX_GLOBAL_H__8D36A381_5D0B_11D6_889B_000B2B0F84B6__INCLUDED_)
