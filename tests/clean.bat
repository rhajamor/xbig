@ECHO off
ECHO Building Testsuite ... > build.log
FOR /D %%G IN (t*) DO (ECHO ----- %%G ----- >> build.log & cd %%G & ant clean > ..\tmp.txt & cd .. & del tmp.txt)
