#include <stdio.h>
#define N 4

struct queue{
	int array[N];
	int i_head;
	int size;
};

int nextIndex(int ind, int max)
{
	if(ind >= 0 && ind <= max-2)
		return (ind+1);
	else
		return (ind%4);
}

int QU_freeIndex(struct queue q)
{
	int a=nextIndex(q.size, N);
	return a;
}

struct queue QU_new(void)
{
	struct queue q;
	q.size = 0;
	
	return q;	
}

void QU_show(struct queue q)
{
	for(int a=0;a<q.size;a++)
		printf("%3d", q.array[a] );
	
	puts("");
}

int QU_size(struct queue q)
{
	return q.size;
}

struct queue QU_enqueue(struct queue q, int n)
{
	if (q.size == N)
	{	
		printf("The stack is already fulled\n");
		return q;
	}
	else
	{
		q.array[ QU_freeIndex(q) ] = n;
		q.size++;
		return q;
	}
}

struct queue QU_dequeue(struct queue q)
{
	if(q.size == 0)
	{
		printf("The stack is empty\n");
		return q;
	}
	else
	{
		//for(int a=0;a<q.size;a++)
		//	q.array[a] = q.array[a+1];
	
		q.size--;
		q.i_head = q.array[0];

		return q;
	}
}

int QU_head(struct queue q)
{
	if(q.size == 0)
	{
		printf("The stack is empty\n");
		return 0;
	}
	else
		return q.i_head;
}


int main()
{
	struct queue st = QU_new();
	QU_show(st);
	
	st = QU_enqueue(st, 1);	
	QU_show(st);
	
	st = QU_enqueue(st, 5);	
	QU_show(st);
	
	st = QU_enqueue(st, 2);	
	QU_show(st);

	st = QU_enqueue(st, 7);	
	QU_show(st);		
	
	st = QU_dequeue(st);
	QU_show(st);
	
	st = QU_dequeue(st);
	QU_show(st);

	st = QU_dequeue(st);
	QU_show(st);
	
	st = QU_enqueue(st, 3);	
	QU_show(st);

	st = QU_enqueue(st, 10);	
	QU_show(st);
	
	st = QU_dequeue(st);
	QU_show(st);
	
	st = QU_dequeue(st);
	QU_show(st);
	
	st = QU_dequeue(st);
	QU_show(st);
	
	return 0;
}
