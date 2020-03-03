#include"HT.h"
#include"LL.h"
//---------------------------------------------
HLNode *readList(LLNode *ll){
 HLNode *myList =  malloc(sizeof(HLNode));
 while(ll != NULL){
 	HuffNode *new = malloc(sizeof(HuffNode));
 	new->val = ll->nVal;
 	new->ch = ll->ch;
 	new->left = NULL;
 	new->right = NULL;
 	LLH_sorted_add(&myList,new->val,new);
 	ll= ll->pNext;
 }
 return myList;
}
//---------------------------------------------
int LLH_sorted_add(HLNode **ppList,int n, HuffNode *new){
  HLNode *pSent, *pCur;
  pSent=pCur=*ppList;
  while((pCur)&&(pCur->sum < n)){
    pSent=pCur;
    pCur=pCur->pNext;
  }
  if (pSent==pCur){
    *ppList=(HLNode*)malloc(sizeof(HLNode)); 
    (*ppList)->sum=n;
    (*ppList)->hTree=new;
    (*ppList)->pNext=pCur;
  } else{
  pSent->pNext=(HLNode*)malloc(sizeof(HLNode)); 
  (pSent->pNext)->sum=n;
  (pSent->pNext)->hTree=new;
  (pSent->pNext)->pNext=pCur;
  }
  HL_Print(*ppList);
  return 0;
}
//---------------------------------------------
HuffNode *buildTree(HLNode *myList){
  while(myList){
    if(myList->pNext == NULL)// this is the last node in the huffman list
      return myList->hTree;
    else{
      HLNode *first = myList; 
      myList = myList->pNext;
      HLNode *second = myList; 
      myList = myList->pNext;
      HuffNode *top = (HuffNode *)malloc(sizeof(HuffNode));
      top->val = first->sum + second->sum;
      top->left = first->hTree;
      top->right = second->hTree;
      top->ch = '$'; // just to know that there is a node , it can be empty
      LLH_sorted_add(&myList,top->val,top);
    }
  }
}
//----------------------------------------------
void printHTree(HuffNode *hTree){ // it is like to print binary tree
  if(hTree != NULL){
    printHTree(hTree->left);
    printf("%c \t",hTree->ch);
    printHTree(hTree->right);  
  }
}
//----------------------------------------------
int HL_Print(HLNode *pList){ // it is like to print the linked list
  if (pList==NULL) {
    printf("pList-/\n");
    return 1;
  }
  printf("pList->[%d]->",pList->sum);
  while(pList->pNext){
    pList=pList->pNext;
    printf("[%d]->",pList->sum);
  }
  printf("\b/\n");
  return 0;
}
//-----------------------------------------------
