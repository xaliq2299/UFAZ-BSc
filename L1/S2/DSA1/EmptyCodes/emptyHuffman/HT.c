#include"HT.h"
#include"LL.h"
//---------------------------------------------
HLNode *readList(LLNode *ll){
	HLNode *myList = (HLNode*)malloc(sizeof(HLNode));
	while(ll){
		HuffNode *new = malloc(sizeof(HuffNode));
		new->val = ll->nVal;
		new->ch = ll->ch;
		new->left = new->right = NULL;
		LLH_sorted_add(&myList, new->val, new);
		ll = ll->pNext;
	}
	return myList;
}
//---------------------------------------------
int LLH_sorted_add(HLNode **ppList,int n, HuffNode *new){
  LLNode *pSent, *pCur;
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
  (pSent->pNext)->nVal=n;
  (pSent->pNext)->hTree=new;
  (pSent->pNext)->pNext=pCur;
  }
  return 0;
}
//---------------------------------------------
HuffNode *buildTree(HLNode *myList){
	while(myList){
		if(myList->pNext == NULL) //The last node in the huffman list
			return myList->hTree;
		else{
			HLNode *first = myList; myList = myList->pNext;
			HLNode *second = myList; myList = myList->pNext;
			HufNode *top = (HuffNode*) malloc(sizeof(HuffNode));
			top->val = first->sum+second->sum;
			top->left = first->hTree;
			top->right = second->Tree;
			top->ch = '$';
			LLH_sorted_add(&myList, top->val, top);
			HL_Print(myList);
		}
	}
}
//----------------------------------------------
void printHTree(HuffNode *hTree){

}
//----------------------------------------------
int HL_Print(HLNode *pList){
	if( pList == NULL)
		
}
//-----------------------------------------------
