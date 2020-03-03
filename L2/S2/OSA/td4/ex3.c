#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

int count=0;

void signalhandler(int signal){
	if(signal == SIGALRM)
		printf("%d\n", count);
	exit(0);
}

int main(){
	char c='x';
	int tube[2];

	int ret = pipe(tube);
	if(ret == -1){exit(-1);} // cant create pipe

	signal(SIGALRM, signalhandler);

	pid_t pid = fork();
	if(pid == -1){
		printf("cannot fork!\n");
		exit(5);
	}
	else if(pid == 0){ // child 
		while(write(tube[1],&c,1)){
			alarm(1);
			count++;
		}
	}
	else{
		wait(NULL);
	}
	
	return 0;
}
  