#ifndef __STACK__
#define __STACK__

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



Stack NewStack(int sz);

bool empty(Stack* s);

void pushFront(Stack* s, DATA_TYPE no);

void pushBack(Stack* s, DATA_TYPE no);

DATA_TYPE front(Stack* s);

void popFront(Stack* s);

DATA_TYPE back(Stack* s);

void popBack(Stack* s);

#endif // __STACK__
