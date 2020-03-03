#include <stdio.h>
#include <stdlib.h>
#define N 100

struct stack {
	int array[N];
	int size;
};

struct stack ST_new();
void ST_print(struct stack st);
int ST_size(struct stack st);
struct stack ST_push(struct stack st, int n);
struct stack ST_pop(struct stack st);
int ST_top(struct stack st);
