#include <stdio.h>
#include <stdlib.h>
#include <float.h>

typedef struct Lifo{
	int iTop, nSize;
	double *pValueStack;
}SLifo;

int CLifo(SLifo *p, int s){//constructor
	//p = (SLifo*) malloc(sizeof(SLifo));
	
	p->iTop = -1;
	p->nSize = s;
	p->pValueStack = (double *)malloc(sizeof(double)*s);
	
	return 0;
}

int CLifo_getSize(SLifo *p){
	return p->nSize;
}

int CLifo_isFull(SLifo *p)  {return p->iTop == p->nSize-1;}

int CLifo_isEmpty(SLifo *p) {return p->iTop == -1;}

/*int CLifo_setSize(SLifo *p){
	
}*/

int CLifo_push(SLifo *p, double n){
	if(CLifo_isFull(p)) {
		p->nSize+=3;
		CLifo_push(p, n);}
	else
		p->pValueStack[++p->iTop] = n;
	return 1;
}

double CLifo_pop(SLifo *p){
	if(CLifo_isEmpty(p))	return DBL_MAX;
	else if(p->nSize-p->iTop-1 >= 3)	p->nSize-=3;
	else  return p->pValueStack[p->iTop--];
}

int CLifo_print(SLifo *p){
	if(CLifo_isEmpty(p)) { printf("Stack is Empty!\n"); return 0; }
	for(int i=0;i<=p->iTop;i++)
		printf("%lf\t", p->pValueStack[i] );
	printf("\n");
	return 1;
}

int d_CLifo(SLifo *p){
	free(p->pValueStack);
	return 0;
}

int main(){
	SLifo *myStack;
	int n, c; double d;
	printf("Give us the size of the stack: ");
	scanf("%d", &n);
	if ( CLifo(myStack, n) != 0)	printf("Something is wrong !\n");
	
	do{
	printf("Choice, give\n1) to push value 2) pop 3) print all stack 4)quit 5)get size\n");
	scanf("%d", &c);
	switch(c){
		case 1: printf("Give a double to push it: "); scanf("%lf", &d);
				printf("%d\n", CLifo_push(myStack, d)); break;
 		case 2: printf("you POP the value %lf from the stack\n", CLifo_pop(myStack)); break; 
 		case 3: CLifo_print(myStack); break;
 		case 5: printf("%d\n", CLifo_getSize(myStack));
 	}}while(c!=4);
		
	return 0;
}
