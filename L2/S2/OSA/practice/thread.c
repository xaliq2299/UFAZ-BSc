#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int nthread;

void *f(void *arg){
	int i=*(int*) arg;
	int *p;

	printf("I am thread %d (out of %d), tid=%ld\n", i, nthread, pthread_self());
	p = malloc(sizeof(int));
	*p = i*2;

	pthread_exit(p);
}

int main(int argc, char **argv){
	pthread_t *tid; int e, i, *ti;
	nthread=atoi(argv[1]);
	tid = malloc(nthread*sizeof(pthread_t));
	ti = malloc(nthread*sizeof(int));
	for(i=0;i<nthread;i++){
		ti[i]=i;
		if((e=pthread_create(&tid[i], NULL, f, &ti[i]))!=0)
			perror("pthread_create");
	}

	for(i=0;i<nthread;i++){
		void *r;
		if((e=pthread_join(tid[i], &r))!=0)
			perror("pthread_join");
		printf("Return of thread %d=%d\n", i, *(int*) r);
		free(r);
	}
	free(tid); free(ti);
}