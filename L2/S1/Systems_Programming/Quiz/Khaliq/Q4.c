#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/times.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[]){
    if(argc != 2){
        printf("enter argument or wrong one\n");
        return -1;
    }
    
    int why, fd1, fd, fd2, pid1, tube[2]; pipe(tube);

    pid_t pid = fork();
   	if(pid == -1)
    	exit(-1);
	else if(pid == 0){
        dup2(fd, 1);
        pid1 = fork();
        if(pid1 == -1){exit(-1);}
        else if(pid1 == 0){      
            close(tube[0]);
            dup2(tube[1], 1);
            close(tube[1]);
            execlp("ps", "ps", "eaux", NULL);  
        }
        else{
          close(tube[1]);
          dup2(tube[0], 0);
          close(tube[0]);
          //execlp("grep", "grep", argv[1], NULL);
        
          int fd1 = open("/dev/null", O_WRONLY);
          dup2(fd1,1);
          execlp("grep", "grep", argv[1], NULL);
        }
    }
    else{
        wait(&why);
        if(WEXITSTATUS(why) == 0)
            printf("%s is a user\n", argv[1]);
        else{
            exit(9);
        }
    }
	return 0;
}