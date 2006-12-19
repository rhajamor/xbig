#!/bin/bash

touch build.log
echo "Building Testsuite ..." > build.log

for i in `ls -d t*`
do
	echo >> build.log
	echo >> build.log
	echo ----- $i ----- >> build.log
	cd $i
	./run.sh >> ../build.log 2>&1
	cd  ..
done
