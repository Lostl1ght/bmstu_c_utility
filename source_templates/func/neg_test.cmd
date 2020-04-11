@ECHO OFF
IF "%1"=="" ECHO Not enough arguments. & GOTO :END
..\app.exe <neg_%~1_in.txt >out.txt
IF %ERRORLEVEL% EQU 0 ECHO Failed negative test no. %~1. Return code is 0. & GOTO :END
ECHO Negative test no. %~1. Return code is 1.
FC /N neg_%~1_out.txt out.txt
:END
ECHO.