#include <stdio.h>
#include <stdlib.h>
#include "Cell.h"
#include "ExplorationMarker.h"

ExplorationMarker EM_new(int nc, int nl)
{
	StructExplorationMarker ene;
	ExplorationMarker em;
	em=&ene;
	
	//ExplorationMarker em = malloc(sizeof(ExplorationMarker));
		
	em->_nb_columns = nc;
	em->_nb_lines = nl;

	em->_array = calloc( (nc*nl), sizeof(boolean) ); // calloc initializes the elements of this array to 0 by default

	return em;
}

void EM_free(ExplorationMarker em)
{
	free(em);
}

void EM_check(ExplorationMarker em, char *label)
{
	printf("%d x %d boolean array\n", em->_nb_lines, em->_nb_columns);
	
	for(int a=0;a<em->_nb_lines;a++)
	{
		for(int b=0;b<em->_nb_columns;b++)
			printf("%u\n", em->_array[b+(em->_nb_lines*a)] ); //or %hhi
	}
}

void EM_clear(ExplorationMarker em)
{
	for(int a=0;a<em->_nb_lines;a++)
	{
		for(int b=0;b<em->_nb_columns;b++)
			em->_array[b+(em->_nb_lines*a)] = 0;
	}
}

boolean EM_isMarked(ExplorationMarker em, Cell c)
{
	if (em->_array[c.x+c.y*em->_nb_lines] == 1)
		return 1;
	else
		return 0;
}

void EM_mark(ExplorationMarker em, Cell c)
{
	em->_array[c.x+c.y*em->_nb_lines] = 1;
}
