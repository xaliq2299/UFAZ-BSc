#include <stdio.h>
#include <stdlib.h>

void print_array(int array[], int size)
{
	for(int a=0;a<size;a++)
		printf("%4d", array[a] );
	puts("");
}

int * reallocation(int old_array[], int old_size, int new_size)
{
	int *new_array = malloc(sizeof(int)*new_size);
	
	for(int a=0;a<old_size;a++)
		new_array[a] = old_array[a];
	
	//free(old_array);
	return new_array;
}

int addValue(int value, int array[], int size, int *empty_index)
{		   		   
	if(*empty_index < size)
	{
	       array[*empty_index] = value;
	       (*empty_index)++;
	}
	else
	{
	       //int *array = malloc(sizeof(int)*size);
	       //for(int a=0;a<size;a++)
	       	//	array[a] = table[a];
	       
	       //for(int a=0;a<empty_index;a++)
	       //table[a] = array[a];
		 
	       //free(array);
	  
	       array = reallocation(array, size, size+5);
	  	size+=5;
	       array[*empty_index] = value;
	       (*empty_index)++;      
	       print_array(array, size);
	}
	return size;
}

int main()
{
	int number, size = 5, empty_index=0;
	int *table = malloc(sizeof(int)*size);
	int answer;

	while(1)
	{
	   printf("Do you want to enter a new value? (Enter 1 for Yes / 0 for No)\n");
	   scanf("%d", &answer);
	
	   switch(answer)
	   {
	       case 1: 
	       {
		   printf("Enter a new value: ");
		   scanf("%d", &number);
		   size=addValue(number, table, size, &empty_index);
		   
		   /*if(empty_index < size)
		   {
		       table[empty_index] = number;	
		       empty_index++;
		   }
		   else
		   {
		       int *array = malloc(sizeof(int)*size);
		       for(int a=0;a<size;a++)
		           array[a] = table[a];
		
		       size+=5;
		       table = malloc(sizeof(int)*size);
		       for(int a=0;a<empty_index;a++)
		           table[a] = array[a];
		 
		       free(array);
		       table[empty_index] = number;
		       empty_index++;*/
	           break;
	       }
	       case 0:
	           print_array(table, size);
	           return 1;
	       default: continue;
	   }
	}
}
