#include <stdio.h>
#include <omp.h>
int main() {
  double total, part1, part2;
  #pragma omp parallel \
              num_threads(2)
  {
    int tid;
    tid = omp_get_thread_num();
    if (tid == 0)
      part1 = 25;

    if (tid == 1)
      part2 = 17;

	#pragma omp barrier
    if (tid == 0) {     
      total = part1 + part2;
      printf("%g\n", total);
    }
  }
  return 0;
}