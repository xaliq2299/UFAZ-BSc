#!/bin/bash

isPrime() {
	for cr in {2..$(($1/2))} 
		do
		if [ $1%$cr -eq 0 ]; then
			 break
			 return 0
		fi
		
		done
	return 1
}

echo hi from $0

read -p "Enter two positive numbers: " a b

for (( x=$a; x<=$b; x++ ))
	do
	hg=isPrime $x
	if [ $hg -eq 1 ]; then 
		echo "is prime"
	fi
done
