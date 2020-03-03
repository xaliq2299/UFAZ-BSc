#Revise the case syntax ( usage of []|) ) 

if [ $# -eq 0 ]; then
	echo "Wrong number of arguments"
	echo "Usage: ./zip_code.sh zip"
	exit
fi

case $1 in
	67[0-9][0-9][0-9])
		echo "$1 is a zip code from the area of Strasbourg"
	;;
	
	75[0-9][0-9][0-9])
		echo "$1 is a correct zip code, not from the area of Strasbourg (actually it is Paris ;-)"
	;;
	
	[0-9][0-9][0-9][0-9][0-9])
		echo "$1 is a correct zip code, not from the area of Strasbourg"
	;;
	
	*) 
		echo "$1 is incorrect"
	;;
esac
