#include <stdio.h>
#define SIZE 100

int main() {
  double a[SIZE], b[SIZE], c[SIZE], d[SIZE];
  
  for (size_t i = 0; i < SIZE; i++)
    a[i] = b[i] = i;

  // In the following example, threads that are finished with the first loop can start on the second. 
  // Note that this requires both loops to have the same schedule. 
  #pragma omp parallel
  {
    #pragma omp for schedule(static) nowait
    for (size_t i = 0; i < SIZE; i++)
      c[i] = a[i] + b[i];

    #pragma omp for schedule(static)
    for (size_t i = 0; i < SIZE; i++)
      d[i] = a[i] + c[i];
  }

  for (size_t i = 0; i < SIZE; i++)
    printf("%g ", d[i]);
  printf("\n");
  return 0;
}