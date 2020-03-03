
#include <stdio.h>
#include <stdlib.h>
#include "grid.h"

int main()
{
	Grid g = G_new(6,9);

	int count = 0;
	for(int i=0; i<g.height; i++)
		for(int j=0; j<g.width; j++)
			G_set(g,i,j,count++);

	for(int i=0; i<g.height; i++)
	{	for(int j=0; j<g.width; j++)
			printf("%d ",
				G_get(g,i,j));
		printf("\n");
	}
	return 0;
}
