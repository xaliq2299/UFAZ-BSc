#include <stdio.h>
#define SIZE 100

int main() {
  double a[SIZE], b[SIZE], c[SIZE], d[SIZE];
  
  for (size_t i = 0; i < SIZE; i++)
    a[i] = b[i] = i;

  #pragma omp parallel
  {
    #pragma omp for schedule(static) nowait
    for (size_t i = 0; i < SIZE; i++)
      c[i] = a[i] + b[i];

    #pragma omp for schedule(guided)
    for (size_t i = 0; i < SIZE; i++)
      d[i] = a[i] + c[i];
  }

  for (size_t i = 0; i < SIZE; i++)
    printf("%g ", d[i]);
  printf("\n");
  return 0;
}

/*
* In static case it nowait waa reasonable
*/