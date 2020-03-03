#include "read.h"
#include "string.h"
#include <stdlib.h>
#include "HT.h"

void writeBinaryFile(FILE *filename, int size, Huffchar tab[]){
	//save the size first in the file
	fwrite(&size,sizeof(int),1,filename);//putw(size,filename);
	//save the table of structures
	for(int i=0;i<size;i++)
		fwrite(&tab[i],sizeof(Huffchar),1,filename);
	//save the compressed text
}

char *readBinaryFile(char *filename){
	FILE *fp = fopen(filename,"rb");
	//read the size of the number of characters
	int num=getw(fp);
	printf("The number of characters is %d\n", num);//for testing
	//READ the alphabet of the compression
//	Huffchar newch = {0,""};
// 	Huffchar *dict = malloc(sizeof(Huffchar));
//	HuffNode *node = malloc(sizeof(HuffNode));
//	for(int i=0;i<num;i++){
//		fread(&newch,sizeof(Huffchar),1,fp);
		
		//dict[i] = newch;
//		printf("character %c: %s\n", newch.l,newch.bitstab);
//	}
	//read the compressed text and translate
	char c;
	int *array = (int*)malloc(sizeof(int)), size = 0, i=0;
	while(!(feof(fp))){
		size+=8;
		fread(&c,sizeof(char),1,fp);
		int mask = 0x80;
		while (mask>0) {
			array[i] = (c & mask) > 0;
	//		printf("%d", array[i]);
	//		puts("");
			mask >>= 1;
			(i)++;
		}
	} 
/*	char string[8]; string[0]='\0';
	for(int i=0;i<size;i++){
		if(array[1])
			str_append(string, '1');
		else
			str_append(string, '0');
	}*/
//	for(int i)
//	if(strcmp(string,)
}

/*
project: malloc.c:2394: sysmalloc: Assertion `(old_top == initial_top (av) && old_size == 0) || ((unsigned long) (old_size) >= MINSIZE && prev_inuse (old_top) && ((unsigned long) old_end & (pagesize - 1)) == 0)' failed.
Aborted (core dumped)
*/

//What happens if we try to pass the pointer to the file as an argument to the function and try to allocate the memory for some var.
