s1=yes
s2=no
mt=""
file1=report.pdf

if [ $s1 == $s2 ]; then #blank space
	echo "They are equal"
fi

if [ $s1 != $s2 ]; then
	echo "They are different"
fi

if [ -z $mt ]; then
	echo "Empty"
else
	echo "Non-empty"
fi

if [ $file1 == *.doc ]; then 
	echo "Ends with .doc"
fi

if [[ $file1 = *.doc || $file1 = *.pdf ]]; then 
	echo "Ends with .doc or .pdf"
fi
