#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NbLL 11

typedef struct Word {
  char s[50]; // to store the word
  int nNb;    // to store the number of occurrences
} SWord;

typedef struct Node { // This is a linked list
  SWord wsWord;
  struct Node *pNext;
} SNode;

/*
typedef struct Node { // This is a linked tree
  SWord wsWord;
  struct Node *pLC, *pRC;
} SNode;
*/

//int LL_sorted_add(SNode **ppList,int n);
int LL_add(SNode **,char *);
int LL_del(SNode **,char *);
int LL_Print(SNode *);
int LL_Destructor(SNode **);

int LL_Destructor(SNode **ppList){
  while(*ppList){
    SNode *pTemp=(*ppList)->pNext;
    printf("removing [%s], ",((*ppList)->wsWord).s); 
    free(*ppList);
    *ppList=pTemp;
  }
  printf("\b\b\n"); 
  return 0;
}

int LL_del(SNode **ppList,char *s){
  SNode *pSent, *pCur;
  pSent=pCur=*ppList;
  while((pCur)&&(strcmp((pCur->wsWord).s,s))){
    pSent=pCur;
    pCur=pCur->pNext;
    if (pCur==NULL) break; 
  }
  if (pCur){
    if (pCur==*ppList) *ppList=pCur->pNext;
    else pSent->pNext=pCur->pNext;
    free(pCur);
    return 0;
  } else return 1;
}

int LL_add(SNode **ppList,char *s){
  SNode *pTemp = *ppList; 
  if (*ppList==NULL){ // if the list is empty, create the first node.
    *ppList=(SNode *) malloc(sizeof(SNode));
    strcpy(((*ppList)->wsWord).s,s);
    ((*ppList)->wsWord).nNb=1;
    (*ppList)->pNext=NULL;
    return 0;
  }
  for(;(pTemp->pNext)&&(strcmp(s,(pTemp->wsWord).s));pTemp=pTemp->pNext);
  if(!strcmp(s,(pTemp->wsWord).s)) (pTemp->wsWord).nNb++;
  else{
    pTemp->pNext=(SNode *) malloc(sizeof(SNode));
    strcpy(((pTemp->pNext)->wsWord).s,s); ((pTemp->pNext)->wsWord).nNb=1;
    (pTemp->pNext)->pNext=NULL;
  }
  return 0;
}

int LL_Print(SNode *pList){
  if (pList==NULL) { printf("[NULL]\n"); return 1; }
  printf("[XXXX]->(%s,%d)->",(pList->wsWord).s, (pList->wsWord).nNb);
  while(pList->pNext){
    pList=pList->pNext;
    printf("(%s,%d)->",(pList->wsWord).s, (pList->wsWord).nNb);
  }
  printf("\b/\n");
  return 0;
}

int hash(char *s, int m){
  int h=0;
  for (int n=0;s[n];n++)
    h=(h*256 + s[n]) % m;
  return h;
}

int main(){
  SNode *pList[NbLL];
  int n;
  char cAction;
  char *szText="UFAZ aims at acquiring academic excellence not only in Azerbaijan but also in the region thanks to the quality of the full-time and visiting highly-qualified French and Azerbaijani Professors. Those dedicated and experienced instructors from Azerbaijan and France (Strasbourg and Rennes 1 universities) are delivering their lectures in English. French course is a part of the curriculum. It is taught as a second language throughout the program. This enhances students' chances to continue their studies in a French speaking country at the master level. Our potential candidates are Azerbaijani students who just graduated from high school with a strong scientific background and foreign high-school graduates. Local students would have to successfully complete the exam of the State Examination Center (SEC). Both local and foreign prospective students need to demonstrate basic knowlegde of English and pass the UFAZ recruitment exam organized by Strasbourg University in Baku. Foreign students are welcome to apply on a paying basis.";
  for(int i=0;i<NbLL;i++) pList[i]=NULL;

  do{
    printf("(l)oad text, (p)rint table, (d)elete word, (h)ash value, (D)estruct table: ");
    scanf(" %c",&cAction);
    if (cAction=='l'){
      char *pCur, szWord[50]; pCur=szText;
      while(*pCur){
        sscanf(pCur," %s",szWord);
        for(int i=0;szWord[i];i++,pCur++);
        if(*pCur) pCur++;
        LL_add(&(pList[hash(szWord,NbLL)]), szWord);
      }
      for (int i=0;i<NbLL;i++){
        LL_Print(pList[i]);
      }
    }
    if (cAction=='h'){
      char szWord[50];
      printf("Enter a word: ");scanf("%s",szWord);
      printf("The hash value of %s is %d\n",szWord, hash(szWord, NbLL));
    }
    if (cAction=='d'){
      char szWord[50];
      printf("Enter a word to delete from table: ");scanf("%s",szWord);
      if( LL_del(&(pList[hash(szWord, NbLL)]), szWord) )
        fprintf(stderr, "This word doesn't exist in the table\n");
      for (int i=0;i<NbLL;i++)
        LL_Print(pList[i]);
    }
    /*
    if (cAction=='s'){
      printf("Sorted adding of a number to the list: ");scanf(" %d",&n);
      LL_sorted_add(&pList, n);
      if (pList==NULL) printf("pList = NULL!!\n");
      LL_Print(pList);
    } else if (cAction=='R'){
      LL_RecursiveDestructor(&pList);
    } else if (cAction=='D'){
      LL_Destructor(&pList);
    } else if (cAction=='S'){
      int a[]={13, 9, 98, 15, 5, 12, 95};
      for (int i=0;i<7;i++)
        LL_sorted_add(&pList, a[i]);
      LL_Print(pList);
    } else if (cAction=='p'){
      LL_RPrint(pList);
    } else if (cAction=='P'){
      LL_RBPrint(pList);
    }
    */
  }while(cAction!='q');

  return 0;
}



