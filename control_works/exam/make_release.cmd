@ECHO OFF
ECHO Compiling for release.
CHCP 65001 1>NUL
gcc -std=c99 -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -Werror -O3 -c main.c arith.c
gcc -o app.exe main.o arith.o
SET ERR=%ERRORLEVEL%
IF %ERR% NEQ 0 ECHO. & ECHO Files were not compiled.
DEL *.o
ECHO Done.
ECHO.
EXIT /B %ERR%