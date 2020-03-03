#ifndef __CELL_H__
#define __CELL_H__

#include <stdio.h>
#include <stdlib.h>

#include "Maze.h"

typedef struct
{
	int x, y;
} Cell;

// From two integers representing the column and the row of a cell,
// this function creates and returns a cell with those coordinates

Cell CL_new(int x, int y);

// This function frees the memory allocated by cell c.
void CL_free(Cell c);

// This function prints on the terminal the coordinates of cell c,
// along with a label which identifies the output.
void CL_check(Cell c, char *label);

// For two given cells, c1 and c2, this function returns 1 if
// both cells have the same coordinates and 0 otherwise.
int CL_isTheSame(Cell c1, Cell c2);

// For a give maze mz, this function returns a cell representing the
// position of the entrace cell of mz.
Cell CL_entrance(Maze mz);

// For a give maze mz, this function returns a cell representing the
// position of the exit cell of mz.
Cell CL_exit(Maze mz);

// For a give maze mz, for a given cell c in this maze, and an array
// of at least 4 cells, this function fills the array with the linked
// neighbors of c. There are not necessarily 4 linked neighbors. The
// return value indicates the number of linked neighbors.
int CL_linkedCells(Maze mz, Cell c, Cell linked_cells[]);

// For a given maze mz and an array of nb_cells cells, this function
// memorizes this set of cells and considers it as a proposed solution.
// It does not check if the solution is correct. But when the maze
// is saved as in image file, the proposed solution will be represented
// in orange.
void CL_setSolution(Maze mz, Cell solution_cells[], int nb_cells);

#endif
