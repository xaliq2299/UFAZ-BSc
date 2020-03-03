
#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include "Cell.h"

typedef struct st
{
	int _max_size;
	int _first_free_place;
	Cell *_array;
} StructStack, *Stack;

// This function allocates a new stack of cells with,
// at maximum, nb_max cells.
Stack ST_new(int nb_max);

// This function frees the memory allocated for s.
void ST_free(Stack s);

// This function prints on the terminal the contents
// of stack s.
void ST_check(Stack s, char *label);

// This function returns 1 if s is empty and 0 otherwise.
unsigned char ST_isEmpty(Stack s);

// This function returns 1 if s is full and 0 otherwise.
unsigned char ST_isFull(Stack s);

// This function adds cell c on the top of stack s.
Stack ST_push(Stack s, Cell c);

// This function removes the top of stack s.
Stack ST_pop(Stack s);

// This function returns the value of the top of stack s,
// i.e. the cell which was pushed (memorized) the last.
void ST_top(Stack s, Cell *c);

// This function returns the number of cells pushed in the stack.
int ST_size(Stack s);

// For a given stack s of cells and an array of cells (solution)
// This function copies in solution the contents of stack s.
int ST_export(Stack s, Cell *solution);

#endif
