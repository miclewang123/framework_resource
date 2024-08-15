VERSION 5.00
Begin VB.Form frmAbout 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "About..."
   ClientHeight    =   2670
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   5205
   ClipControls    =   0   'False
   Icon            =   "frmAbout.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   2670
   ScaleWidth      =   5205
   ShowInTaskbar   =   0   'False
   StartUpPosition =   1  'CenterOwner
   Begin VB.CommandButton cmdOK 
      Cancel          =   -1  'True
      Caption         =   "Done"
      Default         =   -1  'True
      Height          =   345
      Left            =   3360
      TabIndex        =   0
      Tag             =   "ȷ��"
      Top             =   2160
      Width           =   1467
   End
   Begin VB.CommandButton cmdSysInfo 
      Caption         =   "&System info..."
      Height          =   345
      Left            =   1800
      TabIndex        =   1
      Tag             =   "ϵͳ��Ϣ(&S)..."
      Top             =   2160
      Width           =   1452
   End
   Begin VB.Frame Frame1 
      Height          =   1935
      Left            =   240
      TabIndex        =   2
      Top             =   120
      Width           =   4695
      Begin VB.Label lblVersion 
         Caption         =   "VB��������"
         BeginProperty Font 
            Name            =   "����"
            Size            =   9
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   225
         Left            =   480
         TabIndex        =   6
         Tag             =   "�汾"
         Top             =   720
         Width           =   4095
      End
      Begin VB.Label lblTitle 
         Caption         =   "OPC ���ݷ��ʷ������ͻ��˿������߰�"
         BeginProperty Font 
            Name            =   "����"
            Size            =   9
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00000000&
         Height          =   240
         Left            =   480
         TabIndex        =   5
         Tag             =   "Ӧ�ó������"
         Top             =   360
         Width           =   3615
      End
      Begin VB.Label Label3 
         Caption         =   "http://www.agilewill.com"
         BeginProperty Font 
            Name            =   "����"
            Size            =   9
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00000000&
         Height          =   210
         Left            =   480
         TabIndex        =   4
         Tag             =   "Ӧ�ó�������"
         Top             =   1440
         Width           =   3735
      End
      Begin VB.Label lblDescription 
         Caption         =   "�������ݶ�����������޹�˾ 2005.11"
         BeginProperty Font 
            Name            =   "����"
            Size            =   9
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00000000&
         Height          =   285
         Left            =   480
         TabIndex        =   3
         Tag             =   "Ӧ�ó�������"
         Top             =   1080
         Width           =   3615
      End
   End
End
Attribute VB_Name = "frmAbout"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

' ע�����ȫѡ��...
Const KEY_ALL_ACCESS = &H2003F
                                          

' ע���������...
Const HKEY_LOCAL_MACHINE = &H80000002
Const ERROR_SUCCESS = 0
Const REG_SZ = 1                         ' Unicode �ս�β�ַ���
Const REG_DWORD = 4                      ' 32λ��


Const gREGKEYSYSINFOLOC = "SOFTWARE\Microsoft\Shared Tools Location"
Const gREGVALSYSINFOLOC = "MSINFO"
Const gREGKEYSYSINFO = "SOFTWARE\Microsoft\Shared Tools\MSINFO"
Const gREGVALSYSINFO = "PATH"


Private Declare Function RegOpenKeyEx Lib "advapi32" Alias "RegOpenKeyExA" (ByVal hKey As Long, ByVal lpSubKey As String, ByVal ulOptions As Long, ByVal samDesired As Long, ByRef phkResult As Long) As Long
Private Declare Function RegQueryValueEx Lib "advapi32" Alias "RegQueryValueExA" (ByVal hKey As Long, ByVal lpValueName As String, ByVal lpReserved As Long, ByRef lpType As Long, ByVal lpData As String, ByRef lpcbData As Long) As Long
Private Declare Function RegCloseKey Lib "advapi32" (ByVal hKey As Long) As Long

Private Sub Form_Load()
    lblVersion.Caption = "Version " & App.Major & "." & App.Minor & "." & App.Revision
    lblTitle.Caption = App.Title
End Sub



Private Sub cmdSysInfo_Click()
        Call StartSysInfo
