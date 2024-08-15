# Microsoft Developer Studio Generated NMAKE File, Based on Tracker.dsp
!IF "$(CFG)" == ""
CFG=Tracker - Win32 Debug
!MESSAGE No configuration specified. Defaulting to Tracker - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Tracker - Win32 Release" && "$(CFG)" != "Tracker - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Tracker.mak" CFG="Tracker - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Tracker - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Tracker - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Tracker - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\Tracker.exe"


CLEAN :
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\Tracker.obj"
	-@erase "$(INTDIR)\Tracker.pch"
	-@erase "$(INTDIR)\Tracker.res"
	-@erase "$(INTDIR)\TrackerDoc.obj"
	-@erase "$(INTDIR)\TrackerView.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\WS_PolyLine.obj"
	-@erase "$(INTDIR)\WS_RectTracker.obj"
	-@erase "$(OUTDIR)\Tracker.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Tracker.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Tracker.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Tracker.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\Tracker.pdb" /machine:I386 /out:"$(OUTDIR)\Tracker.exe" 
LINK32_OBJS= \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Tracker.obj" \
	"$(INTDIR)\TrackerDoc.obj" \
	"$(INTDIR)\TrackerView.obj" \
	"$(INTDIR)\WS_PolyLine.obj" \
	"$(INTDIR)\WS_RectTracker.obj" \
	"$(INTDIR)\Tracker.res"

"$(OUTDIR)\Tracker.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Tracker - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\Tracker.exe" "$(OUTDIR)\Tracker.bsc"


CLEAN :
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\Tracker.obj"
	-@erase "$(INTDIR)\Tracker.pch"
	-@erase "$(INTDIR)\Tracker.res"
	-@erase "$(INTDIR)\Tracker.sbr"
	-@erase "$(INTDIR)\TrackerDoc.obj"
	-@erase "$(INTDIR)\TrackerDoc.sbr"
	-@erase "$(INTDIR)\TrackerView.obj"
	-@erase "$(INTDIR)\TrackerView.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\WS_PolyLine.obj"
	-@erase "$(INTDIR)\WS_PolyLine.sbr"
	-@erase "$(INTDIR)\WS_RectTracker.obj"
	-@erase "$(INTDIR)\WS_RectTracker.sbr"
	-@erase "$(OUTDIR)\Tracker.bsc"
	-@erase "$(OUTDIR)\Tracker.exe"
	-@erase "$(OUTDIR)\Tracker.ilk"
	-@erase "$(OUTDIR)\Tracker.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\Tracker.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Tracker.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Tracker.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\Tracker.sbr" \
	"$(INTDIR)\TrackerDoc.sbr" \
	"$(INTDIR)\TrackerView.sbr" \
	"$(INTDIR)\WS_PolyLine.sbr" \
	"$(INTDIR)\WS_RectTracker.sbr"

"$(OUTDIR)\Tracker.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\Tracker.pdb" /debug /machine:I386 /out:"$(OUTDIR)\Tracker.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Tracker.obj" \
	"$(INTDIR)\TrackerDoc.obj" \
	"$(INTDIR)\TrackerView.obj" \
	"$(INTDIR)\WS_PolyLine.obj" \
	"$(INTDIR)\WS_RectTracker.obj" \
	"$(INTDIR)\Tracker.res"

"$(OUTDIR)\Tracker.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("Tracker.dep")
!INCLUDE "Tracker.dep"
!ELSE 
!MESSAGE Warning: cannot find "Tracker.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Tracker - Win32 Release" || "$(CFG)" == "Tracker - Win32 Debug"
SOURCE=.\MainFrm.cpp

!IF  "$(CFG)" == "Tracker - Win32 Release"


"$(INTDIR)\MainFrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Tracker.pch"


!ELSEIF  "$(CFG)" == "Tracker - Win32 Debug"


"$(INTDIR)\MainFrm.obj"	"$(INTDIR)\MainFrm.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Tracker.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "Tracker - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Tracker.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Tracker.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Tracker - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\Tracker.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\Tracker.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\Tracker.cpp

!IF  "$(CFG)" == "Tracker - Win32 Release"


"$(INTDIR)\Tracker.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Tracker.pch"


!ELSEIF  "$(CFG)" == "Tracker - Win32 Debug"


"$(INTDIR)\Tracker.obj"	"$(INTDIR)\Tracker.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Tracker.pch"


!ENDIF 

SOURCE=.\Tracker.rc

"$(INTDIR)\Tracker.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\TrackerDoc.cpp

!IF  "$(CFG)" == "Tracker - Win32 Release"


"$(INTDIR)\TrackerDoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Tracker.pch"


!ELSEIF  "$(CFG)" == "Tracker - Win32 Debug"


"$(INTDIR)\TrackerDoc.obj"	"$(INTDIR)\TrackerDoc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Tracker.pch"


!ENDIF 

SOURCE=.\TrackerView.cpp

!IF  "$(CFG)" == "Tracker - Win32 Release"


"$(INTDIR)\TrackerView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Tracker.pch"


!ELSEIF  "$(CFG)" == "Tracker - Win32 Debug"


"$(INTDIR)\TrackerView.obj"	"$(INTDIR)\TrackerView.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Tracker.pch"


!ENDIF 

SOURCE=.\WS_PolyLine.cpp

!IF  "$(CFG)" == "Tracker - Win32 Release"


"$(INTDIR)\WS_PolyLine.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Tracker.pch"


!ELSEIF  "$(CFG)" == "Tracker - Win32 Debug"


"$(INTDIR)\WS_PolyLine.obj"	"$(INTDIR)\WS_PolyLine.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Tracker.pch"


!ENDIF 

SOURCE=.\WS_RectTracker.cpp

!IF  "$(CFG)" == "Tracker - Win32 Release"


"$(INTDIR)\WS_RectTracker.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Tracker.pch"


!ELSEIF  "$(CFG)" == "Tracker - Win32 Debug"


"$(INTDIR)\WS_RectTracker.obj"	"$(INTDIR)\WS_RectTracker.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Tracker.pch"


!ENDIF 


!ENDIF 

