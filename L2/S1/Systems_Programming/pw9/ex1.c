#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void copy(int fdsrc,int fddst){
	char c; int n;
	while((n = read(fdsrc,&c,1)) != 0)
		write(fddst,&c,1);
}


int main(int argc, char const *argv[]){
	int tube[2]; // two files descriptors for piping, tube[0] --> reading, tube[1] --> writing
	int v = pipe(tube);
	if(v == -1)
		exit(3);

	pid_t pid = fork();
	if(pid == -1){
		printf("cannot fork!\n");
		exit(5);
	}else if(pid == 0){ // child 
		close(tube[1]);
		copy(tube[0],1);
		close(tube[0]);
	}
	else{ // parent
		close(tube[0]);
		copy(0,tube[1]);
		close(tube[1]);
	}
	return 0;
}
