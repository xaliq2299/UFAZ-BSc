#ifndef LIST
#define LIST

typedef struct Node {
  int nVal;
  struct Node *pNext;
} SNode;

int LL_sorted_add(SNode **ppList,int n);
int LL_add(SNode **ppList,int n);
int LL_del(SNode **ppList,int n);
int LL_Print(SNode *pList);
int LL_Destructor(SNode **ppList);
int LL_sorted_add(SNode **ppList,int n);
int LL_RecursiveDestructor(SNode **ppList);
int LL_Destructor(SNode **ppList);
int LL_del(SNode **ppList,int n);
int LL_add(SNode **ppList,int n);
int LL_Print(SNode *pList);
int LL_RPrint(SNode *pList);
int LL_RBPrint(SNode *pList);

#endif
