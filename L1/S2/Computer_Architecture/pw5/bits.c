#include "bits.h"

void print_bits(int n) {
  for (int i = 8 * sizeof(int) - 1; i >= 0; i--)
    printf(" %d ", BIT(n, i));
  printf("\n"); 
}
