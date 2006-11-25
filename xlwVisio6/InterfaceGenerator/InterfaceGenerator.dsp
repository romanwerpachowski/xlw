# Microsoft Developer Studio Project File - Name="InterfaceGenerator" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=InterfaceGenerator - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "InterfaceGenerator.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "InterfaceGenerator.mak" CFG="InterfaceGenerator - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "InterfaceGenerator - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "InterfaceGenerator - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "InterfaceGenerator - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x809 /d "NDEBUG"
# ADD RSC /l 0x809 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "InterfaceGenerator - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR /YX /FD /GZ /c
# ADD BASE RSC /l 0x809 /d "_DEBUG"
# ADD RSC /l 0x809 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "InterfaceGenerator - Win32 Release"
# Name "InterfaceGenerator - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\InterfaceGenerator\Functionizer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\InterfaceGenerator\FunctionModel.cpp
# End Source File
# Begin Source File

SOURCE=..\..\InterfaceGenerator\FunctionType.cpp
# End Source File
# Begin Source File

SOURCE=..\..\InterfaceGenerator\IncludeRegister.cpp
# End Source File
# Begin Source File

SOURCE=..\..\InterfaceGenerator\main.cpp
# End Source File
# Begin Source File

SOURCE=..\..\InterfaceGenerator\Outputter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\InterfaceGenerator\ParserData.cpp
# End Source File
# Begin Source File

SOURCE=..\..\InterfaceGenerator\Strip.cpp
# End Source File
# Begin Source File

SOURCE=..\..\InterfaceGenerator\Tokenizer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\InterfaceGenerator\TypeRegister.cpp
# End Source File
# Begin Source File

SOURCE=..\..\InterfaceGenerator\TypeRegistrations.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\..\xlw\ArgList.h
# End Source File
# Begin Source File

SOURCE=..\..\xlw\ArgListFactory.h
# End Source File
# Begin Source File

SOURCE=..\..\xlw\ArgListFactoryHelper.h
# End Source File
# Begin Source File

SOURCE=..\..\xlw\CellMatrix.h
# End Source File
# Begin Source File

SOURCE=..\..\xlw\config.bcc.h
# End Source File
# Begin Source File

SOURCE=..\..\xlw\config.mgw.h
# End Source File
# Begin Source File

SOURCE=..\..\xlw\config.msvc.h
# End Source File
# Begin Source File

SOURCE=..\..\xlw\defines.h
# End Source File
# Begin Source File

SOURCE=..\..\xlw\DoubleOrNothing.h
# End Source File
# Begin Source File

SOURCE=..\..\xlw\ERR_Macros.h
# End Source File
# Begin Source File

SOURCE=..\..\xlw\EXCEL32_API.h
# End Source File
# Begin Source File

SOURCE=..\..\InterfaceGenerator\Functionizer.h
# End Source File
# Begin Source File

SOURCE=..\..\InterfaceGenerator\FunctionModel.h
# End Source File
# Begin Source File

SOURCE=..\..\InterfaceGenerator\FunctionType.h
# End Source File
# Begin Source File

SOURCE=..\..\InterfaceGenerator\IncludeRegister.h
# End Source File
# Begin Source File

SOURCE=..\..\xlw\macros.h
# End Source File
# Begin Source File

SOURCE=..\..\xlw\MJmatrices.h
# End Source File
# Begin Source File

SOURCE=..\..\xlw\MyContainers.h
# End Source File
# Begin Source File

SOURCE=..\..\InterfaceGenerator\Outputter.h
# End Source File
# Begin Source File

SOURCE=..\..\InterfaceGenerator\ParserData.h
# End Source File
# Begin Source File

SOURCE=..\..\xlw\port.h
# End Source File
# Begin Source File

SOURCE=..\..\xlw\pragmas.h
# End Source File
# Begin Source File

SOURCE=..\..\InterfaceGenerator\Singleton.h
# End Source File
# Begin Source File

SOURCE=..\..\InterfaceGenerator\Strip.h
# End Source File
# Begin Source File

SOURCE=..\..\InterfaceGenerator\Tokenizer.h
# End Source File
# Begin Source File

SOURCE=..\..\InterfaceGenerator\TypeRegister.h
# End Source File
# Begin Source File

SOURCE=..\..\xlw\Win32StreamBuf.h
# End Source File
# Begin Source File

SOURCE=..\..\xlw\Win32StreamBuf.inl
# End Source File
# Begin Source File

SOURCE=..\..\xlw\wrapper.h
# End Source File
# Begin Source File

SOURCE=..\..\xlw\xlcall32.h
# End Source File
# Begin Source File

SOURCE=..\..\xlw\XlfAbstractCmdDesc.h
# End Source File
# Begin Source File

SOURCE=..\..\xlw\XlfAbstractCmdDesc.inl
# End Source File
# Begin Source File

SOURCE=..\..\xlw\XlfArgDesc.h
# End Source File
# Begin Source File

SOURCE=..\..\xlw\XlfArgDescList.h
# End Source File
# Begin Source File

SOURCE=..\..\xlw\XlfCmdDesc.h
# End Source File
# Begin Source File

SOURCE=..\..\xlw\XlfExcel.h
# End Source File
# Begin Source File

SOURCE=..\..\xlw\XlfExcel.inl
# End Source File
# Begin Source File

SOURCE=..\..\xlw\XlfException.h
# End Source File
# Begin Source File

SOURCE=..\..\xlw\XlfException.inl
# End Source File
# Begin Source File

SOURCE=..\..\xlw\XlfFuncDesc.h
# End Source File
# Begin Source File

SOURCE=..\..\xlw\XlfOper.h
# End Source File
# Begin Source File

SOURCE=..\..\xlw\XlfOper.inl
# End Source File
# Begin Source File

SOURCE=..\..\xlw\XlfRef.h
# End Source File
# Begin Source File

SOURCE=..\..\xlw\XlfRef.inl
# End Source File
# Begin Source File

SOURCE=..\..\xlw\XlFunctionRegistration.h
# End Source File
# Begin Source File

SOURCE=..\..\xlw\XlOpenClose.h
# End Source File
# Begin Source File

SOURCE=..\..\xlw\xlw.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
