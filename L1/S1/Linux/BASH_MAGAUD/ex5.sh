#!/bin/bash

let a=0
echo "The files that are regular and writable:"
for i in *
do
	if [ -f $i -a -w $i ]; then
		echo $i
		let a+=1
	fi
done
echo "The number of such files $a"
