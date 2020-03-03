#!/bin/bash
echo $#
if [[ $# == 1 ]]
then
clear
echo "**** Analyse of data file $1 ****"
echo "1. Name of the Laboratory"
echo "2. Name of the gene"
echo "3. Number of genes on the principal branch"
echo "4. Number of genes on the complemantary branch"
echo "5. Base sequence"
echo "6. Complete Nucleic Sequences"
echo "7. Number of apparition of data in the nucleic sequence"
echo 
echo "8. Terminate the program"
echo
echo "Your Choice:"

read choix

case $choix in
	
	"1")
		echo "Name of the Laboratory:"
		sed '/ORGANISM/!d' $1 | sed -e 's/\( ORGANISM \) \(.*\)/\2/'
	;;

	"2")
		echo "Name of the gene:"
		sed '/[ ]*  gene  [ ]*/!d' $1 | wc -l #sed -n '$=' wc is more useful for one matching, wc show 0 and sed -n '$=' doesnt show anything
	;;
		
	"3")
		echo "Number of genes on the principal branch:"
		sed '/[ ]*  gene  [ ]*/!d' $1 | sed '/complement/d' | wc -l #sed -n '$=' idem
	;;
	
	"4")
		echo "Number of genes on the complemantary branch:"
		sed '/[ ]*  gene  [ ]*.*complement.*/!d' $1 | wc -l #sed -n '$=' idem
	;;

	"5")
		echo "Base sequence:"
		sed -n '/^ORIGIN */,/[/][/]/p' $1 | sed '$d' 
	;;
	
	"6")
		#Impossible to delete the return to line with sed, command tr obligatory
		echo "Complete Nucleic Sequences:"
		sed -n '/^ORIGIN */,/[/][/]/p' $1 | sed '$d' |sed -e 's/\( *[0-9]* \)\(.*\)/\2/' | tr '\n' ' '
		echo 
	;;
	
	"7")
			echo "for what you need to search:"
			read MOTIF
							
			#Verification the motif continue
			echo $MOTIF | sed '/[cagt]\+/!d' 1>/dev/null


				sed -n '/^ORIGIN */,/[/][/]/p' $1 | sed '$d' |sed -e 's/\( *[0-9]* \)\(.*\)/\2/'| tr ' ' '\n'  | awk '/'"$MOTIF"'/{x+=1}END{print x}'
			

	;;
	

esac 
else
echo "USAGE: You should give at least 1 argument"
fi

