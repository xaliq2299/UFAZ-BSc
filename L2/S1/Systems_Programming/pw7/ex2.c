#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char **argv){
	int pid, why, n;
	if(argc != 2){
		printf("[!] Wrong number of arguments\n");
		exit(-1);
	}
	n = atoi(argv[1]); //n is the number of child processes that will be created
	printf("%d child processes\n", n);

	for(int i=0;i<n;i++){
		pid = fork();
		if(pid == -1) exit(-2);
		else if(pid == 0) { // child
			printf("Child process\n");
			exit(getpid()%10);
		}
		else{ // parent
			printf("Parent process, ");
			wait(&why);
			if(WIFEXITED(why)) 
				printf("Child #%d: Parent pid=%d, return code=%d\n", i+1, getpid(), WEXITSTATUS (why) );
		}
	}
	return 0;
}
