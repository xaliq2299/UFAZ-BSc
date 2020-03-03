
echo "Write one number per line, ^d to display the sum:"
sum=0

while read num
do
	if [[ $num == ?(+)?(-)*([0-9]) ]]; then
		sum=$((sum+num))
	else
		echo "This value is not a number, please write a number:"
	fi
done

echo "The sum of all these numbers is: $sum"
