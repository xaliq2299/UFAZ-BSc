#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	if(argc<=2) exit(1);
	int n=atoi(argv[1]);
	char* cmd = argv[2];
	int ex=0;
	for(int i=0;i<n;i++){
		pid_t pid = fork();
		if(pid == -1)	exit(1);
		else if(pid == 0){//child
			execvp(cmd,argv+2);
		}
		else{//parent
			int why;
			wait(&why);
			printf("%d\n", i); 
			if(WIFEXITED(why)){
				int rc = WEXITSTATUS(why);
				if(rc == 1) ex=1;
			}
		}
	}
	exit(ex);
}