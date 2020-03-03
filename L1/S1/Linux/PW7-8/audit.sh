#Revise function syntax (how to write and call)
users_connect()
{
	who
}

disk_space()
{
	df	#what does it do?
}

pause()
{	
	read -s -p "" #how to pause (wait or sleep or pause)
	      # return key
}

echo "0 - End"
echo "1 - Display users"
echo "2 - Display space available"
echo "Choose an item:"
read choice

case $choice in
	0) pause
		;;
	1) users_connect
		;;
	2) disk_space
		;;
	*) echo "Wrong number entered"
		;;
esac
