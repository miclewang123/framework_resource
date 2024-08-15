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
      Tag             =   "确定"
      Top             =   2160
      Width           =   1467
   End
   Begin VB.CommandButton cmdSysInfo 
      Caption         =   "&System info..."
      Height          =   345
      Left            =   1800
      TabIndex        =   1
      Tag             =   "系统信息(&S)..."
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
         Caption         =   "VB样例程序"
         BeginProperty Font 
            Name            =   "宋体"
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
         Tag             =   "版本"
         Top             =   720
         Width           =   4095
      End
      Begin VB.Label lblTitle 
         Caption         =   "OPC 数据访问服务器客户端开发工具包"
         BeginProperty Font 
            Name            =   "宋体"
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
         Tag             =   "应用程序标题"
         Top             =   360
         Width           =   3615
      End
      Begin VB.Label Label3 
         Caption         =   "http://www.agilewill.com"
         BeginProperty Font 
            Name            =   "宋体"
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
         Tag             =   "应用程序描述"
         Top             =   1440
         Width           =   3735
      End
      Begin VB.Label lblDescription 
         Caption         =   "北京安捷尔软件技术有限公司 2005.11"
         BeginProperty Font 
            Name            =   "宋体"
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
         Tag             =   "应用程序描述"
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

' 注册键安全选项...
Const KEY_ALL_ACCESS = &H2003F
                                          

' 注册键根类型...
Const HKEY_LOCAL_MACHINE = &H80000002
Const ERROR_SUCCESS = 0
Const REG_SZ = 1                         ' Unicode 空结尾字符串
Const REG_DWORD = 4                      ' 32位数


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
        

        ' 从注册表获得系统信息程序路径\名称...
        If GetKeyValue(HKEY_LOCAL_MACHINE, gREGKEYSYSINFO, gREGVALSYSINFO, SysInfoPath) Then
        ' 仅从注册表获得系统信息程序路径...
        ElseIf GetKeyValue(HKEY_LOCAL_MACHINE, gREGKEYSYSINFOLOC, gREGVALSYSINFOLOC, SysInfoPath) Then
                ' 验证已知的 32 位文件版本的存在
                If (Dir(SysInfoPath & "\MSINFO32.EXE") <> "") Then
                        SysInfoPath = SysInfoPath & "\MSINFO32.EXE"
                        

                ' 错误 - 文件找不到...
                Else
                        GoTo SysInfoErr
                End If
        ' 错误 - 注册表项找不到...
        Else
                GoTo SysInfoErr
        End If
        

        Call Shell(SysInfoPath, vbNormalFocus)
        

        Exit Sub
SysInfoErr:
        MsgBox "此时系统信息不可用", vbOKOnly
End Sub


Public Function GetKeyValue(KeyRoot As Long, KeyName As String, SubKeyRef As String, ByRef KeyVal As String) As Boolean
        Dim I As Long                                           ' 循环记数器
        Dim rc As Long                                          ' 返回代码
        Dim hKey As Long                                        ' 打开的注册表键句柄
        Dim hDepth As Long                                      '
        Dim KeyValType As Long                                  ' 注册表键数据类型
        Dim tmpVal As String                                    ' 临时存储一个注册表键值
        Dim KeyValSize As Long                                  ' 注册表键变量大小
        '------------------------------------------------------------
        ' 在键根{HKEY_LOCAL_MACHINE...}之下打开注册键
        '------------------------------------------------------------
        rc = RegOpenKeyEx(KeyRoot, KeyName, 0, KEY_ALL_ACCESS, hKey) ' 打开注册表键
        

        If (rc <> ERROR_SUCCESS) Then GoTo GetKeyError          ' 错误处理...
        

        tmpVal = String$(1024, 0)                             ' 分配变量空间
        KeyValSize = 1024                                       ' 标记变量大小
        

        '------------------------------------------------------------
        ' 检索注册表键值...
        '------------------------------------------------------------
        rc = RegQueryValueEx(hKey, SubKeyRef, 0, KeyValType, tmpVal, KeyValSize)    ' 获得/创建键值
                                                

        If (rc <> ERROR_SUCCESS) Then GoTo GetKeyError          ' 错误处理
      

        tmpVal = VBA.Left(tmpVal, InStr(tmpVal, VBA.Chr(0)) - 1)


        '------------------------------------------------------------
        ' 决定转换的键值类型...
        '------------------------------------------------------------
        Select Case KeyValType                                  ' 搜索数据类型...
        Case REG_SZ                                             ' 字符串注册表键数据类型
                KeyVal = tmpVal                                     ' 复制字符串值
        Case REG_DWORD                                          ' 双精度注册表键数据类型
                For I = Len(tmpVal) To 1 Step -1                    ' 转换每一页
                        KeyVal = KeyVal + Hex(Asc(Mid(tmpVal, I, 1)))   ' 一个字符一个字符地生成值
                Next
                KeyVal = Format$("&h" + KeyVal)                     ' 转换双精度为字符串
        End Select
        

        GetKeyValue = True                                      ' 返回成功
        rc = RegCloseKey(hKey)                                  ' 关闭注册表键
        Exit Function                                           ' 退出
        

GetKeyError:    ' Cleanup After An Error Has Occured...
        KeyVal = ""                                             ' 设返回值为空字符串
        GetKeyValue = False                                     ' 返回失败
        rc = RegCloseKey(hKey)                                  ' 关闭注册表键
End Function

