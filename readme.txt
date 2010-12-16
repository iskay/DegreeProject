*************************************
** Degree Project -- Client/Server **
**   Remote Surveillance System    **
**                                 **
**  by Ian Kay, ikay@lakeheadu.ca  **
**                                 **
*************************************

This software was written as part of my senior year project -- a motorized security camera and remote monitoring system. The finished project allowed a user to view the video feed stream using the client application and control the camera's viewing angle via commands that were relayed to the server, then through the comm port to an 8051 microcontroller and stepper motor.

The video capture is accomplished using the Compression of the video stream is handled using the VidCap component of the VideoForWindows framework, and the stream compression is handled using libr263, a free H.263 encoder library written by Roalt Aalmoes of Twente University <aalmoes@huygens.nl>.

This software was written using MFC and Visual C++ 6, and has not been tested with other compilers.