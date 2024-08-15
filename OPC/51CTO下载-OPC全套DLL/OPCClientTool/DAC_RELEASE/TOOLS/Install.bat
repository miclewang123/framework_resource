
Copy Dlls\*.* %WINDIR%\System32
Copy OpcEnum.exe %WINDIR%

REGSVR32  /s %WINDIR%\System32\opccomn_ps.dll
REGSVR32  /s %WINDIR%\System32\opcproxy.dll
REGSVR32  /s %WINDIR%\System32\opc_aeps.dll
REGSVR32  /s %WINDIR%\System32\opchda_ps.dll
REGSVR32  /s %WINDIR%\System32\OpcRcw.Comn.dll
%WINDIR%\Opcenum /RegServer

