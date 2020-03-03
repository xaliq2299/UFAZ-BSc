#include <stdio.h>
#include "BSTree.h"
#include "queue.h"


int main(){
	BSNode *BStree=NULL;
	int d=0, s; int *number; number=&d;	
	//Add Nodes
	int tab[]={50,25,75,12,27,55,90,10,14,26,40,52,57,85,95};
	for (int i=0;i<15;i++) BStree=add(BStree, tab[i]);

	  //queue
   SFifo myFifo;

//   printf("Enter a queue size: ");scanf("%d",&n);
   if (constructFifo(&myFifo,treeNodeNumber(BStree, &d))){
     fprintf(stderr,"Error creating the queue\n");
     return 1;
   }
	
	for(int i=0;i<treeDepth(BStree);i++){
		treePrintLevel(BStree, i, &myFifo);
		while(1){ //we do it until it is empty to print all of them
			printf("%3d", deQueue(&myFifo) );
		}
		myFifo.iEnQueue = 0;
		myFifo.iDeQueue = -1;
	}
	
	return 0;
}
