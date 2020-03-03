#include <stdio.h>
#include <pthread.h>

void *f ( void *arg ){
	int i = *(int*) arg;
	printf("A am thread of pid %d\n", pthread_self() );
}

int main(){
	pthread_t tid[2];
	int nthread = 2;
	int pthread_create(tid, NULL, 2,NULL);

	for(int i=0;i<nthread;i++){
		pthread_create(&tid[i], NULL, f, NULL);
	}
	
	return 0;
}