declare -A class
file="students.txt"
class[5eme]=0
class[6eme]=0

while read line
do
	#for i in ${!class[$@]}
	i=$(echo line | cut -d '|' -f2)
	let class[$i]=${class[$i]}+1	
	
done < $file

echo "${class[5eme]}"
