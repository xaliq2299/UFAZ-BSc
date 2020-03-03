
#include "grid.h"

//----------------------------------
Grid G_new(int width, int height)
{
	Grid thenew;
	thenew.width = width;
	thenew.height = height;
	thenew.array = (int*)calloc(height*width,sizeof(int));
	if(thenew.array==NULL)
	{	printf("G_new : Calloc failed on thenew.array\n");
		exit(1);
	}
	return(thenew);
}

//----------------------------------
int G_get(Grid g, int i, int j)
{
	return g.array[g.width*i + j];
}

//----------------------------------
void G_set(Grid g, int i, int j, int value)
{
	g.array[g.width*i+j]=value;
}

//----------------------------------
