@ECHO OFF
CHCP 65001
ECHO.
FOR /L %%B IN (1,1,7) DO (CALL neg_test.cmd %%B)
FOR /L %%B IN (1,1,6) DO (CALL pos_test.cmd %%B)
DEL out.txt