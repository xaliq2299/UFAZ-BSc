#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "LL.h"
#include "HT.h"
#include "read.h"
#include "bit.h"

char *readFile(char *filename); // to read file 
unsigned maxChar(LLNode *pList); // maximum character inside of file 
unsigned nbrChar(LLNode *pList);
double entropy(LLNode *pList); // to calculate the entropy of file

int main(){
    LLNode *pList=NULL;
   // int n;
  //  char cAction;
 	char l[8]; l[0] = '\0';
    
   // FILE *file = fopen("test.txt", "r"); 
    char *tc=readFile("test.txt");
//	char temp[strlen(tc)];
//	strcpy(temp,tc);

	int i=0;
	do{//printf("%c",tc[i]);
		if(!LL_Search_L(pList, tc[i]))  // if it is the first occurences of your character
		LL_add(&pList, tc[i], 1); // add it to a list
		i++;
	}while(tc[i]!='\n'); //'\0' for multi lines
//	free(tc);

	LL_Print(pList);
	LLNode *psList = NULL;  
	while(pList){
		LLNode *temp=pList->pNext;
		LL_sorted_add(&psList, pList->ch, pList->nVal);
		free(pList);
		pList=temp;
	}
	LL_Print(psList);

	//printf("The entropy value of the file is: %lf\n", entropy(psList));
	//printf("max nb occurences: %d\n",maxChar(psList));
	HLNode *hlist=readList(psList);
	HuffNode *huffmanTree=buildTree(hlist);
	//printHTree(huffmanTree);
	//printf("\n");

	//1st part
	int index=0;
	Huffchar *huffmanTable = malloc(sizeof(Huffchar)*(nbrChar(psList)));
	int j=0, *array = malloc(sizeof(int));
	binaryCodes(huffmanTree,huffmanTable,l,&index);
/*
	for(int i=0;tc[i] != '\n';i++){
		printBinary(huffmanTree,l,tc[i]);
		printf("tc[%d]=%c: %s\n", i, tc[i], l);
		for(int i=0;l[i] != '\0';i++){
			if(l[i] == '0')	array[j] = 0;
			else 		array[j] = 1;
			(j)++;
		}
		l[0] = '\0';
	}
	int arSize = j;
//	printf("size of array=%d\n", arSize);
	for(int i=0;i<arSize;i++)
		printf("%2d", array[i] );
//	puts("");
//	fclose(file); //important
	free(tc);

	//free(temp);
	//2nd part: writing to binary file
	//Writing dictionary to huffman table
	binaryCodes(huffmanTree,huffmanTable,l);
	FILE *fp = fopen("test.bin", "w+b");
	if(fp == NULL){	printf("error while opening the file\n");exit(1);}
	writeBinaryFile(fp,nbrChar(psList),huffmanTable);
	//Writing the text
	BIT_BUFFER buf;
	bb_init(&buf,fp);
	bb_fill(&buf, arSize, array);
	fclose(fp);
	
	//3rd part
	char *c = readBinaryFile("test.bin");
	*/
		
	return 0;
}

char *readFile(char *filename) {
    FILE *file = fopen(filename, "r");
    char *code;
    size_t n = 0;
    int c;
	if (file == NULL) return NULL; //could not open
    fseek(file, 0, SEEK_END);
    long f_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    code = malloc(f_size);
    while ((c = fgetc(file)) != EOF) {
        code[n++] = (char)c;
    }
    code[n] = '\0';
    fclose(file);   
    return code; // is a table of different characters that we have inside of file
}

unsigned maxChar(LLNode *pList){
  unsigned int nbchar=0;
  while(pList != NULL){
    nbchar+= pList->nVal;
    pList = pList->pNext;
  }
  return nbchar;
}

unsigned nbrChar(LLNode *pList){
	unsigned nbchar=0;
	while(pList != NULL){
	  nbchar++;
	  pList= pList->pNext;
	}
	return nbchar;
}

double entropy(LLNode *pList){
	unsigned int nbchar = maxChar(pList);
	double entropy = 0.0,p,f; // p(probability)
	while(pList != NULL){
	  p = pList->nVal/(float) nbchar;
	  f = p*(log2(1/p));
	  entropy+=f;
	  pList = pList->pNext;
	}
	return entropy;
}
