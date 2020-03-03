#include <stdio.h>
#include "stack.h"
#include "LL.h"

int main(){
	SNode *myList = NULL;
	SLifo *myStack;
		
	for(int i=0;i<10;i++)
		LL_add(&myList, i);
	if( CLifo(myStack, 10) )
		fprintf(stderr, "Problem with constructing Stack\n");

	LL_Print(myList);

	while(myList != NULL){
		CLifo_push(myStack, myList->nVal);
		myList = myList->pNext;
	}
	
	while( CLifo_isEmpty(myStack) == 0)
		printf("%lf\n", CLifo_pop(myStack) );

	return 0;
}
