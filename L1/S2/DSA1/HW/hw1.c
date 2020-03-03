#include <stdio.h>
#include <stdlib.h>

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
		   		   
		   if(empty_index < size)
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
		       empty_index++;
		   }
		   break;
	       }
	       case 0:
	           return 1;
	       default: continue;
	   }
	}
}