End Sub


Private Sub cmdOK_Click()
        Unload Me
End Sub


Public Sub StartSysInfo()
    On Error GoTo SysInfoErr


        Dim rc As Long
        Dim SysInfoPath As String
        

        ' ��ע�����ϵͳ��Ϣ����·��\����...
        If GetKeyValue(HKEY_LOCAL_MACHINE, gREGKEYSYSINFO, gREGVALSYSINFO, SysInfoPath) Then
        ' ����ע�����ϵͳ��Ϣ����·��...
        ElseIf GetKeyValue(HKEY_LOCAL_MACHINE, gREGKEYSYSINFOLOC, gREGVALSYSINFOLOC, SysInfoPath) Then
                ' ��֤��֪�� 32 λ�ļ��汾�Ĵ���
                If (Dir(SysInfoPath & "\MSINFO32.EXE") <> "") Then
                        SysInfoPath = SysInfoPath & "\MSINFO32.EXE"
                        

                ' ���� - �ļ��Ҳ���...
                Else
                        GoTo SysInfoErr
                End If
        ' ���� - ע������Ҳ���...
        Else
                GoTo SysInfoErr
        End If
        

        Call Shell(SysInfoPath, vbNormalFocus)
        

        Exit Sub
SysInfoErr:
        MsgBox "��ʱϵͳ��Ϣ������", vbOKOnly
End Sub


Public Function GetKeyValue(KeyRoot As Long, KeyName As String, SubKeyRef As String, ByRef KeyVal As String) As Boolean
        Dim I As Long                                           ' ѭ��������
        Dim rc As Long                                          ' ���ش���
        Dim hKey As Long                                        ' �򿪵�ע�������
        Dim hDepth As Long                                      '
        Dim KeyValType As Long                                  ' ע������������
        Dim tmpVal As String                                    ' ��ʱ�洢һ��ע����ֵ
        Dim KeyValSize As Long                                  ' ע����������С
        '------------------------------------------------------------
        ' �ڼ���{HKEY_LOCAL_MACHINE...}֮�´�ע���
        '------------------------------------------------------------
        rc = RegOpenKeyEx(KeyRoot, KeyName, 0, KEY_ALL_ACCESS, hKey) ' ��ע����
        

        If (rc <> ERROR_SUCCESS) Then GoTo GetKeyError          ' ������...
        

        tmpVal = String$(1024, 0)                             ' ��������ռ�
        KeyValSize = 1024                                       ' ��Ǳ�����С
        

        '------------------------------------------------------------
        ' ����ע����ֵ...
        '------------------------------------------------------------
        rc = RegQueryValueEx(hKey, SubKeyRef, 0, KeyValType, tmpVal, KeyValSize)    ' ���/������ֵ
                                                

        If (rc <> ERROR_SUCCESS) Then GoTo GetKeyError          ' ������
      

        tmpVal = VBA.Left(tmpVal, InStr(tmpVal, VBA.Chr(0)) - 1)


        '------------------------------------------------------------
        ' ����ת���ļ�ֵ����...
        '------------------------------------------------------------
        Select Case KeyValType                                  ' ������������...
        Case REG_SZ                                             ' �ַ���ע������������
                KeyVal = tmpVal                                     ' �����ַ���ֵ
        Case REG_DWORD                                          ' ˫����ע������������
                For I = Len(tmpVal) To 1 Step -1                    ' ת��ÿһҳ
                        KeyVal = KeyVal + Hex(Asc(Mid(tmpVal, I, 1)))   ' һ���ַ�һ���ַ�������ֵ
                Next
                KeyVal = Format$("&h" + KeyVal)                     ' ת��˫����Ϊ�ַ���
        End Select
        

        GetKeyValue = True                                      ' ���سɹ�
        rc = RegCloseKey(hKey)                                  ' �ر�ע����
        Exit Function                                           ' �˳�
        

GetKeyError:    ' Cleanup After An Error Has Occured...
        KeyVal = ""                                             ' �践��ֵΪ���ַ���
        GetKeyValue = False                                     ' ����ʧ��
        rc = RegCloseKey(hKey)                                  ' �ر�ע����
End Function

