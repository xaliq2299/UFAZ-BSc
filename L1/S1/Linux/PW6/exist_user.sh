file=/etc/passwd

if [ $# -eq 0 ]; then
	echo "Wrong number of arguments"
	echo "Usage: ./exist_user.sh <username>"
fi

#if (grep -i -w $1 $file | cut -d ':' -f1); then #xali also works
#use of grep -w and cut (-b,-c, -d, -f)
if [[ $(grep -i -w $1 $file | cut -d ':' -f 1) ]]; then
	echo "The user $1 exists in this system"
else
	echo "The user $1 is not defined in this system"
fi
