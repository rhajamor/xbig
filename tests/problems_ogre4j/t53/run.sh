#!/bin/sh
export LD_LIBRARY_PATH=$(dirname $0)
ant -lib ../../../src/ant/jar
