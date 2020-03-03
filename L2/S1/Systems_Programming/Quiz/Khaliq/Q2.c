#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, const char **argv){
  if(argc != 2){exit(-1);}
  int tube[2];
  int v;
  int pid;
 // char *arg = argv[1];
  v=pipe(tube);
  
  if (v==-1) {exit(3);} //pipe creation failed
  pid=fork();
  if (pid==-1) {exit(5);}
  if (pid==0){ //ps eaux, child
      close(tube[0]);
      dup2(tube[1], 1);
      close(tube[1]);
      execlp("ps", "ps", "eaux", NULL);
    }
  else{
      //grep $1, parent
      close(tube[1]);
      dup2(tube[0], 0);
      close(tube[0]);
  	    char arg[255];
  //      strcpy(user, argv[1]);
        sprintf(arg, "%s ", argv[1]);
 //             execlp("grep", "grep", arg, NULL);
            
  	   //     sprintf(arg, "^%s ", argv[1]);
 
      int fd = open("/dev/null", O_WRONLY);
      dup2(fd,1);
      execlp("grep", "grep", arg, NULL);
    }
  
  return 0;
}
