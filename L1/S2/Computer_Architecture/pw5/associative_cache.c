#include "associative_cache.h"
#include <time.h>

struct associative_cache* associative_cache_create(int nb_blocks, int nb_tables) {
  // TODO
  return NULL;
}

void associative_cache_delete(struct associative_cache* c) {
  // TODO
}

void associative_cache_print(struct associative_cache* c){
  if (c == NULL)
    return;
  for (int i = 0; i < c->nb_tables; i++) {
    printf("###################### Table: %d ##########################\n", i);
    direct_cache_print(c->dtable[i]);
  }
}

int set_associative_cache(int address, int word, struct associative_cache* c) {
  // TODO
  return -1;
}

int lw_associative_cache(int *reg, int address, struct associative_cache* c) {
  // TODO
  return -1;
}
