//gettimeofday, fork (wait), execlp
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>

int main(int argc, char *argv[]){
	if(argc != 2){
		printf("Needed argument.\n");
		exit(-2);
	}
	int why, d, pid;
	struct timeval tv; 
	struct timezone tz;
	char *dirName = argv[1];
	
	if( gettimeofday(&tv, NULL) == 0 ){ // if successful
		printf("seconds: %ld, microseconds: %ld\n", tv.tv_sec, tv.tv_usec);
		d=tv.tv_usec;
	}
	pid = fork();
	if(pid == -1){exit(-3);}
	else if(pid == 0){ // child
		printf("Child process\n");
		execlp("ls", "ls", "-l", dirName, NULL); // displays content of a given directory
	}
	else{ // parent
		printf("Parent process\n");
		wait(&why);
		if( gettimeofday(&tv, &tz) == 0 ){ // if successful
			printf("seconds: %ld, microseconds: %ld\n", tv.tv_sec, tv.tv_usec);
			d-=tv.tv_usec;
			printf("it took %d microseconds to run the command\n", -d);
		}
	}

	return 0;
}
