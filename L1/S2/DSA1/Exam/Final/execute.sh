# takes strip width as argument and executes 
# extractStrip on all BMP files in current folder

if [ $# -ne 2 ]
then
    echo "[!] Wrong argument count"
    return 1
fi

strip_width=$1

if [ $strip_width -le 0 ]
then
    ((strip_width=-strip_width))
fi

total=0
errcount=0
for file in $(ls "$2"/*.bmp);
do
    ((total++))
    printf "Processing $file:\n"
    error=$(./extractStrip -$strip_width $file 2>&1 >/dev/tty)
    if [ -n "$error" ]
    then
        ((errcount++))
        printf "An error occured during processing of file: $file\n"
        printf "Error message:\n"
        printf "$error\n\n"
    fi
done

printf "\n--------------------------\n"
printf "Total files processed: %d" $total
printf "\nErrors:                %d" $errcount
echo ""
