@ECHO OFF
CALL make_release.cmd
ECHO.
ECHO Running.
IF %ERRORLEVEL% NEQ 0 ECHO An error occurred during compilation. 
app.exe
ECHO.
ECHO.
ECHO Return code is %ERRORLEVEL%.
:END
DEL *.o *.exe 2>NUL
ECHO Done.