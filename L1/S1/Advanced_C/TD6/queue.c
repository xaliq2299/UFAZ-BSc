#include <stdio.h>
#include <stdlib.h>
#define N 4

struct queue{
  int array[N];
  int i_head;
  int size;
};

int nextIndex(int ind, int max){
  if(ind >= 0 && ind <= max-2) return ind+1;
  else
    return ind%N;
}

int QU_freeIndex(struct queue q){
  int index = nextIndex(q.size, 5);
  if(q.i_head == 3)
  	return index-2;
  
  return index-1;
}

struct queue QU_new(void){
  struct queue q;
  q.i_head=0;
  q.size=0;
  for(int i=0;i<N;i++)
    q.array[i]=0;
  return q;
}

void QU_show(struct queue q){
  for(int i=0;i<4;i++)
    printf("%4d", q.array[i]);
  puts("");
}

int QU_size(struct queue q){
  return q.size;
}

struct queue QU_enqueue(struct queue q, int n){
  if(q.size < N){
    int i=QU_freeIndex(q);
    q.size++;
    q.array[i]=n;
  }
  else
    printf("The queue is full!!!\n");
    
  return q;
}

struct queue QU_dequeue(struct queue q){
  if(q.size == 0)
    printf("Queue is empty - You can't dequeue\n");
  else{
    q.array[q.i_head]=0; //let it be dequeued
    q.i_head=(q.i_head+1)%N; //changing head
    q.size--;
  }
  return q;
} 

int QU_head(struct queue q){
  if(q.size == 0){
    printf("Queue is empty\n");
    return 1;
  }
  return q.array[q.i_head]; 
}

int main()
{
	struct queue q = QU_new();
	QU_show(q);
	
	q = QU_enqueue(q, 1);	
	QU_show(q);
	printf("%d\n", QU_head(q) );
		
	q = QU_enqueue(q, 5);	
	QU_show(q);
	printf("%d\n", QU_head(q) );

	q = QU_enqueue(q, 2);	
	QU_show(q);
	printf("%d\n", QU_head(q) );
	
	q = QU_enqueue(q, 7);	
	QU_show(q);		
	printf("%d\n", QU_head(q) );

	q = QU_dequeue(q);
	QU_show(q);
	printf("%d\n", QU_head(q) );
	
	q = QU_dequeue(q);
	QU_show(q);
	printf("%d\n", QU_head(q) );
	
	q = QU_dequeue(q);
	QU_show(q);
	printf("%d\n", QU_head(q) );

	q = QU_enqueue(q, 3);	
	QU_show(q);
	printf("%d\n", QU_head(q) );
	
	q = QU_enqueue(q, 10);	
	QU_show(q);
	printf("%d\n", QU_head(q) );
	
	q = QU_dequeue(q);
	QU_show(q);
	printf("%d\n", QU_head(q) );	
	
	q = QU_dequeue(q);
	QU_show(q);
	printf("%d\n", QU_head(q) );	
	
	q = QU_dequeue(q);
	QU_show(q);
	printf("%d\n", QU_head(q) ); 	
  
  	return 0;
}
