#ifndef ACACHE
#define ACACHE

#include <stdio.h>
#include <stdlib.h>
#include "direct_cache.h"

struct associative_cache {
  int nb_tables;                // Number of sets
  struct direct_cache** dtable; // Array of direct caches
};

struct associative_cache* associative_cache_create(int nb_blocks, int nb_tables);

void associative_cache_delete(struct associative_cache* c);

void associative_cache_print(struct associative_cache* c);

int set_associative_cache(int address, int word, struct associative_cache* c);

int lw_associative_cache(int *reg, int address, struct associative_cache* c);

#endif 
