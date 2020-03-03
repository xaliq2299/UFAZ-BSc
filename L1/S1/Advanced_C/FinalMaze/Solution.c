#include <stdio.h>
#include <stdlib.h>
#include "Cell.h"
#include "ExplorationMarker.h"
#include "Stack.h"
#include "Maze.h"
#include "Solution.h"

int S_unexploredLinkedNeighbors(Maze mz, ExplorationMarker em, Cell c, Cell *ue_linked_cell)
{
	Cell linked_cells[4];
	
	int nb_links = CL_linkedCells(mz, c, linked_cells);
	
	for(int a=0;a<nb_links;a++)
	{
		if(em->_array[ linked_cells[a].x + em->_nb_lines*linked_cells[a].y ] == 0)
		{	
			ue_linked_cell->x = linked_cells[a].x;
			ue_linked_cell->y = linked_cells[a].y;
		}
	}
	
	return nb_links;
}

void S_trackBackUntilFree(Maze mz, Stack s, ExplorationMarker em)
{
	Cell linked_cells[4];
	
	for(int a=s->_first_free_place-1;;a--)
	{
		int check=0; // it will check if all linked neighbors are explored or not
		int nb_links = CL_linkedCells(mz, s->_array[a], linked_cells);
		
		for(int b=0;b<nb_links;b++)
		{
			if(em->_array[ linked_cells[b].x + em->_nb_lines*linked_cells[b].y ] == 1)
				check++;
		}
		 
		if(check == nb_links)
			s = ST_pop(s);
		else
			break;
	}
}

int S_advanceUntilBlockedOrFound(Maze mz, Stack s, ExplorationMarker em, Cell c, int is_random)
{
	Cell ue_linked_cell;
	Cell linked_cells[4];

	while(1)
	{
		int check = 0; // checking the equality with nb (number of linkes)
				
		if(s->_array[s->_first_free_place-1].x == c.x && s->_array[s->_first_free_place-1].y == c.y)
			return 1;
		else
		{
			int nb_links = S_unexploredLinkedNeighbors(mz, em, s->_array[s->_first_free_place-1], &ue_linked_cell);
			int nb = CL_linkedCells(mz, ue_linked_cell, linked_cells);
			s = ST_push(s, ue_linked_cell);
			EM_mark(em, ue_linked_cell);
			
			for(int a=0;a<nb_links;a++) 
			{
				if(em->_array[ linked_cells[a].x + linked_cells[a].y*em->_nb_lines ] == 1)
					check++;
			}
			
			if(check == nb)
			return 0;
		}
	}
}
