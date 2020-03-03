if [ -e /etc ]; then
	echo "/etc exists"
fi

if [ -r /etc/hosts ]; then
	echo "readable"
fi

if [ -x /etc/hosts ]; then
	echo "/etc/hosts is executable by the user"
fi

if [[ -d /usr && -r /usr ]]; then
	echo "/usr is both a directory and can be visited"
fi

if [ -c /dev/null ]; then 
	echo "/dev/null is a special device file"
fi
