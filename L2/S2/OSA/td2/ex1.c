#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	int status;
	int r=fork();
	if(r==-1){exit(-1);}
	else if(r==0){
		printf("Son\n");
		printf("pid of son: %d\n", getpid());
		printf("pid of father: %d\n", getppid());
		exit(getpid()%10);
	}
	else{
		printf("Father\n");
		printf("pid of son: %d\n", r);
		wait(&status);
		if(WIFEXITED(status)){
			printf("exit status: %d\n", WEXITSTATUS(status));
		}
	}
	return 0;
}