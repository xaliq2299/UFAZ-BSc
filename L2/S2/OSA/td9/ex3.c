#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int last;
void *function(void *arg){
	int id = *(int*)arg;
	int counter;
	struct timespec req;
	req->tv_sec=1;
	for(int counter=0;i<10;i++){
		printf("counter value prefix: %d\n", counter+1);
		nanosleep(&req, NULL);
	}
}

int main(int argc, char **argv){
	if(argc != 2) exit(1);
	int n=atoi(argv[1]);
	pthread_t *tid = malloc(sizeof(pthread_t)*n);
	for(int i=0;;i<n;i++){
		pthread_create(&tid[i], NULL, &function, (void*) &i);
	}

}