#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	int why, pid = fork();
	if(pid == -1) {printf("[!] The child couldn't be created\n"); exit(-1);}
	else if(pid == 0) { // child
		printf("Child process\n");	
		printf("My pid: %d\n", getpid());
		printf("My father's pid: %d\n", getppid());
		exit(getpid()%10);
	}
	else{ // parent
		printf("Parent process\n");
		printf("My child's pid: %d\n", pid);
		wait(&why);
		if(WIFEXITED(why)) 
			printf("Return code=%d\n", WEXITSTATUS (why));
		if(WIFSIGNALED(why))
			printf("stopped by signal %d\n", WTERMSIG(why) );
	}
	return 0;
}
