#include <stdbool.h>
#include "numop.h"

#define DATA_TYPE NumOp

typedef struct
{
	DATA_TYPE* data;
	int hfr;
	int hbk;
	int sz;
} Stack;



Stack NewStack(int sz)
{
	Stack s;
	s.data = malloc(sz*sizeof(DATA_TYPE));
	s.hfr = sz/2;
	s.hbk = s.hfr+1;
	s.sz = sz;
	return s;
}

bool empty(Stack* s)
{
	return s->hfr == s->hbk-1;
}


void pushFront(Stack* s, DATA_TYPE no)
{
	if (s->hfr < 0)
		return;
	s->data[s->hfr--] = no;
}

void pushBack(Stack* s, DATA_TYPE no)
{
	if (s->hbk >= s->sz)
		return;
	s->data[s->hbk++] = no;
}


DATA_TYPE front(Stack* s)
{
	return s->data[s->hfr+1];
}

void popFront(Stack* s)
{
	if (!empty(s))
		s->hfr++;
}

DATA_TYPE back(Stack* s)
{
	return s->data[s->hbk-1];
}

void popBack(Stack* s)
{
	if (!empty(s))
		s->hbk--;
}

