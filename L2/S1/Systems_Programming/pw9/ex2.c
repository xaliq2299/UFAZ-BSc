#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[]){
	int tube1[2];
	int v1 = pipe(tube1);
	if(v1 == -1)
		exit(-1);

	pid_t pid1 = fork();
	if(pid1 == -1)
		exit(-3);

	else if(pid1 == 0){
		int tube2[2];
		int v2 = pipe(tube2);
		if(v2 == -1)
			exit(-2);

		pid_t pid2 = fork();
		if(pid2 == -1)
			exit(-4);
		else if(pid2 == 0){
			close(tube2[0]);
			dup2(tube2[1],1);
			close(tube2[1]);
			execlp("ps","ps","eaux",NULL);
		}
		// grep <name>
		close(tube2[1]);
		dup2(tube2[0],0);
		close(tube2[0]);

		dup2(tube1[1],1);
		close(tube1[1]);
        execlp("grep", "grep", (argc == 2) ? argv[1] : getenv("USER"), NULL);		
	}
	close(tube1[1]);
	dup2(tube1[0],0);
	close(tube1[0]);
	execlp("wc", "wc", "-l", NULL);

	return 0;
}
