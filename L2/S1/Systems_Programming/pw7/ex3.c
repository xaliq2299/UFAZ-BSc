#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char **argv){
	char c, *filename; int n, pid, fd;
	if(argc != 2)
		exit(-1);
		
	filename = argv[1];
	
	pid = fork();
	fd = open ( filename , O_RDONLY ); //if file is opened after 
									   //call of the function fork 
									   //then, both parent and child will
									   //read the file character by character.
	if(pid == -1) {exit(-2);}
	else if(pid == 0){ // child
		printf("Child process\n");
		while (( n = read ( fd , &c , 1)) > 0)
			write(1,&c, 1);
			//printf("character read: %c\n", c);
	}
	else{ // parent
		printf("Parent process\n");
		while (( n = read ( fd , &c , 1)) > 0)
			write(1,&c, 1);
			//printf("character read: %c\n", c);
	}
	
	return 0;
}
