#include <stdio.h>
#include <stdlib.h>
#include "DistField.h"

DistField DF_new(int Nx, int Ny)
{
	DistField df;
	df.width = Nx;
	df.height = Ny;
	df.array = (int**)calloc(Ny,sizeof(int*));
	
	if(df.array==NULL)
	{	printf("G_new : Calloc failed on thenew.array\n");
		exit(1);
	}
	
	for(int i=0; i<Ny; i++)
	{
		df.array[i]=(int*)calloc(Nx,sizeof(int));
		if(df.array[i]==NULL)
		{	printf("G_new : Calloc failed on thenew[%d]\n",i);
			exit(1);
		}
	}
	
	for(int a=0;a<Nx;a++)
	{
		for(int b=0;b<Ny;b++)
		df.array[a][b] = DF_INFINITY;
	}
	return(df);
}

int DF_get(DistField df, int x, int y)
{
	return df.array[x][y];	
}

void DF_set(DistField df, int x, int y, int val)
{	
	df.array[x][y] = val;
}

void DF_show(DistField df, char *label)
{
	for(int a=0;a<df.width;a++)
	{
		for(int b=0;b<df.height;b++)
			printf("%4d\n", df.array[a][b]);
		
		puts(""); 
	}
}

bool DF_propogate(DistField df, Cell c1, Cell c2)
{
	if(df.array[c2.x][c2.y] > df.array[c1.x][c1.y]+1)
	{
		df.array[c2.x][c2.y] = 1+df.array[c1.x][c1.y]; 
		return TRUE;
	}
	
	else
		return FALSE;
}

bool DF_propagatableLinkedCell(Maze mz, DistField df, Cell c, Cell *lnkneigh)
{
	//nb number of linked cells
	Cell linked_cells[4];
	int nb = CL_linkedCells(mz, c, linked_cells);
	
	for(int a=0;a<nb;a++)
	{
		if(df.array[linked_cells[a].x] [linked_cells[a].y] > 1+df.array[c.x][c.y])
		{
			lnkneigh = linked_cells[a];
			return TRUE;
		}	
	}
	return FALSE;
}

void DF_propagateUntilDeadEnd(Maze mz, DistField df, Stack ds)
{
	int check = 0;
	Cell c = ds->_array[ds->_first_free_place];

	Cell lnkneigh;
	Cell linked_cells[4];

	while(1)
	{
		int check = 0; // checking the equality with nb (number of linkes)
				
		if(CL_isTheSame(c, exit) == 1)
		else
		{
			int nb_links = DF_propagatableLinkedCell(mz, df, s->_array[s->_first_free_place-1], lnkneigh);
			int nb = CL_linkedCells(mz, lnkneigh, linked_cells);
			ds = ST_push(ds, ue_linked_cell);
			DF_set(df, int x, int y, int val);
			
			for(int a=0;a<nb_links;a++) 
			{
				if(df.array[ linked_cells[a].x] [linked_cells[a].y] == 1)
					check++;
			}
			
			if(check == nb)
		}
	}
}

bool DF_backTrackUntilFree(Maze mz, DistField df, Stack ds)
{
	
}
