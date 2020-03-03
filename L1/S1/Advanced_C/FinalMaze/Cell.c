#include <stdio.h>
#include <stdlib.h>
#include "Maze.h"
#include "Cell.h"

Cell CL_new(int x, int y)
{
	Cell c;

	c.x=x;
	c.y=y;
	
	return c;
}

void CL_free(Cell c)
{
	//free(c); // couldn't use free function in this case
}

void CL_check(Cell c, char *label)
{
	printf("(%d, %d)\n", c.x, c.y);
}

int CL_isTheSame(Cell c1, Cell c2)
{
	if(c1.x == c2.x && c1.y == c2.y)
		return 1;
	else
		return 0;
}

Cell CL_entrance(Maze mz)
{
	Cell c;
	
	MZ_entrance(mz, &c.x, &c.y);
	
	return c;	
}

Cell CL_exit(Maze mz)
{
	Cell c;
	
	MZ_exit(mz, &c.x, &c.y);
	
	return c;
}

int CL_linkedCells(Maze mz, Cell c, Cell linked_cells[])
{
	int a, b;
	int links[8];
	int nb_links = MZ_linkedCells(mz, c.x, c.y, links);
	
	for(a=0, b=0;a<2*nb_links;a+=2, b++)
		linked_cells[b].x = links[a];
	
	for(a=1, b=0;a<2*nb_links;a+=2, b++)
		linked_cells[b].y = links[a];

	return nb_links;
}

void CL_setSolution(Maze mz, Cell solution_cells[], int nb_cells)
{
	int a, b;
	int solution[2*nb_cells];
		
	for(a=0, b=0;a<2*nb_cells;a+=2, b++)
		solution[a] = solution_cells[b].x;			

	for(a=1, b=0;a<2*nb_cells;a+=2, b++)
		solution[a] = solution_cells[b].y;
	
	MZ_setSolution(mz, solution, nb_cells);
}
