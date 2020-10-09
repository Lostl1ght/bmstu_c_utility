@ECHO OFF
ECHO Compiling for release.
CHCP 65001 1>NUL
gcc -std=c99 -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -Werror -c  create.c
gcc -o create.exe create.o
SET ERR=%ERRORLEVEL%
IF %ERR% NEQ 0 ECHO. & ECHO Files were not compiled.
DEL *.o 2>NUL
ECHO Done.
EXIT /B %ERR%