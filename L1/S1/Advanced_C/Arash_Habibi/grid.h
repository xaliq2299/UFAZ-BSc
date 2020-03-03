#ifndef __GRID_H__
#define __GRID_H__

#include <stdio.h>

struct g
{
	int width, height;
	int **array;
};

typedef struct g Grid;

Grid G_new(int width, int height);
int G_get(int i, int j);
void G_set(int i, int j, int value);


#endif
