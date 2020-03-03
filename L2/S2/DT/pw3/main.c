#include <stdio.h>
#include <stdlib.h>

typedef union{
	double num;
	unsigned long op_code;
}Union;

typedef struct {
	char *array;
	int size;
	int head_front, head_back;
}Stack;

Stack new_stack(int size){
	Stack s;
	s.size=size;
	s.array = malloc(sizeof(char)*size);
	s.head_front=0;
	s.head_back=size-1;

	return s;
}

void print_summary(Stack *s){
	printf("s->size=%d, s->head_front=%d, s->head_back=%d\n",
		    s->size, s->head_front, s->head_back);
}

void push_front(Stack *s, char c){
	s->array[s->head_front++]=c;
}


int main(){
	Union u;
	u.op_code=5;
	u.num=6;
	// printf("%lf\n", u.num);
	// printf("%ld\n", u.op_code);
	char exp[100];
	scanf("%s", exp);
	Stack s=new_stack(100);
	print_summary(&s);


	return 0;
}