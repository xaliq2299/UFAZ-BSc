#include "direct_cache.h"

struct direct_cache* direct_cache_create(int nb_blocks) {
  // TODO
  return NULL;
}

void direct_cache_delete(struct direct_cache* c) {
  // TODO
}

void direct_cache_print(struct direct_cache* c) {
  if (c == NULL) {
    printf("Non-initialized direct cache: %p\n", c);
    return;
  }
  printf("Number of blocks: %d\n", (c->nb_blocks == 0 ? 0 : (0x1 << c->nb_blocks)));
  if (c->table == NULL) {
    printf ("Nn-initialized table: %p\n", c->table);
    return;
  }
  int T = (c->nb_blocks == 0 ? 0 : (0x1 << c->nb_blocks));
  printf ("--------------------------------Table:------------------------------------\n");
  for (int i = 0; i < T; i++){
    printf ("Tag: %10d | Valid: %1d | Word:",c->table[i].tag, c->table[i].valid);
    print_bits(c->table[i].word);
  }
  printf ("--------------------------------------------------------------------------\n");
  return;
}

int get_offset(int address, struct direct_cache* c) {
  // TODO
  return -1;
}

int get_index(int address, struct direct_cache* c) {
  // TODO
  return -1;
}

int get_tag(int address, struct direct_cache* c) {
  // TODO
  return -1;
}

int set_direct_cache(int address, int word, struct direct_cache* c) {
  // TODO
  return -1;
}

int lw_direct_cache(int* reg, int address, struct direct_cache* c) {
  // TODO
  return -1;
}
