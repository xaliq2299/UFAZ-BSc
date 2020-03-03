#!/bin/bash

##arguments are only -c or -m
if [ $# = 1 ]
then 
if [[ $1 = "-s" || $1 = "-c" ]]; then
while [ 1 -eq 1 ]
do
	if [[ "1" -eq "-s" ]]; then
	ps -o %mem -o command
	else
	ps 
done

echo "ok"
else echo "usage: 

else echo "usage: %0 arg1 (%0 requires oen single argument 
