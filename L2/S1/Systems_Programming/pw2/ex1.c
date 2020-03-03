#include <stdio.h>

int main(){
	FILE *f1 = fopen("foo", "r");
	FILE *f2 = fopen("bar", "w");
	char c;
	while((c=getc(f1)) != EOF)
		putc(c,f2);
	fclose(f1);
	fclose(f2);
	
	return 0;
}
