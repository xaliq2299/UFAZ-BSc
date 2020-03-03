#include <stdio.h>
#define size1 5
#define size2 5

int main()
{
	int array1[size1] = {1, 8, 7, 6, 5};
	int array2[size2] = {52, 2, 3, 0, 4};

	for(int a=0;a<size1;a++)
	{
		for(int b=0;b<size2;b++)
		{	
			if(array1[a]==array2[b])
				{
				printf("These two tables have an intersection\n");
				return 1;
				}		
		}
	}

	printf("These two tables don't have an intersection\n");
	return 0;
}
