#include "LL.h"
//---------------------------------------
int LL_sorted_add(LLNode **ppList,char *digraph,int n){
  LLNode *pSent, *pCur;
  pSent=pCur=*ppList;
  while((pCur)&&(pCur->nVal < n)){
    pSent=pCur;
    pCur=pCur->pNext;
  }
  if (pSent==pCur){
    *ppList=(LLNode*)malloc(sizeof(LLNode)); 
    (*ppList)->nVal=n;
    strcpy( (*ppList)->digraph, digraph );
    (*ppList)->pNext=pCur;
  } else{
  pSent->pNext=(LLNode*)malloc(sizeof(LLNode)); 
  (pSent->pNext)->nVal=n;
  strcpy( (pSent->pNext)->digraph, digraph);
  (pSent->pNext)->pNext=pCur;
  }
  return 0;
}

//-----------------------------------------
int LL_RecursiveDestructor(LLNode **ppList){
  if(*ppList){
    LL_RecursiveDestructor(&((*ppList)->pNext));
    printf("removing [%d,%s], ",(*ppList)->nVal,(*ppList)->digraph); 
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
    printf("removing [%d,%s], ",(*ppList)->nVal,(*ppList)->digraph); 
    free(*ppList);
    *ppList=pTemp;
  }
  printf("\b\b\n"); 
  return 0;
}

//---------------------------------------
int LL_del(LLNode **ppList,char *digraph,int n){
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
int LL_add(LLNode **ppList,char *digraph, int n){
  LLNode *pTemp = *ppList;
  *ppList=(LLNode *) malloc(sizeof(LLNode));
  (*ppList)->pNext=pTemp;
  (*ppList)->nVal=n;
  strcpy( (*ppList)->digraph, digraph );
  return 0;
}

//----------------------------------------
int LL_Print(LLNode *pList){
  if (pList==NULL) {
    printf("pList-/\n");
    return 1;
  }
  printf("pList->[%d,%s]->",pList->nVal,pList->digraph);
  while(pList->pNext){
    pList=pList->pNext;
    printf("[%d,%s]->",pList->nVal,pList->digraph);
  }
  printf("\b/\n");
  return 0;
}
//---------------------------------------
int LL_RPrint(LLNode *pList){
  if (pList){
    printf("[%d,%s]->",pList->nVal,pList->digraph);
    LL_RPrint(pList->pNext);
  }
  printf("\n");
  return 0;
}
//----------------------------------------
int LL_RBPrint(LLNode *pList){
  if (pList){
    LL_RBPrint(pList->pNext);
    printf("[%d,%s]->",pList->nVal,pList->digraph);
  }
  printf("\n");
  return 0;
}
//----------------------------------------
int LL_Search_L(LLNode *pList, char *di){
  while((pList)&&strcmp(pList->digraph,di) != 0){
    pList=pList->pNext;
    if (pList==NULL) break;
  }
  if (pList){
    pList->nVal++;
    return 1;
  } else return 0;
}

