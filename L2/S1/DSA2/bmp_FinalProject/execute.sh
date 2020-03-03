make resize
make stitch
# Argument checking
if [ $# -ne 1 ]
then
    echo "Argument problem"
    echo "Usage: ./execute.sh foldername"
    exit
fi
foldername=$1
if [ ! -d $foldername ]; then
	echo "The provided foldername ($foldername) doesn't exist in a current directory"
	exit
fi

# Resizing bmp files
count=0
echo "Resizing files"
for file in $(ls "$foldername"/*.bmp);
do
	if [[ "$file" != *"Resized.bmp" && "$file" != *"flattenedPot.bmp" && "$file" != *"_S82.bmp" ]]; then
		echo "Processing: $file\n"
    	./resize $file
		((count++))
    fi
done
printf "\nTotal files processed: $count"
printf "\n--------------------------\n"
echo ""

# Extracting strips of width 82 from new resized bmp files
count=0
echo "Extracting the strips from newly created resized files"
for file in $(ls "$foldername"/*Resized.bmp);
do
	echo "Extracting a strip from $file\n"
    ./extractStrip -82 $file
	((count++))
done
printf "\nTotal files extracted: $count"
printf "\n--------------------------\n"
echo ""

# Stitching all the new strips of width 82
mv stitch $foldername
cd $foldername
echo "Stitching process starts"
./stitch
echo "Stitching process ended"
mv stitch ..

echo "End of the process"