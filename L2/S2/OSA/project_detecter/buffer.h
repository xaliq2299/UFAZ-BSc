#ifndef _H_BUF
#define _H_BUF

#include <stdlib.h>
#include <string.h>

typedef struct {
	char *data;
	int size;
}Buffer;

Buffer get_buffer(); // a function that returns a buffer of size 1
int compare(Buffer *b1, Buffer *b2); // a function that compares the contents of 2 buffers
Buffer copy(Buffer *des, Buffer *src); // a function that copies the content of buffer src to the buffer des
void destruct_buffer(Buffer *buf); // a function that destructs the given buffer

#endif