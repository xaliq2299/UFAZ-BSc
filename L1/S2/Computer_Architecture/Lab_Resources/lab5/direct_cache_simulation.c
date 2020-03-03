#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "direct_cache.h"

int rand_address(int inf, int sup) {
  int interval = sup-inf;
  int address = (rand() % interval) + inf;
  return address;
}

int main(int argc, char* argv[]) {
  srand(time(NULL));
  // TODO
  return 0;
} 
