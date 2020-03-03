if [ $# -lt 1 ]; then
dir=$(pwd)
fi

for file in $(ls $dir);
do
	mv $dir/$file $dir/$( echo $file | tr [:upper:] [:lower:] )
done
