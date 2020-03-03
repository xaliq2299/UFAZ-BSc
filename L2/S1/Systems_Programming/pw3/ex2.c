#include <stdio.h>

char my_getchar(){
	int c = getc(stdin);
	return (char)c;
}

int main(){
	char c;
	while( ( c=my_getchar() ) != EOF)
		printf("character read: %c\n", c);
	return 0;
}
