#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
  int tube[2];
 
  int pid;
  if (argc!=2) {exit(3);}

  pipe(tube);
  pid=fork();
  if (pid==-1) {exit(2);}
  if (pid==0)
    { // child ps eaux
      close(tube[0]);
      dup2(tube[1],1);
      close(tube[1]);
      execlp("ps", "ps", "eaux", NULL);
      exit(7);
    }

  pid=fork();
  if (pid ==0)

    {// 2nd child grep "^$1 "
     int fd;
     char *t= malloc( strlen(argv[1])+3 );
     close(tube[1]);
     dup2(tube[0], 0);
     close(tube[0]);
     close(1);
     fd=open("/dev/null", O_WRONLY);
     sprintf(t, "^%s ", argv[1]);
     execlp("grep", "grep", t, NULL) ;
     exit(17);
    }
    
  close(tube[0]);
  close(tube[1]);
  int status1, status2;
  wait(&status1);
  wait(&status2);
  
  if( WIFEXITED(status1) && WEXITSTATUS(status1)==0 && WIFEXITED(status2) && WEXITSTATUS(status2)==0 )
    {
      char *s=" est connecté\n";
      write( 1, argv[1], strlen(argv[1]) );
      write( 1, s, strlen(s) );
    }
  
  return( 0 );


  return 0;
}
