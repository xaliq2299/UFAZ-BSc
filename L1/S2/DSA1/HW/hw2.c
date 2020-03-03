//=========================================
//Khaliq Aghakarimov CS1
//04.03.2018
//=========================================

//Code solution
/*
#include <stdlib.h>
function that returns pointer to the array(array, size, pointer to the variable empty_index)
{
	if array[1] == 0 (Which means we have only one element in array)
		print "We cant delete anymore"
		end
	endif
		
	array[empty_index-1] = 0	
	empty_index-=1	
         
	if size - empty_index >= 5 (which means we have empty places more than or equal to 5)
	      size-=5;
	
	print "You deleted one"
	   
	return the pointer of array;
}

main()
{
	size = 15 (I chose size of an array bu default)
	pointer to table
	
	print "Enter the size: "
	get size of the array from the user
	allocate dynamically an array of <size> elements (test whether the allocation is done correctly) 
	empty_index = size (The variable which allows us to know the first empty place starting from the beginning)  	

	initialize ur array with some numbers to be able to delete some values(but 0 values are not allowed, since they will be considered as the empty places)
	
	while true
	   print "Do you want to delete the last element?"
	   get answer from the user
	
	   if yes:
		call function delete_value
		print the whole table
	   if no:
	       	printf "Process of deleting finished"
	        exit
	   else: continue;
	   endif
	endwhile
}
*/

#include <stdio.h>
#include <stdlib.h>

void print_array(int array[], int size)
{
	for(int a=0;a<size;a++)
	{	
		if(array[a] == 0)
			break;
		printf("%4d", array[a] );
	}
	puts("");
}

int *delete_value(int array[], int size, int *empty_index)
{
	if(array[1] == 0)
   	{	
   		printf("There is one element remaining in the table\nYou can not delete anymore\n");
		exit(0);
	}	  		   
	    array[(*empty_index)-1] = 0;	
            (*empty_index)--;
		   
	   if (size - (*empty_index) >= 5)
	      size-=5;
	   
	   printf("You deleted one\n");
	   
	   return array;
}

int main()
{
	int size;
	int answer;	
	
	printf("Size: ");
	scanf("%d", &size);
	int *table = malloc(sizeof(int)*size);
	int empty_index = size;	

	for(int a=0;a<size;a++)
		table[a] = a+1;
	
	while(1)
	{
	   printf("Do you want to delete the last element? (Enter 1 for Yes / 0 for No)\n");
	   scanf("%d", &answer);
	
	   switch(answer)
	   {
	       case 1: 
	       {
		   table = delete_value(table, size, &empty_index);
		   print_array(table, size);
		   break;
	       }
	       case 0:
	       	   printf("Process of deleting finished\n");
	           return 0;
	       default: printf("Nothing changed\n"); continue;
	   }
	}
}
