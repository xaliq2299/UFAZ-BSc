#include <stdio.h>

int main()
{
	FILE *f = fopen("foo.pgm", "w");

	fprintf(f, "P2\n%d %d\n%d\n", 16,16,255);

	for(int a=0;a<=255;a++)
		fprintf(f, "%d %d %d ", a, 0, 0);
	fprintf(f, "\n");

	fclose (f);
	
	return 0;
}
