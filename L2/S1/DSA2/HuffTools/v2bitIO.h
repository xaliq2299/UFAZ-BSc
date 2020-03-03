#include <stdio.h>

typedef struct BIT_BUFFER{
	FILE *f; //pointer to the file
	int pos; //position
	char bits; //array of 8 bits
}BIT_BUFFER;

void bb_init(BIT_BUFFER *buff, FILE *fp); //initialize the buffer with all elements
void bb_print(BIT_BUFFER *buff); //print the buffer in the file
void bb_fill(BIT_BUFFER *buff, int s, int *bitsTab); //to fill the buffer by reading from bitsTab TABLE OF BITS  we need to write in the file

