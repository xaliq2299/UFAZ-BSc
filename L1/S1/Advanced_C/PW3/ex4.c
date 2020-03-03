#include <stdio.h>
#include <stdlib.h>

struct stack{
	int _size;
	int *_array;
};

struct stack ST_new(int maxsize){
	struct stack s;
	s.size = maxsize;
	s._array = (int*) malloc(sizeof(int)*maxsize);
	return s;
}
