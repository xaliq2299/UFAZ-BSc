#include "Cell.h"
#include "Maze.h"

Cell CL_new(int x, int y){
	Cell c;
	c.x = x; c.y = y;
	return c;
}

void CL_free(Cell c){
	//free(&c);
}

void CL_check(Cell c, char *label){
	printf("%s = (%d,%d)\n", label, c.x, c.y);
}

int CL_isTheSame(Cell c1, Cell c2){
	if(c1.x == c2.x && c1.y == c2.y)	
		return 1;
	else 	return 0;
}

Cell CL_entrance(Maze mz){
	Cell entrance;
	MZ_entrance(mz, &entrance.x, &entrance.y);
	return entrance;
}

Cell CL_exit(Maze mz){
	Cell exit;
	MZ_exit(mz, &exit.x, &exit.y);
	return exit;
}

int CL_linkedCells(Maze mz, Cell c, Cell linked_cells[]){
	int linked_ints[8], j=0;
	int nb_cells = MZ_linkedCells(mz, c.x, c.y, linked_ints);
	if(nb_cells == -1){
		printf("The given cell (%d,%d) is not in the Maze.\n", c.x, c.y);
		return -1;
	}
	else{
		for(int i=0;i<nb_cells;i++){
			linked_cells[i] = CL_new(linked_ints[j], linked_ints[j+1]);
			j+=2;
		}
	}
	return nb_cells;
}

void CL_setSolution(Maze mz, Cell solution_cells[], int nb_cells){
	int solution_ints[2*nb_cells], j=0;
	for(int i=0;i<nb_cells;i++){
		solution_ints[j++] = solution_cells[i].x;
		solution_ints[j++] = solution_cells[i].y;
	}
	MZ_setSolution(mz, solution_ints, nb_cells);
}
