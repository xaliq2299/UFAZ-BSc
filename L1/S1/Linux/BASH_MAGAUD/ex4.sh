#!/bin/bash

read -p "Magic word? : " a
while [ "$a" != "thanks" ]
do
echo "The input is: $a"
echo "Magic word? "
read a
done
echo "you are welcome"
