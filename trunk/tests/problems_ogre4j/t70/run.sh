#!/bin/bash


ant_16() {
  ant -lib ../../../src/ant/jar "$@"
}

ant_17() {
  ant "$@"
}

export LD_LIBRARY_PATH=$(dirname $0)

version=$( ant -version | grep -o "[0-9]\.[0-9]" | cut -c 1 )
subversion=$( ant -version | grep -o "[0-9]\.[0-9]" | cut -c 3 )

if [ "$version" -le "0" ]
then
  ant_16
else
  if [ "$version" == "1" ]
  then
    if [ "$subversion" -le "6" ]
    then
      ant_16
    else
      ant_17
    fi
  else
    ant_17
  fi
fi
