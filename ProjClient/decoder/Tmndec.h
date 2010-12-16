/************************************************************************
 *
 *  tmndec.h, TMN specific defines for tmndecode (H.263 decoder)
 *  Copyright (C) 1996  Telenor R&D, Norway
 *        Karl Olav Lillevold <Karl.Lillevold@nta.no>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *  Karl Olav Lillevold               <Karl.Lillevold@nta.no>
 *  Telenor Research and Development
 *  P.O.Box 83                        tel.:   +47 63 84 84 00
 *  N-2007 Kjeller, Norway            fax.:   +47 63 81 00 76
 *
 *  Robert Danielsen                  e-mail: Robert.Danielsen@nta.no
 *  Telenor Research and Development  www:    http://www.nta.no/brukere/DVC/
 *  P.O.Box 83                        tel.:   +47 63 84 84 00
 *  N-2007 Kjeller, Norway            fax.:   +47 63 81 00 76
 *  
 ************************************************************************/

/*
 * based on mpeg2decode, (C) 1994, MPEG Software Simulation Group
 * and mpeg2play, (C) 1994 Stefan Eckart
 *                         <stefan@lis.e-technik.tu-muenchen.de>
 *
 */


#if !defined(AFX_TMNDEC_H__C5DE7F23_6033_11D6_889B_000B2B0F84B6__INCLUDED_)
#define AFX_TMNDEC_H__C5DE7F23_6033_11D6_889B_000B2B0F84B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



//#define GLOBAL

#include "DGlobal.h"
#include "GetBits.h"
#include "GetPic.h"
#include "GetHdr.h"
#include "convert.h"



void error (char *text);
void printbits (int code, int bits, int len);


/* private prototypes */
void InitH263Decoder();
int DecompressFrame(unsigned char *cdata,int size,unsigned char *outdata,int outsize);
void ExitH263Decoder();
static void initdecoder();


#endif // !defined(AFX_TMNDEC_H__C5DE7F23_6033_11D6_889B_000B2B0F84B6__INCLUDED_)
