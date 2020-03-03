#include <stdio.h>

typedef struct Huffchar{
	char l;
	char bitstab[8];
}Huffchar;


void writeBinaryFile(FILE *filename, int size, Huffchar tab[]);
char *readBinaryFile(FILE *filename);
