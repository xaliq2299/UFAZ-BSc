// write a program which runs 2 threads with different parameters, display in both threads the value of the parameter, the id of the thread and the id of the process
#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

int glob=0;

void *myfunction (void *arg)
{
  int *i = (int *)arg;
  printf("pid = %d, task id = %d, value = %d\n",
	 getpid(), (int) pthread_self(), *i);
  glob=*i;
  return NULL;
}
void *otherfunction (void *arg)
{
  int *i = (int *)arg;
  *i=*i*2;
  return (void*)arg;
}
int main()
{
  pthread_t p1;
  int v=43;
  pthread_t p2;
  int w=12;
  pthread_t p3;
  int z=1;
  pthread_t p4;
  pthread_create(&p1, NULL, myfunction, &v);
  pthread_create(&p2, NULL, myfunction, &w);
  
  pthread_create(&p3, NULL, otherfunction, &z);
  pthread_create(&p4, NULL, otherfunction, &w);

  printf("v, w, z, glob = %d, %d, %d, %d\n", v, w, z, glob);
  printf("v, w, z, glob = %d, %d, %d, %d\n", v, w, z, glob);
  printf("v, w, z, glob = %d, %d, %d, %d\n", v, w, z, glob);
  
  pthread_join(p1, NULL);
  pthread_join(p2, NULL);
  pthread_join(p3, NULL);
  pthread_join(p4, NULL);
  printf("v, w, z = %d, %d, %d\n", v, w, z);
  printf("glob=%d\n",glob);
  return 0;
}