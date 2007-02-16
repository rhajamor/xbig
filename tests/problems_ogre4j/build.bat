@ECHO off
ECHO Building Testsuite ... > build.log
FOR /D %%G IN (t*) DO (ECHO ----- %%G ----- >> build.log & cd %%G & ant -lib ..\..\..\src\ant\jar clean > ..\tmp.txt & ant -lib ..\..\..\src\ant\jar >> ..\build.log 2>&1 & cd .. & del tmp.txt)
