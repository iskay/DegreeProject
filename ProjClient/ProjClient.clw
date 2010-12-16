; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CProjClientDlg
LastTemplate=CSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ProjClient.h"

ClassCount=4
Class1=CProjClientApp
Class2=CProjClientDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_PROJCLIENT_DIALOG
Resource4=IDD_ABOUTBOX (English (U.S.))
Class4=MySocket
Resource5=IDD_PROJCLIENT_DIALOG (English (U.S.))

[CLS:CProjClientApp]
Type=0
HeaderFile=ProjClient.h
ImplementationFile=ProjClient.cpp
Filter=N

[CLS:CProjClientDlg]
Type=0
HeaderFile=ProjClientDlg.h
ImplementationFile=ProjClientDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_REMOTE

[CLS:CAboutDlg]
Type=0
HeaderFile=ProjClientDlg.h
ImplementationFile=ProjClientDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg


[DLG:IDD_PROJCLIENT_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CProjClientDlg

[DLG:IDD_PROJCLIENT_DIALOG (English (U.S.))]
Type=1
Class=CProjClientDlg
ControlCount=11
Control1=IDOK,button,1073807361
Control2=IDCANCEL,button,1342242816
Control3=IDC_REMOTE,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_CONNECT,button,1342242816
Control6=IDC_DISCONNECT,button,1342242816
Control7=IDC_LEFT,button,1342242816
Control8=IDC_RIGHT,button,1342242816
Control9=IDC_STATUSBOX,edit,1352730820
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342177287

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

