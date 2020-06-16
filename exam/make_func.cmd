@ECHO OFF
DEL *gcov 2>NUL
IF NOT EXIST "func" ECHO No tests. & GOTO :END
ECHO Compiling for coverage.
CHCP 65001 1>NUL
gcc -std=c99 -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -Werror --coverage -O0 -g3 -c main.c arith.c
gcc --coverage -o app.exe main.o arith.o
IF %ERRORLEVEL% NEQ 0 ECHO. & ECHO Files were not compiled. & GOTO :END
ECHO Done.
ECHO.
ECHO Testing.
PUSHD func
CALL all_test.cmd
POPD
gcov main.c
DEL *.gcda *.gcno *.o *.exe
:END
ECHO Done.