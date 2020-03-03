#include <stdio.h>

typedef struct a {char c; char *pc; int i;}A;

int main(){
	printf("%ld\n", sizeof(int));
	printf("%ld\n", sizeof(char));
	printf("%ld\n", sizeof(char*));
	printf("%ld\n", sizeof(char));
	printf("%ld\n", sizeof(A));
	printf("%ld\n", sizeof(A*));

	return 0;
}