#include<string.h>
#include<math.h>
#include "LL.h"
#include "HT.h"

char *readFile();
unsigned maxChar(LLNode *pList);
unsigned nbrChar(LLNode *pList);
double entropy(LLNode *pList);


int main(){
  LLNode *pList=NULL;
  int n;
  char cAction, l;
  char *tc=readFile();

  	int i=0;
	do{//printf("%c",tc[i]);
	if(!LL_Search_L(pList, tc[i]))
	LL_add(&pList, tc[i], 1);
	i++;
	}while(tc[i]!='\n'); //'\0' for multi lines
	free(tc);

	LL_Print(pList);
	LLNode *psList = NULL;
	while(pList){
	LLNode *temp=pList->pNext;
	LL_sorted_add(&psList, pList->ch, pList->nVal);
	free(pList);
	pList=temp;
	}
	LL_Print(psList);

	printf("The entropy value of the file is: %lf \n",entropy(psList));

	//TODO
	
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
    return code;
}

unsigned maxChar(LLNode *pList){
	unsigned int nbchar = 0;
	while(pList!=NULL){
		nbchar+=(unsigned)pList->nVal;
		pList = pList->pNext;
	}
		
	return nbchar;
}

unsigned nbrChar(LLNode *pList){
	unsigned nbchar = 0;
	while(pList!=NULL){
		nbchar++;
		pList = pList->pNext;
	}
	
	return nbchar;
}

double entropy(LLNode *pList){
	int nbchar = maxChar(pList);
	double entrop = 0.0, p, f;
	
	while(pList != NULL){
		p=pList->nVal/(float)nbchar;
		f = p*log2(1/p); 
		entrop+=f;
		pList = pList->pNext;
	}
	
	return entrop;
}
