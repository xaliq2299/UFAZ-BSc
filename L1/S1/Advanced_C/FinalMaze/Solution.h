#ifndef __SOLUTION_H__
#define __SOLUTION_H__

#include <stdio.h>
#include <stdlib.h>

#include "Cell.h"
#include "ExplorationMarker.h"
#include "Stack.h"
#include "Maze.h"

// For a given maze mz, the exploration marker em, and a given
// cell c, this function puts in ue_linked_cell one unexplored
// linked neighbor of c.
int S_unexploredLinkedNeighbors(Maze mz, ExplorationMarker em, Cell c, Cell *ue_linked_cell);

// For a given maze mz, a stack of cells s and the exploration
// marker em, this function removes elements from the top of the
// stack (pop) until it finds a cell with unexplored linked neighbors.
void S_trackBackUntilFree(Maze mz, Stack s, ExplorationMarker em);

// For a given maze mz, a stack of cells s, the exploration
// marker em and the exit cell (exitt), this function assumes that
// the top of the stack has unexplored linked cells and steps
// forward until it meets the exit cell or until it finds no more
// unexplored linked neighbors (dead-end).
int S_advanceUntilBlockedOrFound(Maze mz, Stack s, ExplorationMarker em, Cell c, int is_random);

// For a given maze mz, and an array of integers : solution, with
// nb_cells cells allocated, this function fills solution with the
// the positions of the solution cells and returns the length of
// this solution.
int S_build(Maze mz, Cell *solution, int is_random);

#endif
