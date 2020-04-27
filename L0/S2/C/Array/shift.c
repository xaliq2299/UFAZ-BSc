//shifting to the right
#include <stdio.h>

void print(int array[], int SIZE )
{
	for(int a=0;a<SIZE;a++)
		printf("%3d", array[a] );

	puts("");
}


int main()
{
	int array[10] = { 0,1,2,3,4,5,6, 7, 8, 9 };
	
	print(array, 10);
	
	for(int i=8;i>=0;i--)
		array[i+1] = array[i];

	print(array,10);
	
	return 0;
}
