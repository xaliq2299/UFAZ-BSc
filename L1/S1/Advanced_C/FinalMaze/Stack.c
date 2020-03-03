#include <stdio.h>
#include <stdlib.h>
#include "Cell.h"
#include "Stack.h"

Stack ST_new(int nb_max)
{
	StructStack st;
	Stack s;
	
	s = &st;
	//Stack s = malloc(sizeof(Stack));
	
	s->_max_size = nb_max;
	s->_first_free_place = 0;
	s->_array = calloc(nb_max, sizeof(Cell) );
		
	return s;
}

void ST_free(Stack s)
{
	free(s);
}

void ST_check(Stack s, char *label)
{
	printf("The max size: %d\n", s->_max_size );
	for(int a=0;a<s->_first_free_place;a++)
		CL_check(s->_array[a], label);
}

unsigned char ST_isEmpty(Stack s)
{
	 if(s->_max_size - s->_first_free_place > 0)
	 	return 1;
	 else
	 	return 0; 
}

unsigned char ST_isFull(Stack s)
{
	if(s->_max_size - s->_first_free_place <= 0)
		return 1;
	else
		return 0;
}

Stack ST_push(Stack s, Cell c)
{
	s->_array[s->_first_free_place].x = c.x;
	s->_array[s->_first_free_place].y = c.y;

	s->_first_free_place+=1;

	return s;
}

Stack ST_pop(Stack s)
{
	s->_first_free_place-=1;

	return s;
}

void ST_top(Stack s, Cell *c)
{
	c->x=s->_array[s->_first_free_place-1].x;
	c->y=s->_array[s->_first_free_place-1].y;
}

int ST_size(Stack s)
{
	return s->_first_free_place; 
}

int ST_export(Stack s, Cell *solution)
{
	for(int a=0;a<s->_first_free_place;a++)
	{
		solution[a].x = s->_array[a].x;
		solution[a].y = s->_array[a].y;
	}

	return s->_first_free_place;
}
