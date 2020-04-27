//a program to multiply matrices
#include <stdio.h>

int main()
{
	int size1a, size1b, size2a, size2b, a, b, c;
	float sum;

	printf("Enter the size of first matrix: ");
	scanf("%d", &size1a);
	printf("by ");
	scanf("%d", &size1b);

	float array1[size1a][size1b];

	printf("Enter the size of second matrix: ");
	scanf("%d", &size2a);
	printf("by ");
	scanf("%d", &size2b);

	float array2[size2a][size2b];

	if(size1b==size2a)//if the multiplication is available
	{
		printf("Enter the elements of the first matrix:\n");//Entering the elements
		for(a=0;a<size1a;a++)
		{
			for(b=0;b<size1b;b++)
				scanf("%f", &array1[a][b]);
		}
	
		printf("Enter the elements of the second matrix:\n");//Entering the elements
		for(int a=0;a<size2a;a++)
		{
			for(b=0;b<size2b;b++)
				scanf("%f", &array2[a][b]);
		}

		for(a=0;a<size1a;a++)//The process happens here and
		{
			for(b=0;b<size2b;b++)
			{
				sum=0.;
				for(c=0;c<size2a;c++)
					sum+=(float)( array1[a][c]*array2[c][b] );
				printf("%4.1f", sum);		
			}
			puts("");			
		}//ends here
	}
	else//if we can't multiply matrices
	{
		printf("These matrices can't be multiplied\n");
		return 1;
	}
	
	return 0;
}
