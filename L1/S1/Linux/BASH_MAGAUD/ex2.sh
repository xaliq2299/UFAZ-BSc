#!/bin/bash

if [ $# == 2 ]; then
echo "right numbers of arguments -. proceeding..."
echo "arg1 is: $1"
if [ -f $1 ]
then echo "regular"
else echo "directory"
fi
echo $(($2+1))
else
echo "usage: $0 x1 x2"
