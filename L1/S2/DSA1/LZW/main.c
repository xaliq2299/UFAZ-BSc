#include <stdio.h>
#include <string.h>
#include "LL.h"

LLNode* dictAscii(){
	char *c = malloc(sizeof(1));
	LLNode *dict = malloc(sizeof(LLNode));
	LLNode *pCur = dict;
	
	for(int i=0;i<256;i++){
		pCur->nVal = i+1;
		printf("%d %c -->Added to dictionary\n", i, i);
		strncpy(pCur->string, c, 1); //c[0] = (char)i;
		LL_add(&dict, c, i+1);	
		
		//strcpy(pCur->string, );
		//pCur = pCur->pNext;
	}
	return dict;
}

int main(){
	LLNode *dict = dictAscii();
	
	
	return 0;
}
