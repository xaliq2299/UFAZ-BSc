#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
  int val;
  #pragma omp parallel private(val)
  {
    val = rand();
    sleep(1);
    printf("My val : %d\n", val);
  }
  return 0;
}