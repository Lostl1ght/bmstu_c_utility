@ECHO OFF
CALL make_release.cmd
ECHO.
ECHO Running.
IF %ERRORLEVEL% NEQ 0 ECHO An error occurred during compilation. & GOTO :END
app.exe C:\Apps\Programming\c_labs\lab_06_01_01\text.txt title
ECHO.
ECHO.
ECHO Return code is %ERRORLEVEL%.
DEL app.exe 2>NUL
:END
ECHO Done.