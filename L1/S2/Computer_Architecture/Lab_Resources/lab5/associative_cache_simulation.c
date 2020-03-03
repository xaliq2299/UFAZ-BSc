#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "associative_cache.h"

int rand_address(int inf, int sup) {
  return (rand() % (sup - inf)) + inf;
}

int main(int argc, char* argv[]) {
 srand(time(NULL));
 // TODO
 return 0;
}
