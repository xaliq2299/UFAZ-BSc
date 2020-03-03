#ifndef DIRECT_CACHE
#define DIRECT_CACHE

#include <stdio.h>
#include <stdlib.h>
#include "bits.h"

struct block {
  int tag;   // Block's tag
  int valid; // Validity bit
  int word;  // Block's content
};

struct direct_cache {
  int nb_blocks;       // Number of blocks (must be a power of 2)
  struct block* table; // Table
};

struct direct_cache* direct_cache_create(int nb_blocks);

void direct_cache_delete(struct direct_cache* c);

void direct_cache_print(struct direct_cache* c);

int get_offset(int address, struct direct_cache* c);

int get_index(int address, struct direct_cache* c);

int get_tag(int address, struct direct_cache* c);

int set_direct_cache(int address, int word, struct direct_cache* c);

int lw_direct_cache(int* reg, int address, struct direct_cache* c);

#endif 
