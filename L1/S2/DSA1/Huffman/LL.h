#ifndef __LL_H_
#define __LL_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int nVal;
  char ch;
  struct Node *pNext;
} LLNode;

int LL_sorted_add(LLNode **ppList,char c,int n);
int LL_add(LLNode **ppList,char c,int n);
int LL_del(LLNode **ppList,char c,int n);
int LL_Print(LLNode *pList);
int LL_Destructor(LLNode **ppList);
int LL_RecursiveDestructor(LLNode **ppList);
int LL_RPrint(LLNode *pList);
int LL_RBPrint(LLNode *pList);
int LL_Search_L(LLNode *pList, char c);

#endif 
