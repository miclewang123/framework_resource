; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTrackerView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Tracker.h"
LastPage=0

ClassCount=5
Class1=CTrackerApp
Class2=CTrackerDoc
Class3=CTrackerView
Class4=CMainFrame

ResourceCount=2
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX

[CLS:CTrackerApp]
Type=0
HeaderFile=Tracker.h
ImplementationFile=Tracker.cpp
Filter=N

[CLS:CTrackerDoc]
Type=0
HeaderFile=TrackerDoc.h
ImplementationFile=TrackerDoc.cpp
Filter=N
LastObject=ID_HOWTO
BaseClass=CDocument
VirtualFilter=DC

[CLS:CTrackerView]
Type=0
HeaderFile=TrackerView.h
ImplementationFile=TrackerView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CTrackerView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=Tracker.cpp
ImplementationFile=Tracker.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_APP_EXIT
Command6=ID_CLEAR
Command7=ID_APP_ABOUT
Command8=ID_HOWTO
CommandCount=8

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

