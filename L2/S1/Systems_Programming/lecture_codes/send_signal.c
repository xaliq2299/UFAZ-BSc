#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[])
{
  int pid, sig;
  if (argc!=3) {printf("usage is not appropriate.\n");exit(12);}
  pid=atoi(argv[1]);
  sig=atoi(argv[2]);
  
  printf("sending signal %d to process %d\n", sig, pid);
  kill(pid, sig);
  exit(8);
}
