// look
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>

void copy(int fdsrc, int fddst){
	char c;
	while(read(fdsrc,&c,1)>0)
		write(fddst	,&c,1);
}

int main(){
	int fd1=open("file1", O_RDONLY);
	int fd2=open("file2", O_WRONLY | O_CREAT, 0666);
	// copy(fd1,fd2);
	// close(fd1); close(fd2);
	int tube[2];
	pipe(tube);
	
	int pid = fork();
	if(pid == -1) exit(1);
	else if(pid == 0){ // child
		close(tube[1]);
		copy(fd1,fd2);
	}
	else{ // parent
		//char data[50];
		//read(0,data,sizeof(char)*50);
		close(tube[0]); dup2(tube[1],fd1); close(tube[1]);
		
		int why; wait(&why);
	}
}	