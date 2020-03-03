/***************************************/
/*** Creating an "intelligent" queue ***/
/***************************************/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
/*typedef struct Fifo {
  int iEnQueue, iDeQueue, nSize;
  int* pFifo;
} SFifo;

int constructFifo(SFifo *p, int n); // signature of the function
int enQueue(SFifo *p, int n);
int deQueue(SFifo *p);
int destructFifo(SFifo *p);
*/
int enQueue(SFifo *p, int n){
  int *pTemp, *pTemp2, i;
  if (p->iEnQueue==p->iDeQueue){ // enlarge queue
    if (!(pTemp=(int *)calloc(p->nSize+3,sizeof(int)))) {
      fprintf(stderr,"Memory Allocation Error"); 
      return 1;
    }
    for(int i=0;i<p->nSize;i++) // copy all the elements of pFifo
      pTemp[i]=p->pFifo[(p->iDeQueue+i)%p->nSize];
    p->iDeQueue=0;p->iEnQueue=p->nSize;
    pTemp2=p->pFifo; p->pFifo=pTemp; free(pTemp2); // update array
    p->nSize+=3;
  }

  p->pFifo[p->iEnQueue]=n;
  if (p->iDeQueue==-1) p->iDeQueue=p->iEnQueue; 
  p->iEnQueue=(p->iEnQueue+1)%p->nSize;
  return 0;
}

int printQueue(SFifo *p){
  printf("Fifo = [");
  for (int i=0;i<p->nSize;i++) printf("%d, ",p->pFifo[i]);
  printf("\b\b]\n");
  printf("Value of iEnQueue: %d, iDeQueue: %d\n", p->iEnQueue, p->iDeQueue);
  return 0;
 }

int deQueue(SFifo *p){
  int n, nFreeSpace, *pTemp;
  if (p->iDeQueue==-1) return -1;
  n=p->pFifo[p->iDeQueue];
  p->iDeQueue=(p->iDeQueue+1)%p->nSize;
  if (p->iDeQueue>p->iEnQueue) nFreeSpace=p->iDeQueue-p->iEnQueue;
  else nFreeSpace=p->iDeQueue-p->iEnQueue+p->nSize;
  printf("Free space=%d\n",nFreeSpace);
  
  if (p->iDeQueue==p->iEnQueue) p->iDeQueue=-1;
  
  if (nFreeSpace>3){  //compress queue
    if (!(pTemp=(int *)calloc(p->nSize+3,sizeof(int)))) { ///+3 when we shrink??
      fprintf(stderr,"Memory Allocation Error"); 
      return 1;
    }
    for(int i=0;i<p->nSize;i++) // copy all the elements of pFifo
      pTemp[i]=p->pFifo[(p->iDeQueue+i)%p->nSize];
  
   	free(p->pFifo); //Why seg.fault when free? (When we allocate -3)
    p->pFifo = pTemp;
    p->nSize-=3;
    p->iDeQueue=0;
    p->iEnQueue=p->nSize-1;
  }
  
	return n;
}

int constructFifo(SFifo *p, int n){
  if (!(p->pFifo=(int *)calloc(n,sizeof(int)))) {
    fprintf(stderr,"Memory Allocation Error"); 
    return 1;
  }
  p->nSize=n;
  p->iEnQueue=0;
  p->iDeQueue=-1;

  return 0;
}

int destructFifo(SFifo *p){
  free(p->pFifo); ////////
  return 0;
}

/*int main(){
  int n,m;
  SFifo myFifo;

  printf("Enter a queue size: ");scanf("%d",&n);
  if (constructFifo(&myFifo,n)){
    fprintf(stderr,"Error creating the queue\n");
    return 1;
  }

  printf("Enqueue numbers (dequeue with -2, quit with -1)\n");
  while (n!=-1){
    scanf("%d",&n);
    if (n==-1) break;
    if (n==-2) {
      m=deQueue(&myFifo);
      if (m==-1) {
        fprintf(stderr,"Dequeueing from empty queue!!!\n");
        exit(1);
      }
      printf("Value %d dequeued\n",m);
      printQueue(&myFifo);
      continue;
    }
    if (enQueue(&myFifo,n)==-2){
        fprintf(stderr,"enQueueing in full queue!!!\n");
        exit(2);
      }
    printQueue(&myFifo);
  }

  destructFifo(&myFifo);

  return 0;
}*/
