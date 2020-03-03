echo "**** Analysing file $1 ****"
echo ""
echo "1. Name of the organism"
echo "2. Number of genes"
echo "3. Number of genes on the main strand"
echo "4. Nombre de genes on the complement strand"
echo "5. sequence in bases"
echo "6. whole nucleic sequence"
echo "7. Number of occurences of a pattern in a sequence"
echo ""
echo "8. End"
echo ""
read -p "Your choice: " choice

case $choice in
1)
	#while read -r line
	#do
		#name=$(echo $line | cut -d ' ' -f1)
		#if [ $name == "SOURCE" ]; then
		#	awk '$1 = '' {print}'
		#awk '$1=="SOURCE" {print} ' $1 | awk '{sub(/SOURCE$/, ""); print }' $1
		#awk -F':' '$2 != "5C" {print $0}' fich_sed
		#sed -n '/SOURCE/ p' $1
	#		break
		#	awk -F':' '{sub(/ STEPHANE$/," STANISLAS",$1);print $0}' fich_sed
		
		awk '{if ( $1 == "SOURCE") {$1=""; print;}}' $1
	#done < $1
	
	;;
*)	echo "You entered smth else"
	
	;;
esac
