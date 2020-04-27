#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int array[4][4];
	int n, a, b;
	srand(time(NULL));

	FIND:
	{
		for(a=0;a<4;a++)
		{
			for(b=0;b<4;b++)
			array[a][b] = 0;
		}
	
		for(n=1;n<=16;n++)
		{
			a=rand()%4;
			b=rand()%4;
			if(array[a][b] == 0)
				array[a][b] = n;
			else
				n--;
		}
			
		for(a=0;a<4;a++)
		{
			for(b=0;b<4;b++)
				printf("%3d", array[a][b]);
			puts("");
		}	
	}

	int vert1 = array[0][0]+array[1][0]+array[2][0]+array[3][0];
	int vert2 = array[0][1]+array[1][1]+array[2][1]+array[3][1];
	int vert3 = array[0][2]+array[1][2]+array[2][2]+array[3][2];
	int vert4 = array[0][3]+array[1][3]+array[2][3]+array[3][3];
	int hort1 = array[0][0]+array[0][1]+array[0][2]+array[0][3];
	int hort2 = array[1][0]+array[1][1]+array[1][2]+array[1][3];
	int hort3 = array[2][0]+array[2][1]+array[2][2]+array[2][3];
	int hort4 = array[3][0]+array[3][1]+array[3][2]+array[3][3];
	int diag1 = array[0][0]+array[1][1]+array[2][2]+array[3][2];
	int diag2 = array[0][3]+array[1][2]+array[2][1]+array[3][0];

	if(vert1==34&&vert2==34&&vert3==34&&vert4==34&&hort1==34&&hort2==34&&hort3==34&&hort4==34&&diag1==34&&diag2==34)
	{	
		for(a=0;a<4;a++)
		{
			for(b=0;b<4;b++)
				printf("%3d", array[a][b]);
			puts("");
		}
	}
	else
		goto FIND;

	return 0;
}
/*
 1  2  3  4 
 5  6  7  8
 9 10 11 12
13 14 15 16
*/
