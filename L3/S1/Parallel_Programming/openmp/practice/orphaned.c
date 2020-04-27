#include <stdio.h>
#define SIZE 1024

void init(int* vec) {
  size_t i;
  #pragma omp for
  for (i = 0; i < SIZE; i++)
    vec[i] = 0;
}

int main() {
  int vec[SIZE];
  #pragma omp parallel
  init(vec);
  return 0;
}