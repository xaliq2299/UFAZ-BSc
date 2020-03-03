#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/times.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, const char **argv){
  if(argc != 2){exit(-1);}
  int tube[2];
  int v;
  int pid, why, fd1, fd2, fd3;
 // char *arg = argv[1];
  v=pipe(tube);
  
  if (v==-1) {exit(3);} //pipe creation failed
  pid=fork();
  if (pid==-1) {exit(5);}
  if (pid==0){ //ps eaux, child
      int fd1 = open("toto", O_CREAT|O_WRONLY, 0666);
      dup2(fd1,1);
      execlp("ps", "ps", "eaux", NULL);
    }
  else{
        wait(NULL);
        pid_t pid2 = fork();
      //grep $1, parent
      switch (pid2){
            case -1:
                exit(-1);
                break;
            case 0:
                fd2 = open("foo", O_RDONLY);
                dup2(fd2, 0);
                fd3 = open("/dev/null", O_WRONLY);
                dup2(fd3, 1);
                char user[255];
                sprintf(user, "^%s ", argv[1]);
                execlp("grep", "grep", user, NULL);
                exit(0);
            default:
                wait(&why);
                //if(WEXITSTATUS(why) == 0)
                //    printf("%s is a user\n", argv[1]);
                    break;
        }  
    }
  }