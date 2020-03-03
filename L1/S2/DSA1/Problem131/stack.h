#ifndef STACK
#define STACK

typedef struct Lifo{
	int iTop, nSize;
	double *pValueStack;
}SLifo;

int CLifo(SLifo *p, int s);
int CLifo_getSize(SLifo *p);
int CLifo_isFull(SLifo *p);
int CLifo_isEmpty(SLifo *p);
int CLifo_setSize(SLifo *p);
int CLifo_push(SLifo *p, double n);
double CLifo_pop(SLifo *p);
int CLifo_print(SLifo *p);
int d_CLifo(SLifo *p);

#endif
