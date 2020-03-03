#include "stack.h"

int main(){
	struct stack st = ST_new();
	ST_print(st);
	st = ST_push(st, 1);
	ST_print(st);	
	st = ST_push(st, 5);
	ST_print(st);	
	st = ST_push(st, 2);
	ST_print(st);	
	st = ST_push(st, 7);
	ST_print(st);
	st = ST_pop(st);
	ST_print(st);	
	st = ST_pop(st);
	ST_print(st);	
	st = ST_pop(st);
	ST_print(st);	
	st = ST_push(st, 3);
	ST_print(st);
	st = ST_push(st, 10);
	ST_print(st);
	st = ST_pop(st);
	ST_print(st);	
	st = ST_pop(st);
	ST_print(st);	
	st = ST_pop(st);
	ST_print(st);
	
	return 0;
}
