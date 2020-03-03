#include <stdlib.h>

struct Color{
	unsigned char r,g,b;
};

int *intArray = (int*) calloc(5,sizeof(int));
int *charArray = (char*) calloc(7,sizeof(char));
struct Color *ColorArray = (struct color*) calloc(10,sizeof(struct Color));

int* newIntArray(int n){
	int *array = calloc(n,sizeof(int));
	return array;
}
