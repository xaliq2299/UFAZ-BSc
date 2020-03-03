#include <stdio.h>
#include <unistd.h>

char my_getchar(){
	char c;
	int n = read(0,&c,1);
	if (n!=0)
		return c;
	//else
	//	return EOF;
}

int main(){
	char c = my_getchar();
	printf("%c\n", c);
}