#include "ExplorationMarker.h"
#include "Cell.h"

ExplorationMarker EM_new(int nc, int nl){
	ExplorationMarker em = (ExplorationMarker)malloc(sizeof(ExplorationMarker));
	em->_nb_columns = nc;
	em->_nb_lines = nl;
	em->_array = (boolean*)calloc( nc*nl, sizeof(boolean) );
	return em;
}

void EM_free(ExplorationMarker em){
	free(em);
}

void EM_check(ExplorationMarker em, char *label){
	printf("%s:\n", label);
	for(int i=0;i < em->_nb_columns*em->_nb_lines;i++)
		printf("Cell %d = (%d,%d): %d\n", i+1, i%em->_nb_columns, i/em->_nb_columns, em->_array[i] );
}

void EM_clear(ExplorationMarker em){
	for(int i=0;i < em->_nb_columns*em->_nb_lines;i++)
		em->_array[i] = 0;
}

boolean EM_isMarked(ExplorationMarker em, Cell c){
	if(em->_array[c.x*em->_nb_lines+c.y] == 1)
		return 1;
	else 	return 0;
}

void EM_mark(ExplorationMarker em, Cell c){
	em->_array[c.x*em->_nb_lines+c.y] = 1;
}
