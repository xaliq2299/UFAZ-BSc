//a program for transpose of a matrix
#include <stdio.h>

int main()
{
	int column, row, a, b;	

	printf("Enter the size of the matrix: ");
	scanf("%d", &row);
	printf("by ");		
	scanf("%d", &column);

	int array[column][row];		
		
	printf("Enter the elements of the matrix of size %dx%d:\n", row, column);
	
	for(a=0;a<row;a++)
	{
		for(b=0;b<column;b++)
			scanf("%d", &array[a][b] );
	}

	for(b=0;b<column;b++)
	{
		for(a=0;a<row;a++)
			printf("%3d", array[a][b] );
	
		puts("");
	}

	return 0;
}
