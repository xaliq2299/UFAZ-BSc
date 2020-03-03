#include "stack.h"

struct stack ST_new(){
	struct stack st;
	st.size = 0;
	return st;
}

void ST_print(struct stack st){
	for(int i=0;i<st.size;i++)
		printf("%4d", st.array[i]);
	printf("\n");
}

int ST_size(struct stack st){
	return st.size;
}

struct stack ST_push(struct stack st, int n){
	if(st.size < N)
		st.array[st.size++] = n;
	else
		printf("The stack is full!\n");
	return st;
}

struct stack ST_pop(struct stack st){
	if(st.size != 0)
		st.size--;
	else
		printf("The stack is empty!\n");
	return st;
}

int ST_top(struct stack st){
	if(st.size == 0){
		printf("The stack is empty!\n");
		return st.size-1;
	}
	else
		return st.array[st.size-1];
}
