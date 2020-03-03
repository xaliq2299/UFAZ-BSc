/*********************************/
/**** Intelligent -STACK     *****/
/*********************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct Lifo {
  int iTop, nSize;
  double *pValueStack;
} SLifo;

int CLifo(SLifo *p, int s);
int CLifo_getSize(SLifo *p);
int CLifo_setSize(SLifo *p);
int CLifo_push(SLifo *p, double n);
int CLifo_pop(SLifo *p);
int CLifo_print(SLifo *p);
int d_CLifo(SLifo *p);

int main(){
	int n;
	SLifo myStack;

	printf("Enter a stack size: "); scanf("%d",&n);
	if (CLifo(&myLifo,n)){
    	fprintf(stderr,"Error creating the stack\n");
   	 	return 1;
  	}
  
	printf("Push numbers (end with -1)\n");
	while (n!=-1){
		scanf("%d",&n);
    	if (n==-1) break;
   	 	CLifo_push(&myLifo,n);
  	}

  	d_CLifo(&myLifo);
	return 0;
}
