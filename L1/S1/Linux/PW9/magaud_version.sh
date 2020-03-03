#!/bin/bash

PS3='Choose an option: '

select opt in "list gpa quit"
do
case $REPLY in
list)	echo "which class ?"; read line; grep $line students.txt | column -t -s "|"
	break
	;;
gpa)	echo "which class ?"; read line; grep $line students.txt | cut -d "|" -f 3 | ./sum.sh
	break
	;;
quit)	break
	;;
*) echo "unexpected option"
esac
done
