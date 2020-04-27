#include <stdio.h>
#define SIZE 12

void read_integers(int size, int numbers[size]);

int main()
{
	int array[SIZE];
	
	read_integers(SIZE, array);
	
	return 0;
}



void read_integers(int size, int numbers[size])
{
	for(int a=0;a<size;a++)
	{
		printf("Enter number %d: ", a+1);
		scanf("%d", &numbers[a] );
	}
}
