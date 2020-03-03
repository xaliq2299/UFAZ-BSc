#include "Stack.h"
#include "Cell.h"

Stack ST_new(int nb_max){
	Stack s = (Stack)malloc(sizeof(Stack));
	s->_max_size = nb_max;
	s->_first_free_place = 0;
	s->_array = (Cell*)malloc(sizeof(Cell)*nb_max);
	return s;
}

void ST_free(Stack s){
	free(s);
}

void ST_check(Stack s, char *label){
	printf("%s:\n", label);
	for(int i=0;i<s->_first_free_place;i++){
		printf("%dth ", i+1);
		CL_check(s->_array[i],"Cell");
	}
}

unsigned char ST_isEmpty(Stack s){
	if(s->_first_free_place == 0)	return 1;
	else if(s->_first_free_place > 0)	return 0;
	printf("[!] The index is negative.\n"); return -1;
}

unsigned char ST_isFull(Stack s){
	if(s->_first_free_place == s->_max_size)
		return 1;
	else 	return 0;
}

Stack ST_push(Stack s, Cell c){
	if(s->_first_free_place <= s->_max_size-1)
		s->_array[s->_first_free_place++] = c;
	else
		printf("[!] The stack is full: Pushing failed.\n"); 
	return s;
}

Stack ST_pop(Stack s){
	if(s->_first_free_place == 0)
		printf("[!] The stack is empty: Popping failed.\n");
	else
		s->_first_free_place--;
	return s;
}

void ST_top(Stack s, Cell *c){
	if(s->_first_free_place-1 < 0)
		printf("[!] The stack is empty: There's no top element.\n");
	else
		*c = s->_array[s->_first_free_place-1];
}

int ST_size(Stack s){
	return s->_first_free_place;
}

int ST_export(Stack s, Cell *solution){
	if(s->_first_free_place == 0){
		printf("[!] The stack is empty.\n");
		return 0;
	}
	for(int i=0;i<s->_first_free_place;i++)
		solution[i] = s->_array[i];
	return s->_first_free_place;
}
