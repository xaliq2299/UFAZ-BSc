#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[]){
	// wrong argument count
	if(argc != 2){
		fprintf(stderr, "Wrong argument, expected a username\n");
		return -1;
	}
		
	int why, fd, pid, fd1, fd2;

	// fork and execute
	pid = fork();
	if(pid == -1)
		exit(-2);
	else if(pid == 0){
		int fd = open("foo", O_CREAT | O_WRONLY, 0666);
		dup2(fd, 1);
		execlp("ps", "ps", "eaux", NULL);
	}
	else{
		wait(NULL); // wait for ps
		pid = fork(); // parent forks again to read from foo

		switch (pid){
			case -1:
		        exit(-1);
		        break;
		    case 0:
		        fd1 = open("foo", O_RDONLY);
		        dup2(fd1, 0);
		        fd2 = open("/dev/null", O_WRONLY);
		        dup2(fd2, 1);
		        char user[255];
		        sprintf(user, "^%s ", argv[1]);
		        execlp("grep", "grep", user, NULL);
		        exit(0);
		    default:
		        wait(&why); // wait for grep
		        if(WEXITSTATUS(why) == 0)
		            printf("%s is a user\n", argv[1]);
		        break;
		}
	}
	return 0;
}
