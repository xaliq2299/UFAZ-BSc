#include "LL.h"
#include <string.h> //added afterwards
//---------------------------------------
int LL_sorted_add(LLNode **ppList,char *c,int n){
  LLNode *pSent, *pCur;
  pSent=pCur=*ppList;
  while((pCur)&&(pCur->nVal < n)){
    pSent=pCur;
    pCur=pCur->pNext;
  }
  if (pSent==pCur){
    *ppList=(LLNode*)malloc(sizeof(LLNode)); 
    (*ppList)->nVal=n;
    strcpy((*ppList)->string, c); //(*ppList)->string=c;
    (*ppList)->pNext=pCur;
  } else{
  pSent->pNext=(LLNode*)malloc(sizeof(LLNode)); 
  (pSent->pNext)->nVal=n;
  strcpy( (pSent->pNext)->string, c); //(pSent->pNext)->ch=c;
  (pSent->pNext)->pNext=pCur;
  }
  return 0;
}

//-----------------------------------------
int LL_RecursiveDestructor(LLNode **ppList){
  if(*ppList){
    LL_RecursiveDestructor(&((*ppList)->pNext));
    //printf("removing [%d,%c], ",(*ppList)->nVal,(*ppList)->ch); 
    free(*ppList);
    *ppList=NULL;
  }
  printf("\b\b\n"); 
  return 0;
}
//------------------------------------------------------
int LL_Destructor(LLNode **ppList){
  while(*ppList){
    LLNode *pTemp=(*ppList)->pNext;
    //printf("removing [%d,%c], ",(*ppList)->nVal,(*ppList)->ch); 
    free(*ppList);
    *ppList=pTemp;
  }
  printf("\b\b\n"); 
  return 0;
}

//---------------------------------------
int LL_del(LLNode **ppList,char *c,int n){
  LLNode *pSent, *pCur;
  pSent=pCur=*ppList;
  while((pCur)&&(pCur->nVal!=n)){
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
//----------------------------------------
int LL_add(LLNode **ppList,char *c, int n){
  LLNode *pTemp = *ppList;
  *ppList=(LLNode *) malloc(sizeof(LLNode));
  (*ppList)->pNext=pTemp;
  (*ppList)->nVal=n;
  strcpy((*ppList)->string, c); //(*ppList)->ch=c;
  return 0;
}

//----------------------------------------
int LL_Print(LLNode *pList){
  if (pList==NULL) {
    printf("pList-/\n");
    return 1;
  }
//  printf("pList->[%d,%c]->",pList->nVal,pList->ch);
  while(pList->pNext){
    pList=pList->pNext;
//    printf("[%d,%c]->",pList->nVal,pList->ch);
  }
  printf("\b/\n");
  return 0;
}

//---------------------------------------
int LL_RPrint(LLNode *pList){
  if (pList){
//    printf("[%d,%c]->",pList->nVal,pList->ch);
    LL_RPrint(pList->pNext);
  }
  printf("\n");
  return 0;
}

//----------------------------------------
int LL_RBPrint(LLNode *pList){
  if (pList){
    LL_RBPrint(pList->pNext);
//    printf("[%d,%c]->",pList->nVal,pList->ch);
  }
  printf("\n");
  return 0;
}
//----------------------------------------
int LL_Search_L(LLNode *pList, char *c){
  while((pList)&&(strcmp( pList->string, c ) != 0)){
    pList=pList->pNext;
    if (pList==NULL) break; 
  }
  if (pList){
    pList->nVal++;
    return 1;
  } else return 0;
}

