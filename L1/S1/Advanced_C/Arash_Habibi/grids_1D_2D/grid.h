#ifndef __GRID_H__
#define __GRID_H__

#include <stdio.h>
#include <stdlib.h>

struct g
{	int width, height;
//	int *array;   // in 1D
	int **array;  // in 2D
};

typedef struct g Grid;

//-------------------------------------------
// For two given integers, width and height,
// this function allocates and produces a
// grid structure with width columns and
// height rows. In case of failure, it returns
// NULL.

Grid G_new(int width, int height);

//-------------------------------------------
// For a given grid g, and two integers, i and j,
// this function returns the value of element
// in row i and in column j.
// Precondition : i belongs to [0,height-1]
// Precondition : j belongs to [0,width-1]

int G_get(Grid g, int i, int j);

//-------------------------------------------
// For a given grid g, and two integers, i and j,
// this function sets the value of element
// in row i and in column j to value.
// Precondition : i belongs to [0,height-1]
// Precondition : j belongs to [0,width-1]

void G_set(Grid g, int i, int j, int value);

#endif
