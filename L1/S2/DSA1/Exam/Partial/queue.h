#ifndef QUEUE
#define QUEUE
typedef struct Fifo {
  int iEnQueue, iDeQueue, nSize;
  int* pFifo;
} SFifo;

int constructFifo(SFifo *p, int n); // signature of the function
int enQueue(SFifo *p, int n);
int deQueue(SFifo *p);
int destructFifo(SFifo *p);

#endif
