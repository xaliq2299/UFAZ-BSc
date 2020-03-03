#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("merida.pgm", "r");
	int a=0;
	int width, height;
	int size = 0;
	fscanf(f, "P2\n%d %d", &width, &height); 
	int *array = malloc(sizeof(int)*width*height);

	for(int a=0;a<width*height;a++)
		fscanf(f, "%d", &array[a]);
	
/*	
	while(!feof(f))
	{		
		fscanf(f, "%d", &array[a]);
		a++;
		size++;
	}
*/	
	fclose(f);
	
	
	/*
	for(int a=0;a<check;a++)
		array[a] /= 2;
	
	FILE *fp = fopen("new.pgm", "w");
	fprintf(fp, "P2");
	fprintf(fp, "%d %d\n", width, height);
	fprintf(fp, "%d\n", 255);clear
	
	for(int a=0;a<check;a++)
		fprintf(fp, "%d ", array[a] );
	*/
	
	for(int a=0;a<width*height;a++)
		array[a] /= 2;
	
	FILE *fp = fopen("new.pgm", "w");
	fprintf(fp, "P2");
	fprintf(fp, "%d %d\n", width, height);
	fprintf(fp, "%d\n", 255);
	
	for(int a=0;a<width*height;a++)
		fprintf(fp, "%d ", array[a] );
	
	fclose(fp);
}
