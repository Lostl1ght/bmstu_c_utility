@ECHO OFF
ECHO Compiling for debug.
CHCP 65001 1>NUL
gcc -std=c99 -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -Werror -O0 -g3 -c *.c
C:\msys64\mingw64\bin\gcc.exe -o app.exe *.o
SET ERR=%ERRORLEVEL%
IF %ERR% NEQ 0 ECHO. & ECHO Files were not compiled.
DEL *.o 2>NUL
ECHO Done.
ECHO.
EXIT /B %ERR%