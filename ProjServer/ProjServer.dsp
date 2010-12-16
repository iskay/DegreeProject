# Microsoft Developer Studio Project File - Name="ProjServer" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=ProjServer - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ProjServer.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ProjServer.mak" CFG="ProjServer - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ProjServer - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "ProjServer - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ProjServer - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x1009 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x1009 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 vfw32.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "ProjServer - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x1009 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x1009 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 vfw32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "ProjServer - Win32 Release"
# Name "ProjServer - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\CapObj.cpp
# End Source File
# Begin Source File

SOURCE=.\MySocket.cpp
# End Source File
# Begin Source File

SOURCE=.\ProjServer.cpp
# End Source File
# Begin Source File

SOURCE=.\ProjServer.rc
# End Source File
# Begin Source File

SOURCE=.\ProjServerDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Serial.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\CapObj.h
# End Source File
# Begin Source File

SOURCE=.\Globals.h
# End Source File
# Begin Source File

SOURCE=.\MySocket.h
# End Source File
# Begin Source File

SOURCE=.\ProjServer.h
# End Source File
# Begin Source File

SOURCE=.\ProjServerDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\Serial.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\ProjServer.ico
# End Source File
# Begin Source File

SOURCE=.\res\ProjServer.rc2
# End Source File
# End Group
# Begin Group "encoder"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\encoder\coder.cpp
# End Source File
# Begin Source File

SOURCE=.\encoder\coder.h
# End Source File
# Begin Source File

SOURCE=.\encoder\config.h
# End Source File
# Begin Source File

SOURCE=.\encoder\countbit.cpp
# End Source File
# Begin Source File

SOURCE=.\encoder\countbit.h
# End Source File
# Begin Source File

SOURCE=.\encoder\ctables.h
# End Source File
# Begin Source File

SOURCE=.\encoder\dct.cpp
# End Source File
# Begin Source File

SOURCE=.\encoder\dct.h
# End Source File
# Begin Source File

SOURCE=.\encoder\def.h
# End Source File
# Begin Source File

SOURCE=.\encoder\Global.cpp
# End Source File
# Begin Source File

SOURCE=.\encoder\Global.h
# End Source File
# Begin Source File

SOURCE=.\encoder\huffman.cpp
# End Source File
# Begin Source File

SOURCE=.\encoder\huffman.h
# End Source File
# Begin Source File

SOURCE=.\encoder\libr263.cpp
# End Source File
# Begin Source File

SOURCE=.\encoder\libr263.h
# End Source File
# Begin Source File

SOURCE=.\encoder\mot_est.cpp
# End Source File
# Begin Source File

SOURCE=.\encoder\mot_est.h
# End Source File
# Begin Source File

SOURCE=.\encoder\owntypes.h
# End Source File
# Begin Source File

SOURCE=.\encoder\pred.cpp
# End Source File
# Begin Source File

SOURCE=.\encoder\pred.h
# End Source File
# Begin Source File

SOURCE=.\encoder\quant.cpp
# End Source File
# Begin Source File

SOURCE=.\encoder\quant.h
# End Source File
# Begin Source File

SOURCE=.\encoder\rlib.cpp
# End Source File
# Begin Source File

SOURCE=.\encoder\rlib.h
# End Source File
# Begin Source File

SOURCE=.\encoder\stream.cpp
# End Source File
# Begin Source File

SOURCE=.\encoder\stream.h
# End Source File
# Begin Source File

SOURCE=.\encoder\struct.h
# End Source File
# End Group
# Begin Group "decoder"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\decoder\convert.cpp
# End Source File
# Begin Source File

SOURCE=.\decoder\convert.h
# End Source File
# Begin Source File

SOURCE=.\decoder\decdef.h
# End Source File
# Begin Source File

SOURCE=.\decoder\decstruct.h
# End Source File
# Begin Source File

SOURCE=.\decoder\DGlobal.cpp
# End Source File
# Begin Source File

SOURCE=.\decoder\DGlobal.h
# End Source File
# Begin Source File

SOURCE=.\decoder\GetBits.cpp
# End Source File
# Begin Source File

SOURCE=.\decoder\GetBits.h
# End Source File
# Begin Source File

SOURCE=.\decoder\GetBlk.cpp
# End Source File
# Begin Source File

SOURCE=.\decoder\GetBlk.h
# End Source File
# Begin Source File

SOURCE=.\decoder\GetHdr.cpp
# End Source File
# Begin Source File

SOURCE=.\decoder\GetHdr.h
# End Source File
# Begin Source File

SOURCE=.\decoder\GetPic.cpp
# End Source File
# Begin Source File

SOURCE=.\decoder\GetPic.h
# End Source File
# Begin Source File

SOURCE=.\decoder\GetVlc.cpp
# End Source File
# Begin Source File

SOURCE=.\decoder\GetVlc.h
# End Source File
# Begin Source File

SOURCE=.\decoder\Idct.cpp
# End Source File
# Begin Source File

SOURCE=.\decoder\Idct.h
# End Source File
# Begin Source File

SOURCE=.\decoder\Idctref.cpp
# End Source File
# Begin Source File

SOURCE=.\decoder\Idctref.h
# End Source File
# Begin Source File

SOURCE=.\decoder\Indices.cpp
# End Source File
# Begin Source File

SOURCE=.\decoder\Indices.h
# End Source File
# Begin Source File

SOURCE=.\decoder\main.cpp
# End Source File
# Begin Source File

SOURCE=.\decoder\Recon.cpp
# End Source File
# Begin Source File

SOURCE=.\decoder\Recon.h
# End Source File
# Begin Source File

SOURCE=.\decoder\Sac.cpp
# End Source File
# Begin Source File

SOURCE=.\decoder\Sac.h
# End Source File
# Begin Source File

SOURCE=.\decoder\Sactbls.cpp
# End Source File
# Begin Source File

SOURCE=.\decoder\Sactbls.h
# End Source File
# Begin Source File

SOURCE=.\decoder\Tmndec.cpp
# End Source File
# Begin Source File

SOURCE=.\decoder\Tmndec.h
# End Source File
# Begin Source File

SOURCE=.\decoder\YuvToRgb.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
