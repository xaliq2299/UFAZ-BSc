fmt="%9s%20s%20s\n"
file="students.txt"
while read line #or read -r ?
do
	name=$(echo "$line" | cut -d"|" -f1)
	subj=$(echo "$line" | cut -d"|" -f2)
	res=$(echo "$line" | cut -d "|" -f3)
	printf $fmt "$name" "$subj" "$res" #printf ("" is important)
done < $file
