#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int nVal;
  struct Node *pNext;
} SNode;

LL_Print(SNode *pList);
LL_add(SNode **ppList,int n);
LL_del(SNode **ppList,int n);

int main(){
  SNode *pList=NULL;
  int n;
  char cAction;

  do{
    printf("(a)dd, (d)elete, (q)uit: ");scanf(" %c",&cAction);
    if (cAction=='a'){
      printf("Enter a number to add to the list: ");scanf(" %d",&n);
      LL_add(&pList, n);
    }
    if (cAction=='d'){
      printf("Enter a number to remove from the list:");scanf(" %d",&n);
      LL_del(&pList, n);
    }
    LL_Print(pList);
    printf("\n");
  }while(cAction!='q');

  return 0;
}


