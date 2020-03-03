#include "readIOF.h"

void writeBinaryFile(FILE *filename, int size, Huffchar tab[]){
	//save he size first in the file
	fwrite(&size,sizeof(int),1,filename);//putw(size,filename);
	//save the table of structures
	//for(int i=0;i<size;i++)
	//	fwrite(&tab[i],sizeof(Huffchar),1,filename);
	//save the compressed text
}

char *readBinaryFile(FILE *filename){
	int num=getw(filename); //read the size of the number of characters
	printf("the number of characters is %d\n", num);//for testing
	//READ the alphabet of the compression
	Huffchar newch = {0,""};
	for(int i=0;i<num;i++){
		fread(&newch,sizeof(Huffchar),1,filename);
		printf("character %c: %s\n", newch.l,newch.bitstab);
	}
	//read the compress text and translate
}
