
#ifndef __EXPLORATION_MARKER_H__
#define __EXPLORATION_MARKER_H__

#include <stdio.h>
#include <stdlib.h>

#include "Cell.h"

typedef unsigned char boolean;

typedef struct ie
{
	int _nb_columns, _nb_lines;
	boolean *_array;
} StructExplorationMarker, *ExplorationMarker;


// This function allocates an array of nc x nl of booleans.
// These booleans are initialized to false, which means that
// all the cells are, by default unexplored.
ExplorationMarker EM_new(int nc, int nl);

// This function frees the memory allocated by em.
void EM_free(ExplorationMarker em);

// This function prints on the screen the value
// of all the elements of em.
void EM_check(ExplorationMarker em, char *label);

// This function initializes the elements of em to 0
void EM_clear(ExplorationMarker em);

// This function indicates whether cell c was explored
// (return value : 1) or not (return value : 0)
boolean EM_isMarked(ExplorationMarker em, Cell c);

// This function marks cell c as explored.
void EM_mark(ExplorationMarker em, Cell c);

#endif
