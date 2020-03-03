#include <stdio.h>
#include "readIOF.h"
#include "v2bitIO.h"

FILE *entre;
FILE *sortie;
FILE *testBinary;

int main(int argc, char **argv){
	testBinary = fopen("TESTbinary.bin","w+b");
	int bits[33]={1,0,1,0,1,1,1,0,0,1,1,1,0,0,1,0,1,0,1,1,1,0,0,0,0,0,1,0,1,0,0,1,0};
	BIT_BUFFER buf;
	bb_init(&buf,testBinary);
	bb_fill(&buf, 33, bits);
/*	if(argc > 1){
		sortie=fopen(argv[1],"w+b");
		if(sortie == NULL){	printf("Couldn't open the file\n"); return 0;}
	
	//int i;
	Huffchar array[5];
	//for(int i=0;i<5;i++){
	//	printf("\nGIVE THE character %d: ", i+1); scanf(" %c", &array[i].l);
	//	printf("\nGIVE bits coding : "); scanf(" %s", array[i].bitstab);
	//}
		int num=5;
		//CALLING THE FUNCTION TO WRITE
		fwrite(&num,sizeof(int),1,sortie);//putw(size,filename); writeBinaryFile(sortie,5,array);
		fclose(sortie);
		//READING COMPRESSED FILE PROCESS
		entre = fopen(argv[1],"rb");
		if(entre == NULL) {printf("Couldnt open the file to read\n");
		return 0;}
	
	//readBinaryFile(entre);
	fclose(entre);
	}
	else
		printf("Usage: %s nameOf File \n\n", argv[0] );
*/	
	return 0;
}
