#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

int n,p;

void* f(void *arg){
	int *t=(int*)arg;
	int *sum = malloc(sizeof(int));
	*sum=0;
	for(int i=1;i<p;i++)
		sum += ((*t-1)*p+i);
	return sum;
}

int main(int argc, char **argv){
	if(argc != 3){
		printf("usage: ./a.out n p");
		exit(-1);
	}
	n=atoi(argv[1]);
	p=atoi(argv[2]);

	pthread_t *tid = malloc(sizeof(pthread_t)*n);
	for(int t=0;t<n;t++)
		pthread_create(&tid[t],NULL,f,&t);
	// printf("%d\n", n);

	int sum=0;
	void *retVal;
	for(int i=0;i<n;i++){
		pthread_join(tid[i],&retVal);
		sum += *((int*)retVal);
	}
	printf("%d\n", sum);
}