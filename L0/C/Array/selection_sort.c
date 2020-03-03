#include <stdio.h>

int main()
{
	int min;
	typedef char boolean;
	scanf("%d", &SIZE);
	
	puts("");
	
	int array[SIZE];
	boolean EM[SIZE];
	int other[SIZE];

	for(int a=0;a<SIZE;a++)
		scanf("%d", &array[a] );
		
	min = array[0];
		
	for(int a=1;a<SIZE;a++)
	{
		if(min>array[a] )
			min = array[a];
	}
	
	
}
