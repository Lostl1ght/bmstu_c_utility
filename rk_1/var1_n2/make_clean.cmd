@ECHO OFF
ECHO Cleaning.
IF EXIST "*.exe" DEL *.exe & ECHO Deleted .exe.
IF EXIST "*.o" DEL *.o & ECHO Deleted .o.
IF EXIST "*.gcov" DEL *.gcov & ECHO Deleted .gcov.
IF EXIST "*.gcda" DEL *.gcda & ECHO Deleted .gcda.
IF EXIST "*.gcno" DEL *.gcno & ECHO Deleted .gcno.
ECHO Done.