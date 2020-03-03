#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()

{
  int tube[2];
  int v;
  int pid;

  v=pipe(tube);
  if (v==-1) {exit(3);}
  pid=fork();
  if (pid==-1) {exit(5);}
  if (pid==0)
    {
      //child "ls -l"
      close(tube[0]);
      dup2(tube[1], 1);
      close(tube[1]);
      execlp("ls", "ls", "-all", NULL);
    }
  else
    {
      //parent "wc -l"
      close(tube[1]);
      dup2(tube[0], 0);
      close(tube[0]);
      execlp("wc", "wc", "-l", NULL);
    }
  
  return 0;
}
