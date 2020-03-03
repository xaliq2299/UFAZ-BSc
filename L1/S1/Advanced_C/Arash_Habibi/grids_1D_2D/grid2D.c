
#include "grid.h"

//----------------------------------
Grid G_new(int width, int height)
{
	Grid thenew;
	thenew.width = width;
	thenew.height = height;
	thenew.array = (int**)calloc(height,sizeof(int*));
	if(thenew.array==NULL)
	{	printf("G_new : Calloc failed on thenew.array\n");
		exit(1);
	}
	for(int i=0; i<height; i++)
	{
		thenew.array[i]=(int*)calloc(width,sizeof(int));
		if(thenew.array[i]==NULL)
		{	printf("G_new : Calloc failed on thenew[%d]\n",i);
			exit(1);
		}
	}
	return(thenew);
}

//----------------------------------
int G_get(Grid g, int i, int j)
{
	return g.array[i][j];
}

//----------------------------------
void G_set(Grid g, int i, int j, int value)
{
	g.array[i][j]=value;
}

//----------------------------------
