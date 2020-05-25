@ECHO OFF
CALL make_release.cmd
ECHO.
ECHO Running.
IF %ERRORLEVEL% NEQ 0 ECHO An error occurred during compilation. & GOTO :END
app.exe
ECHO.
ECHO.
ECHO Return code is %ERRORLEVEL%.
DEL app.exe 2>NUL
:END
ECHO Done.