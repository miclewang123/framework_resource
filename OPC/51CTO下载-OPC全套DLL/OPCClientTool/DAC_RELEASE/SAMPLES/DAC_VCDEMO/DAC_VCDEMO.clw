; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDAC_VCDEMODlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DAC_VCDEMO.h"

ClassCount=10
Class1=CDAC_VCDEMOApp
Class2=CDAC_VCDEMODlg
Class3=CAboutDlg

ResourceCount=12
Resource1=IDD_DIALOGBAR (English (U.S.))
Resource2=IDR_MAINFRAME
Resource3=IDD_ItemStatus
Resource4=IDD_ABOUTBOX
Resource5=IDD_ServerStatus
Class4=ItemBrowserDlg
Resource6=IDD_ItemWrite
Class5=ServerStatusDlg
Resource7=IDD_ServerBrowser
Class6=ItemStatusDlg
Resource8=IDD_ItemActive
Class7=ServerBrowserDlg
Resource9=IDD_GroupStatus
Class8=GroupStatusDlg
Resource10=IDD_DAC_VCDEMO_DIALOG
Class9=ItemActiveDlg
Resource11=IDD_ItemBrowser
Class10=ItemWriteDlg
Resource12=IDR_MENU1

[CLS:CDAC_VCDEMOApp]
Type=0
HeaderFile=DAC_VCDEMO.h
ImplementationFile=DAC_VCDEMO.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC
LastObject=CDAC_VCDEMOApp

[CLS:CDAC_VCDEMODlg]
Type=0
HeaderFile=DAC_VCDEMODlg.h
ImplementationFile=DAC_VCDEMODlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CDAC_VCDEMODlg

[CLS:CAboutDlg]
Type=0
HeaderFile=DAC_VCDEMODlg.h
ImplementationFile=DAC_VCDEMODlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=6
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

[DLG:IDD_DAC_VCDEMO_DIALOG]
Type=1
Class=CDAC_VCDEMODlg
ControlCount=1
Control1=IDC_LIST,SysListView32,1350565893

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_MENUExit
Command2=ID_MENUConnect
Command3=ID_MENUDisconnect
Command4=ID_MENUServerStatus
Command5=ID_MENUGroupStatus
Command6=ID_MENUGroupRefresh
Command7=ID_MENUItemAdd
Command8=ID_MENUItemRemove
Command9=ID_MENUItemRead
Command10=ID_MENUItemWrite
Command11=ID_MENUItemActive
Command12=ID_MENUItemStatus
Command13=ID_MENUAbout
CommandCount=13

[DLG:IDD_DIALOGBAR (English (U.S.))]
Type=1
Class=?
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_ServerBrowser]
Type=1
Class=ServerBrowserDlg
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDOK2,button,1342242816
Control3=IDRefresh,button,1342242816
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_EDIT2,edit,1350631552
Control6=IDC_EDIT3,edit,1350631552
Control7=IDC_LIST,listbox,1352663297
Control8=IDC_CHECK1,button,1342242819
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352

[DLG:IDD_ServerStatus]
Type=1
Class=ServerStatusDlg
ControlCount=19
Control1=IDOK,button,1342242817
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT2,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT3,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT4,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT5,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDIT6,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_EDIT7,edit,1350631552
Control15=IDC_STATIC,static,1342308352
Control16=IDC_EDIT8,edit,1350631552
Control17=IDC_STATIC,static,1342308352
Control18=IDC_EDIT9,edit,1350631552
Control19=IDC_STATIC,static,1342308352

[CLS:ServerStatusDlg]
Type=0
HeaderFile=ServerStatusDlg.h
ImplementationFile=ServerStatusDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT1
VirtualFilter=dWC

[DLG:IDD_ItemBrowser]
Type=1
Class=ItemBrowserDlg
ControlCount=10
Control1=IDAdd,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDRefresh,button,1342242816
Control4=IDC_TREE1,SysTreeView32,1350631463
Control5=IDC_EDIT1,edit,1350631552
Control6=IDC_EDIT2,edit,1350631552
Control7=IDC_LIST,listbox,1352728833
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352

[CLS:ItemBrowserDlg]
Type=0
HeaderFile=ItemBrowserDlg.h
ImplementationFile=ItemBrowserDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[CLS:ServerBrowserDlg]
Type=0
HeaderFile=ServerBrowserDlg.h
ImplementationFile=ServerBrowserDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_MENUAbout
VirtualFilter=dWC

[DLG:IDD_ItemStatus]
Type=1
Class=ItemStatusDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDRefresh,button,1342242816
Control3=IDC_LIST,SysListView32,1350631429

[CLS:ItemStatusDlg]
Type=0
HeaderFile=ItemStatusDlg.h
ImplementationFile=ItemStatusDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_MENUAbout
VirtualFilter=dWC

[DLG:IDD_GroupStatus]
Type=1
Class=GroupStatusDlg
ControlCount=15
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_EDIT2,edit,1350631552
Control5=IDC_EDIT3,edit,1350631552
Control6=IDC_EDIT4,edit,1350631552
Control7=IDC_CHECK,button,1342242819
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352

[CLS:GroupStatusDlg]
Type=0
HeaderFile=GroupStatusDlg.h
ImplementationFile=GroupStatusDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=GroupStatusDlg
VirtualFilter=dWC

[CLS:ItemActiveDlg]
Type=0
HeaderFile=ItemActiveDlg.h
ImplementationFile=ItemActiveDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_MENUAbout
VirtualFilter=dWC

[DLG:IDD_ItemActive]
Type=1
Class=ItemActiveDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_CHECK,button,1342242819
Control4=IDC_STATIC,static,1342308352

[DLG:IDD_ItemWrite]
Type=1
Class=ItemWriteDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_CHECK,button,1342242819
Control6=IDC_STATIC,static,1342308352

[CLS:ItemWriteDlg]
Type=0
HeaderFile=ItemWriteDlg.h
ImplementationFile=ItemWriteDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_MENUAbout
VirtualFilter=dWC

