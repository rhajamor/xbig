@ECHO off
ECHO Building Testsuite ... > build.log
FOR /D %%G IN (t*) DO (ECHO ----- %%G ----- >> build.log & cd %%G & ant clean > ..\tmp.txt & ant >> ..\build.log 2>&1 & cd .. & del tmp.txt)
