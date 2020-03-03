#include <stdio.h>
#include <stdlib.h>

typedef struct Fifo {
  int iEnQueue, iDeQueue, nSize;
  int* pFifo;
} SFifo;

int constructFifo(SFifo *p, int n);
int enQueue(SFifo *p, int n);
int deQueue(SFifo *p);
int printQueue(SFifo*p);
int destructFifo(SFifo *p);


int main(){
  int n;
  SFifo myFifo;

  printf("Enter a queue size: ");scanf("%d",&n);
  if (constructFifo(&myFifo,n)){
    fprintf(stderr,"Error creating the queue\n");
    return 1;
  }
  
  printf("enQueue numbers (end with -1)\n");
  while (n!=-1){
    scanf("%d",&n);
    if (n==-1) break;
    enQueue(&myFifo,n);
  }

  destructFifo(&myFifo);

  return 0;
}



