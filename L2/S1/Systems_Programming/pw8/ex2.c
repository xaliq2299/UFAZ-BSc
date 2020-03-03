#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/times.h>
#include <time.h>

int main(int argc, char *argv[]){
	int why, pid;
	if(argc != 2){
		printf("Needed arguments.\n");
		exit(-2);
	}
	char *dirName = argv[1];
	
	struct tms buf; clock_t start, end;
	pid = fork();
	
	if(pid == -1){ exit(-3); }
	else if(pid == 0){ // child
		times(&buf); start = clock(); //buf.tms_utime;
		int fd=open("/dev/null",O_WRONLY,0666);
		dup2(fd,1);
		execlp("ls", "ls", "-R", dirName, NULL); // displays content of a given directory
	}
	else{ // parent
		wait(&why);
		times(&buf); end = clock(); //buf.tms_utime;		
		printf("%lf seconds\n", (double)(end-start)/CLOCKS_PER_SEC);
	}

	return 0;
}
