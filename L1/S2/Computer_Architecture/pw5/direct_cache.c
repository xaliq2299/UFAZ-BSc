#include "direct_cache.h"
//#include <math.h>

struct direct_cache* direct_cache_create(int nb_blocks){
	// TODO
	return NULL;
	/*struct direct_cache* c = malloc(sizeof(struct direct_cache));
	c->nb_blocks = nb_blocks;
	c->table = malloc(sizeof(struct block)*nb_blocks);
  
	for(int i=0;i<nb_blocks;i++){
		c->table[i].tag = 0;
		c->table[i].valid = 0;
		c->table[i].word = 0;
  	}  
 	return c;*/
}

void direct_cache_delete(struct direct_cache* c){
	// TODO
	//free(c);
}

void direct_cache_print(struct direct_cache* c){
	if (c == NULL){
		printf("Non-initialized direct cache: %p\n", c);
		return;
	}
	printf("Number of blocks: %d\n", (c->nb_blocks == 0 ? 0 : (0x1 << c->nb_blocks)));
	if (c->table == NULL){
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

int get_offset(int address, struct direct_cache* c){
	// TODO
	return -1;
	//return log2(c->table->word); 
}

int get_index(int address, struct direct_cache* c){
	// TODO
	return -1;
	//return log2(c->nb_blocks);
}

int get_tag(int address, struct direct_cache* c){
	// TODO
	return -1;
	//return 32-log2(c->table->word)-log2(c->nb_blocks);
}

int set_direct_cache(int address, int word, struct direct_cache* c){
	// TODO
	return -1;
}

int lw_direct_cache(int* reg, int address, struct direct_cache* c){
	// TODO
	return -1;
}
