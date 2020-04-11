@ECHO OFF
ECHO Compiling for release.
CHCP 65001 1>NUL
SET VAR=%CD%
PUSHD "C:\msys64\mingw64\bin"
C:\msys64\mingw64\bin\gcc.exe -std=c99 -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -Werror -O3 -c %VAR%\main.c -o %VAR%\main.o
C:\msys64\mingw64\bin\gcc.exe -o %VAR%\app.exe %VAR%\main.o
SET ERR=%ERRORLEVEL%
POPD
IF %ERR% NEQ 0 ECHO. & ECHO Files were not compiled. & GOTO :END
DEL *.o
ECHO Done.
ECHO.