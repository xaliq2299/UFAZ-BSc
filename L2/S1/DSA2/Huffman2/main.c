#include<string.h>
#include <math.h>
#include "LL.h"
#include "HT.h"

char *readFile(); // to read file 
unsigned maxChar(LLNode *pList); // maximum character inside of file 
unsigned nbrChar(LLNode *pList);
double entropy(LLNode *pList); // to calculate the entropy of file

void inBinary(char *digraph, HuffNode *hTree);

int main(){
	LLNode *pList=NULL;
	int n=0;
	char cAction, l;
	char *tc=readFile();

	for(int i=0;tc[i] != '\n';i++)
		n++;
	//printf("%d\n", n);
	int i=0;
	
	if(n%2 == 0){
		do{//printf("%c",tc[i]);
			char string[3];
			string[0]=tc[i];
			string[1]=tc[i+1];
			string[2]='\0';
			printf("%s\n", string);
			if(!LL_Search_L(pList,string))  // if it is the first occurences of your character
				LL_add(&pList, string, 1); // add it to a list
			i+=2;
		} while(tc[i]!='\n'); //'\0' for multi lines
	}	
	else{
		for(int i=0;i<=n-2;i+=2){
			char string[3];
			string[0]=tc[i];
			string[1]=tc[i+1];
			string[2]='\0';
			printf("%s\n", string);
			if(!LL_Search_L(pList,string))  // if it is the first occurences of your character
				LL_add(&pList, string, 1); // add it to a list
		}
		char string[3]; string[0]=tc[n-1]; string[1]=' '; string[2] = '\0';
		printf("%s\n", string);
		if(!LL_Search_L(pList,string))  // if it is the first occurences of your character
			LL_add(&pList, string, 1); // add it to a list
	}
	free(tc);

	LL_Print(pList);
	LLNode *psList = NULL;  
	while(pList){
	LLNode *temp=pList->pNext;
	LL_sorted_add(&psList, pList->digraph, pList->nVal);
	free(pList);
	pList=temp;
	}
	LL_Print(psList);

	printf("The entropy value of the file is: %lf \n",entropy(psList));
	printf("max nb occurences: %d\n",maxChar(psList));
	HLNode *hlist=readList(psList);
	HuffNode *huffmanTree=buildTree(hlist);
	printHTree(huffmanTree);
	printf("\n");

	//DSA2 starts here
	//for(int i=0;tc[i] != '\n';i++){}
	//inBinary(" ",huffmanTree);
	
	return 0; 
}

char *readFile() {
    FILE *file = fopen("test.txt", "r");
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
    return code; // is a table of different characters that we have iside of file
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

void inBinary(char *digraph, HuffNode *hTree){
	if(hTree->left){
		printf("%d",0);
		inBinary(digraph,hTree->left);
	}
	if( strcmp(hTree->digraph, digraph) == 0 )
		return;
	else
		printf("\b");
	if(hTree->right){
		printf("%d",1);
		inBinary(digraph,hTree->right);
	}
	printf("\b");
}
