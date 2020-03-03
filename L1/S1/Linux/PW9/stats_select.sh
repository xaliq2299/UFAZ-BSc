file="students.txt"

select choice in Students GPA
do
	case $REPLY in
	1)	read choice1
		if [ $choice1 -eq 6 ]; then
			while read -r line
			do
				class=$(echo "$line" | cut -d "|" -f 2)
				if [ $class == "6eme" ]; then
					name=$(echo "$line" | cut -d "|" -f 1)
					printf "$name\n"
			  	fi
			done < $file
		elif [ $choice1 -eq 5 ]; then
			while read -r line
			do
				class=$(echo "$line" | cut -d "|" -f 2)
				if [ $class == "5eme" ]; then
					name=$(echo "$line" | cut -d "|" -f 1)
					printf "$name\n"
			  	fi
			done < $file
		else
			echo "You entered the class that we don't have"
		fi
		;;
	2) 	sum=0
		n=0
		while read -r line 
		do
			result=$(echo "$line" | cut -d "|" -f3)
			sum=$((sum+result))
			let n=$n+1
		done < $file

		let avg=$sum/$n
		echo "AVG: $avg"
		;;
	*);;
	esac	
done
