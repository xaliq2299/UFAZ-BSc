echo "$#"
echo "$0"
echo "$1"
echo "$2"
echo "$3"
echo "$*"
echo "$@" #difference between * and @ ?
echo "$$"

if [ $# -le 3 ]; then
	echo "There are less arguments"
fi

echo '$* = ' $*
echo '$@ = ' $@ 

for i in $*
do
	echo '.'$i'.'
done
	
for i in $@
do
	echo '.'$i'.'
done
	

echo -n $1 | wc -m # -n
echo -n $2 | wc -m 
echo -n $3 | wc -m
