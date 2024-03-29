#!/bin/bash

touch build.log
echo "Building Testsuite ..."
echo "Building Testsuite ..." > build.log

for i in `ls -d t*`
do
	echo Building $i ...
	echo >> build.log
	echo >> build.log
	echo ----- $i ----- >> build.log

	if [ $i != t65 ]; then
		cd $i
		ant -lib ../../../src/ant/jar clean > /dev/null
		sh run.sh >> ../build.log 2>&1
		cd  ..
	else
		echo BUILD FAILED >> build.log
	fi
done
echo done
