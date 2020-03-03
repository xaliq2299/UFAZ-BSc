// find / -name "*.tex" > output >2 erreurs

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
  int why;
  int pid;

  pid = fork();
  if (pid == -1) {exit(20); }
  if (pid ==0)
    { // child
      int fd1, fd2;
      fd1=open("output", O_CREAT|O_WRONLY,0666);
      fd2=open("erreurs", O_CREAT|O_WRONLY,0666);
      printf("descriptors : %d %d\n", fd1, fd2);
      printf("child : preparing to exec...\n");
      dup2(fd1, 1);
      dup2(fd2, 2);

      execlp("find", "find", "/", "-name","*.tex", NULL);
      
      exit(5);
    }

  else
    { // parent
      printf("parent : launching the child...\n");
      wait(&why);
      if(WIFEXITED(why)) printf("parent : exit code is %d\n", WEXITSTATUS(why));
    }
  return 0;
}