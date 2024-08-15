; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CHost2
LastTemplate=CCmdTarget
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ScriptDemo.h"

ClassCount=5
Class1=CScriptDemoApp
Class2=CScriptDemoDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CHost
Class5=CHost2
Resource3=IDD_SCRIPTDEMO_DIALOG

[CLS:CScriptDemoApp]
Type=0
HeaderFile=ScriptDemo.h
ImplementationFile=ScriptDemo.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC
LastObject=CScriptDemoApp

[CLS:CScriptDemoDlg]
Type=0
HeaderFile=ScriptDemoDlg.h
ImplementationFile=ScriptDemoDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CScriptDemoDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=ScriptDemoDlg.h
ImplementationFile=ScriptDemoDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_HOMESITE

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=7
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_HOMESITE,static,1342308352
Control6=IDC_STATIC,static,1342312448
Control7=IDC_STATIC,static,1342308352

[DLG:IDD_SCRIPTDEMO_DIALOG]
Type=1
Class=CScriptDemoDlg
ControlCount=19
Control1=IDC_STATIC,static,1342308352
Control2=IDC_TXT_FILENAME,edit,1342242944
Control3=IDC_BTN_BROWSE,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_CMB_LANGUAGE,combobox,1344339971
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342177296
Control8=IDC_TXT_SCRIPT,edit,1345392836
Control9=IDC_BTN_ADDCODE,button,1342242816
Control10=IDC_STATIC,static,1342308352
Control11=IDC_CMB_FUNCTIONS,combobox,1344340226
Control12=IDC_BTN_EXECUTE,button,1342242816
Control13=IDC_STATIC,static,1342308352
Control14=IDC_TXT_PARAMETER,edit,1342242944
Control15=IDC_STATIC,static,1342308352
Control16=IDC_TXT_RESULT,edit,1342244996
Control17=IDOK,button,1342242817
Control18=IDC_SWITCH,button,1342251008
Control19=IDC_ABOUT,button,1342242816

[CLS:CHost]
Type=0
HeaderFile=Host.h
ImplementationFile=Host.cpp
BaseClass=CCmdTarget
Filter=N

[CLS:CHost2]
Type=0
HeaderFile=Host2.h
ImplementationFile=Host2.cpp
BaseClass=CCmdTarget
Filter=N
LastObject=CHost2
VirtualFilter=C

