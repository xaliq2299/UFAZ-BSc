#ls $dir
sweep() #look through
{
	dir=~ #
	FILES=$(ls ~) #
	
	for f in $FILES #looping through files
	do
		if [ ! -s $dir/$f ]; then #
			rm -i $dir/$f 
		fi
	done
}

no_space() #
{
	file="data.txt"
	(df -h --total) > "$file"
	
	while read -r line
	do
		word=$(echo $line | cut -d ' ' -f1)
		if [ $word == "total" ]; then
			used=$(echo $line | cut -d ' ' -f5 | tr -d '%')
		fi
	done < $file
	
	dir=$(pwd)
	rm $dir/"$file"
	
	if [ $used -gt 80 ]; then 
		echo "true"
	else
		echo "false"
	fi
}


echo "0 - End"
echo "1 - Remove files of size 0 from my home directory"
echo "2 - Check the space available at the root of the filesystem"
echo "Choose an item:"
read choice

case $choice in
	0) exit 
	;;
	1) sweep
	;;
	2) no_space
	;;
esac
