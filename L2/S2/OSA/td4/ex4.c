#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv){
	if(argc > 2){exit(-1);}
	char *name = malloc(25);
	argc == 1 ? name=getenv("USER") : strcpy(name, argv[1]);

	int tube1[2], tube2[2];
	int v1=pipe(tube1);
	if(v1 == -1) {exit(-2);}
	int v2=pipe(tube2);
	if(v2 == -1) {exit(-3);}
	pid_t pid1 = fork();
	if(pid1 == -1) {exit(-4);} //failure
	else if(pid1 == 0){ //child
		close(tube1[0]);
		dup2(tube1[1],1);
		close(tube1[1]);
		execlp("ps", "ps", "eaux", NULL);
	}
	else{ // parent
		pid_t pid2 = fork();
		if(pid2 == -1){exit(-5);}
		else if(pid2 == 0){ // child
			close(tube1[1]);
			dup2(tube1[0],0);
			close(tube1[0]);
			close(tube2[0]);
			dup2(tube2[1],1);
			close(tube2[1]);
			execlp("grep", "grep", name, NULL);
		}
		else{//parent
			close(tube2[1]);
			dup2(tube2[0],0);
			close(tube2[0]);
			execlp("wc", "wc", "-l", NULL);
		}
	}
	return 0;
}