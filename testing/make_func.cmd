@ECHO OFF
IF NOT EXIST "func" ECHO No tests. & GOTO :END
ECHO Compiling for coverage.
CHCP 65001 1>NUL
SET VAR=%CD%
PUSHD "C:\msys64\mingw64\bin"
C:\msys64\mingw64\bin\gcc.exe -std=c99 -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -Werror --coverage -O0 -g3 -c %VAR%\main.c -o %VAR%\main.o
C:\msys64\mingw64\bin\gcc.exe -std=c99 -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -Werror --coverage -O0 -g3 -c %VAR%\matrix.c -o %VAR%\matrix.o
C:\msys64\mingw64\bin\gcc.exe -std=c99 -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -Werror --coverage -O0 -g3 -c %VAR%\array.c -o %VAR%\array.o
C:\msys64\mingw64\bin\gcc.exe --coverage -o %VAR%\app.exe %VAR%\main.o %VAR%\matrix.o %VAR%\array.o
POPD
IF %ERRORLEVEL% NEQ 0 ECHO. & ECHO Files were not compiled. & GOTO :END
ECHO Done.
ECHO.
ECHO Testing.
PUSHD func
CALL all_test.cmd
PUSHD ..
C:\msys64\mingw64\bin\gcov.exe %VAR%\main.c
C:\msys64\mingw64\bin\gcov.exe %VAR%\matrix.c
C:\msys64\mingw64\bin\gcov.exe %VAR%\array.c
DEL *.gcda *.gcno *.o *.exe
:END
ECHO Done.