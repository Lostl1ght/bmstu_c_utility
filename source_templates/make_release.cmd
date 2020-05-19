@ECHO OFF
ECHO Compiling for release.
CHCP 65001 1>NUL
C:\msys64\mingw64\bin\gcc.exe -std=c99 -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -Werror -O3 -c *.c
C:\msys64\mingw64\bin\gcc.exe -o %VAR%\app.exe *.o
SET ERR=%ERRORLEVEL%
IF %ERR% NEQ 0 ECHO. & ECHO Files were not compiled.
DEL *.o
ECHO Done.
ECHO.
EXIT /B %ERR%