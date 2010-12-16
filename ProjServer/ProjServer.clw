; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CProjServerDlg
LastTemplate=CSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ProjServer.h"

ClassCount=4
Class1=CProjServerApp
Class2=CProjServerDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_PROJSERVER_DIALOG
Resource4=IDD_ABOUTBOX (English (U.S.))
Class4=MySocket
Resource5=IDD_PROJSERVER_DIALOG (English (U.S.))

[CLS:CProjServerApp]
Type=0
HeaderFile=ProjServer.h
ImplementationFile=ProjServer.cpp
Filter=N

[CLS:CProjServerDlg]
Type=0
HeaderFile=ProjServerDlg.h
ImplementationFile=ProjServerDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_PORT

[CLS:CAboutDlg]
Type=0
HeaderFile=ProjServerDlg.h
ImplementationFile=ProjServerDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg


[DLG:IDD_PROJSERVER_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CProjServerDlg

[DLG:IDD_PROJSERVER_DIALOG (English (U.S.))]
Type=1
Class=CProjServerDlg
ControlCount=13
Control1=IDOK,button,1073807361
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATUSBOX,edit,1352730820
Control4=IDC_REMOTE,edit,1350633600
Control5=IDC_STATIC,static,1342308352
Control6=IDC_BUTTON1,button,1342242816
Control7=IDC_STATIC,static,1342308352
Control8=IDC_PORT,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_CHECKVIDEO,button,1342242819
Control11=IDC_CHECKSERIAL,button,1342242819
Control12=IDC_STATIC,static,1342308352
Control13=IDC_FRAME_SKIP,edit,1350631552

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[CLS:MySocket]
Type=0
HeaderFile=MySocket.h
ImplementationFile=MySocket.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq
LastObject=MySocket

