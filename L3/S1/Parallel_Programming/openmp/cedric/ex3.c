#include <stdio.h>
#include <omp.h>
#define SIZE  100
#define CHUNK  10

int main() {
  int tid;
  double a[SIZE], b[SIZE], c[SIZE];
  
  for (size_t i = 0; i < SIZE; i++)
    a[i] = b[i] = i;
  /// only master thread comes until this point

  /// then fork-join: thread team
  #pragma omp parallel private(tid)
  {
    tid = 2;//omp_get_thread_num(); /// all threads will execute
    if (tid == 0) /// all threads will execute
      printf("Nb threads = %d\n", omp_get_num_threads()); /// only the master thread will execute
    printf("Thread %d: starting...\n", tid); /// all threads will execute

    #pragma omp for schedule(static, CHUNK) /// all threads will execute
    /// the following loop is executed by all threads, but not the same iterations
    for (size_t i = 0; i < SIZE; i++) {
      c[i] = a[i] + b[i];
      printf("Thread %d: c[%2zu] = %g\n", tid, i, c[i]);
    }
    printf("Done\n"); /// to demonstrate nowait
  }
  return 0; /// only master will execute
}



/*
* We dont know which thread getx a given chunk
* no chunk ordering
* Distribution is not stable, but it becomes after static
*/