file="students.txt"

array[0]=0 #size=${#ar[*]}
array[1]=0
fmt="%20s%15s"
fmt1="\n"

while read line
do
	class=$(echo $line | cut -d "|" -f2)
	
	if [ $class == "5eme" ]; then
		let array[0]=${array[0]}+1
	elif [ $class == "6eme" ]; then
		let array[1]=${array[1]}+1
	fi
	
done < $file

printf $fmt "Classes" "5eme" "6eme"
printf $fmt1
printf $fmt "Number of students" "${array[0]}" "${array[1]}"
printf $fmt1


#Second version
#/bin/bash

:'let sum=0
let counter=0
${array[0]}=0
${array[1]}=0
	while read -r line
	do
	  for i in "${!array[@]}"
	  do
	  gpa=$(echo $line | cut -d"|" -f3)
 	  let ${array[i]}+=1
 	  done < students.txt
 	  name=$(echo $line | cut -d"|" -f1)  
	  class=$(echo $line | cut -d"|" -f2)
 	done < students.txt	
	
	
echo "5eme     6eme"
for i in "${!array[@]}"
do
  echo "${array[$i]}"
done'
