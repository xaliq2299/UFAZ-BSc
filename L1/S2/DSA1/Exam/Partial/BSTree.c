/*************************************/
/*******BINARY SEARCH TREE************/
/*************************************/
#include<stdio.h>
#include<stdlib.h>
#include"BSTree.h"
#include"queue.h"
//#include<math.h>
//#define DIGITS 2
/*
typedef struct Node{   
int val;
struct Node *left, *right;
}BSNode;

BSNode *constructTree(int n);
BSNode *add(BSNode *pTree, int n);
//void printNode(BSNode *pTree){printf("%d \t", pTree->val);}
void treeTraverseA(BSNode *pTree);
void treeTraverseD(BSNode *pTree);
int treeNodeNumber(BSNode *pTree, int *d);
int treeDepth(BSNode *pTree);
void treePrintLevel(BSNode *pTree, int level);
void treePrintLevels(BSNode *root, int *d);
int BSearch(BSNode *pTree, int n);
*/

//int main(){
//BSNode *BStree=NULL;
//int d=0, s; int *number; number=&d;

//Add Nodes
//int tb[]={78,55,98,59,34,22,95,5,9,456,6985,3,4658,12,99,100,150};
//int tab[]={50,25,75,12,27,55,90,10,14,26,40,52,57,85,95};
//for (int i=0;i<15;i++) BStree=add(BStree, tab[i]);
/*
treeTraverseA(BStree);
printf("\n");
treeTraverseD(BStree);
printf("\n");
*/
//int o=treeNodeNumber(BStree,number);
//printf("The number of elements inside the tree is %d\n",*number);
/*
printf("Search for a value into the tree:\n");
printf("Give us the value :\t"); scanf("%d",&s);
printf("------> Searching \n");
if(BSearch(BStree, s)) printf("FOUND ..\n");
else printf("This value %d DON'T exist in the tree.\n",s);
*/
//*number = treeDepth(BStree);

//treePrintLevels(BStree,number);

//printf("The depth is  === %d \n",treeDepth(BStree));

//return 0;
//}
//------------------------------------------------------------------
BSNode *constructTree(int n){
BSNode *Temp=(BSNode *)malloc(sizeof(BSNode));
Temp->val=n;
Temp->left=NULL;
Temp->right=NULL;
}
//------------------------------------------------------------------
BSNode *add(BSNode *pTree, int n){
if(pTree==NULL) return constructTree(n);
if(n<pTree->val) pTree->left =add(pTree->left,n);
else if(n>pTree->val) pTree->right =add(pTree->right,n);
return pTree;
}
//------------------------------------------------------------------
void treeTraverseA(BSNode *pTree){
if(pTree !=NULL){
treeTraverseA(pTree->left);
printNode(pTree);
treeTraverseA(pTree->right);
}}
//------------------------------------------------------------------
void treeTraverseD(BSNode *pTree){
if(pTree !=NULL){
treeTraverseD(pTree->right);
printNode(pTree);
treeTraverseD(pTree->left);
}}
//-------------------------------------------------------------------
int treeNodeNumber(BSNode *pTree, int *d){
if(pTree !=NULL){
treeNodeNumber(pTree->left,d);
(*d)++; // COUNTING 
treeNodeNumber(pTree->right,d);
}
}
//--------------------------------------------------------------------
int BSearch(BSNode *pTree, int n){
if (pTree==NULL) return 0;
else {if(pTree->val==n) return 1;
else if(pTree->val>n) BSearch(pTree->left, n);
else if(pTree->val<n) BSearch(pTree->right, n);
else return 0;
}}
//--------------------------------------------------------------------
/*void treePrintLevel(BSNode *pTree, int level){
if (pTree!=NULL){
if (level==1) printf("%d ",pTree->val);
else if (level>1){
treePrintLevel(pTree->left, level-1);
treePrintLevel(pTree->right, level-1);
}}}
//----------------------------------------------------
void treePrintLevels(BSNode *pTree, int *d){
for (int i=1;i<=*d;i++) 
{treePrintLevel(pTree, i);
printf("\n");
}}*/
//----------------------------------------------------
int treeDepth(BSNode *pTree){
if (pTree==NULL) return 0;
else{
int left=treeDepth(pTree->left);
int right=treeDepth(pTree->right);
if (left>right) {return left+1;}
else {return right+1;}
}
}

void treePrintLevel(BSNode *pTree, int level, SFifo *queue){
if (pTree!=NULL){
if (level==1) enQueue(queue, pTree->val);
else if (level>1){
treePrintLevel(pTree->left, level-1, queue);
treePrintLevel(pTree->right, level-1, queue);
}}}
