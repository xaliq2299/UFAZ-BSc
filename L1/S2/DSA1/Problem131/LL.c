#include <stdio.h>
#include <stdlib.h>
#include "LL.h"

int LL_sorted_add(SNode **ppList,int n){
  SNode *pSent, *pCur;
  pSent=pCur=*ppList;
  while((pCur)&&(pCur->nVal < n)){
    pSent=pCur;
    pCur=pCur->pNext;
  }
  if (pSent==pCur){
    *ppList=(SNode*)malloc(sizeof(SNode)); 
    (*ppList)->nVal=n;
    (*ppList)->pNext=pCur;
  } else{
  pSent->pNext=(SNode*)malloc(sizeof(SNode)); 
  (pSent->pNext)->nVal=n;
  (pSent->pNext)->pNext=pCur;
  }
  return 0;
}

int LL_RecursiveDestructor(SNode **ppList){
  if(*ppList){
    LL_RecursiveDestructor(&((*ppList)->pNext));
    printf("removing [%d], ",(*ppList)->nVal); 
    free(*ppList);
    *ppList=NULL;
  }
  printf("\b\b\n"); 
  return 0;
}

int LL_Destructor(SNode **ppList){
  while(*ppList){
    SNode *pTemp=(*ppList)->pNext;
    printf("removing [%d], ",(*ppList)->nVal); 
    free(*ppList);
    *ppList=pTemp;
  }
  printf("\b\b\n"); 
  return 0;
}

int LL_del(SNode **ppList,int n){
  SNode *pSent, *pCur;
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

int LL_add(SNode **ppList,int n){
  SNode *pTemp = *ppList; 
  *ppList=(SNode *) malloc(sizeof(SNode));
  (*ppList)->pNext=pTemp;
  (*ppList)->nVal=n;
  return 0;
}

int LL_Print(SNode *pList){  if (pList==NULL) {
    printf("pList-/\n");
    return 1;
  }
  printf("pList->[%d]->",pList->nVal);
  while(pList->pNext){
    pList=pList->pNext;
    printf("[%d]->",pList->nVal);
  }
  printf("\b/\n");
  return 0;
}

int LL_RPrint(SNode *pList){
  if (pList){
    printf("[%d]->",pList->nVal);
    LL_RPrint(pList->pNext);
  }
  printf("\n");
  return 0;
}

int LL_RBPrint(SNode *pList){
  if (pList){
    LL_RBPrint(pList->pNext);
    printf("[%d]->",pList->nVal);
  }
  printf("\n");
  return 0;
}

