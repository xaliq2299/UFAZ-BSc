#include <stdio.h>
int main() {
  #pragma omp parallel
  {
    #pragma omp single
    { 
      #pragma omp task
      printf("Hello,\n");
      #pragma omp task
      printf("world!\n");
      #pragma omp taskwait
      printf("Bye\n");
    }  
  }
  return 0;
}