#include <stdio.h>
#include <stdlib.h>
int main (int argc, char** argv) {
	char c;
	FILE* input;
	FILE* output;
	char outputname[256];
	if (argc != 3) {
	printf("usage: ./copy <infile> <outfile>\n");
	exit(1);
	}
	snprintf(outputname, sizeof(outputname), "%s/%s", getenv("HOME"), argv[2]);
	input = fopen(argv[1], "r");
	output = fopen(outputname, "w");
	printf("Copie de %s vers %s\n", argv[1], outputname);
	while ((c = fgetc(input)) != EOF) {
	fprintf(output, "%c", c);
	}
	fclose(input);
	fclose(output);
}