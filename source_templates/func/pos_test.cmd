@ECHO OFF
IF "%1"=="" ECHO Not enough arguments. & GOTO :END
..\app.exe <pos_%~1_in.txt >out.txt
IF %ERRORLEVEL% NEQ 0 ECHO Failed positive test no. %~1. Return code is 1. & GOTO :END
ECHO Positive test no. %~1. Return code is 0.
FC /N pos_%~1_out.txt out.txt
:END
ECHO.