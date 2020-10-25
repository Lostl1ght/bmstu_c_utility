@ECHO OFF
IF "%1" == "" ECHO Not enough arguments. & GOTO :END
IF EXIST pos_%1_args.txt (SET /P VAR=<pos_%1_args.txt) ELSE (SET VAR="")
..\app.exe %VAR%
IF %ERRORLEVEL% NEQ 0 ECHO Positive test %1 FAILED. Return code is %ERRORLEVEL%. & GOTO :END
@ECHO Positive test %1 SUCCEDED. Return code is %ERRORLEVEL%.
FC /N pos_%1_out.txt out.txt
:END
ECHO.