#include <stdio.h>

int main() {
  #pragma omp parallel
  printf("Hello,\n");
  printf("world\n");
  return 0;
}