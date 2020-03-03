#include <stdio.h>

int find_det(int size, int array[size][size]);

void main()
{
	int matrix[4][4] = { {5, 3, -4, 2}, {0, 2, 11, 3}, {7, -1, 9, 0}, {10, 2, 0, 4} };
	int a, b, c, check, det=0, flag=0;
	int array[2][2];

	for(a=0;a<4;a++)
	{
		for(b=0;b<4;b++)
			printf("%3d", matrix[a][b] );
		puts("");
	}

	for(a=flag;a<4;a++)
	{
		check=0;//Really nigga?		
		for(b=flag;b<4;b++)
		{
			for(c=flag;c<4;c++)
			{
				if(b!=flag && c!=a)
				{			
					check++;			
					printf("%3d", matrix[b][c]);
					/*if(check == 1)				
						array[0][0] = matrix[b][c];
					if(check == 2)				
						array[0][1] = matrix[b][c];
					if(check == 3)				
						array[1][0] = matrix[b][c];
					if(check == 4)				
						array[1][1] = matrix[b][c];*/
				}
			}
			puts("");
		}
		if(check==4)
		{	
			printf("%d\n", find_det(2, array) );		
		
			if(a%2 == 0)		
				det=det+find_det(2, array)*matrix[0][a];
			else
				det=det-find_det(2, array)*matrix[0][a];
		}
		else
		{
			flag++;			

		}

	}
	printf("Det is %d\n", det);
}


int find_det(int size, int array[size][size])
{
	int det;
	det=array[0][0]*array[1][1]-array[1][0]*array[0][1];
}
