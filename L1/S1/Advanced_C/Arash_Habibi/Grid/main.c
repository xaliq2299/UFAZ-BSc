#include <stdio.h>
#include <stdlib.h>
#include "grid.h"

int main()
{
	Grid g = G_new(6, 9);
	
	int count = 0;
	for(int i=0;i<g.height;i++)
		for(int j=0;j<g.width;j++)
			G_set(g,i,j,count++);
	
	for(int i=0;i<g.height;i++)
	{
		for(int j=0;j<g.width;j++)
			printf("%3d", G_get(g,i,j) );
		printf("\n");
	}
	
	/*
	int count=1;
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			grid[i][j] = count;
			count++;
		}
	}
	
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			printf("%3d", grid[i][j] );
		}
		puts("");
	}
	*/
	
	return 0;
}
