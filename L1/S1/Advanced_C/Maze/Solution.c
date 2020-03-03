#include "Cell.h"
#include "ExplorationMarker.h"
#include "Stack.h"
#include "Maze.h"

int S_unexploredLinkedNeighbors(Maze mz, ExplorationMarker em, Cell c, Cell *ue_linked_cell){
	Cell linked_cells[4];
	int nb_cells = CL_linkedCells(mz,c,linked_cells);
	if( nb_cells != -1 ){
		for(int i=0;i<nb_cells;i++){
			if( EM_isMarked(em,linked_cells[i]) == 0){
				*ue_linked_cell = linked_cells[i];
				return 1;
			}
		}
	}
	return 0;
}

void S_trackBackUntilFree(Maze mz, Stack s, ExplorationMarker em){
	while(1){
		Cell cur; ST_top(s, &cur);
		Cell linked_cells[4];
		int nb_cells = CL_linkedCells(mz,cur,linked_cells);
		if( nb_cells != -1 ){
			for(int i=0;i<nb_cells;i++){
				if( EM_isMarked(em,linked_cells[i]) == 0)
					return;
			}
			s = ST_pop(s);
		}
	}
}

int S_advanceUntilBlockedOrFound(Maze mz, Stack s, ExplorationMarker em, Cell exit){
	Cell cur, ue_linked_cell;
	while(1){
		ST_top(s,&cur);
		if( S_unexploredLinkedNeighbors(mz,em,cur,&ue_linked_cell) ){
			s=ST_push(s, ue_linked_cell);
			EM_mark(em,ue_linked_cell);
			if( CL_isTheSame(ue_linked_cell,exit) )	  return 1;
			else continue;
		}
		else	return 0;
	}
}

void S_build(Maze mz, Cell *solution, int nb_cells){
	CL_setSolution(mz,solution,nb_cells);
}
