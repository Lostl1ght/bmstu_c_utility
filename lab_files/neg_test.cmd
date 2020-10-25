@ECHO OFF
IF "%1" == "" ECHO Not enough arguments. & GOTO :END
IF EXIST neg_%1_args.txt (SET /P VAR=<neg_%1_args.txt) ELSE (SET VAR="")
..\app.exe %VAR%
IF %ERRORLEVEL% EQU 0 ECHO Negative test %1 FAILED. Return code is %ERRORLEVEL%. & GOTO :END
@ECHO Negative test %1 SUCCEDED. Return code is %ERRORLEVEL%.
FC /N neg_%1_out.txt out.txt
:END
ECHO.