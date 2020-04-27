#include <stdio.h>
#include <omp.h>

int main() {
  #pragma omp parallel
  {
    int tid = omp_get_thread_num();
    int size = omp_get_num_threads();
    printf("I'm thread %d in a thread team of size %d\n", tid, size);
  }
  return 0;
}