#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void fct(int sig)
{printf("The signal I just received is %d.\n", sig);}

int main()
{
  struct sigaction s,s2;

  s.sa_handler = fct;
  s.sa_flags=0;
  sigemptyset(&s.sa_mask);
  sigaddset(&s.sa_mask, SIGQUIT);

  sigaction(SIGUSR1, &s, NULL); // 30
  sigaction(24, &s, NULL); // 24

  s2.sa_handler = SIG_IGN;
  s2.sa_flags=0;
  sigemptyset(&s2.sa_mask);
  sigaddset(&s2.sa_mask, SIGQUIT);

  sigaction(SIGUSR2, &s2 ,NULL); //31
  
  printf("SIGUSR1 = %d, SIGUSR2 = %d\n", SIGUSR1, SIGUSR2);
  printf("ready to receive signals (my pid is %d)\n", getpid());
  pause();
}