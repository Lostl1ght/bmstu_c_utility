@ECHO OFF
CHCP 65001 1>NUL
ECHO TESTING
ECHO.
C:\msys64\mingw64\bin\gcc.exe -std=c99 -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -Werror -O0 --coverage %1 -o %2\app.exe
IF NOT EXIST "%2\func" ECHO No tests & GOTO :END
CD "%2\func"
CALL .\all_test.cmd
CD "C:\msys64\mingw64\bin"
C:\msys64\mingw64\bin\gcov.exe main.c
MOVE *.gcov %2 1>NUL
MOVE *.gcda %2 1>NUL
MOVE *.gcno %2 1>NUL
:END
CD "%2"
DEL *.gcda *.gcno *.exe 2>NUL
PUSHD ..
PUSHD ..
ECHO DONE