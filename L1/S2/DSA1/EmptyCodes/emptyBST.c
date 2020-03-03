/*************************************/
/*******BINARY SEARCH TREE************/
/*************************************/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Node{   
	int val;
	struct Node *left, *right;
}BSNode;

BSNode *constructTree(int n);
BSNode *add(BSNode *pTree, int n);
void treePrint(BSNode *pTree){printf("%d \t", pTree->val);}
void treeTraverseA(BSNode *pTree);
void treeTraverseD(BSNode *pTree);
int treeNodeNumber(BSNode *pTree, int *d);
int treeDepth(BSNode *pTree, int *d);
void treePrintLevel(BSNode *pTree, int level);
void treePrintLevels(BSNode *root, int *d);
int BSearch(BSNode *pTree, int n);
BSNode *del(BSNode *pTree, int n);

int main(){
	BSNode *BStree=NULL;
	int d=0, s; int *depth; depth=&d;

	//Add Nodes
	int tab[]={78,55,98,59,34,22,95,5,9,456,6985,3,4658,12,99,100,150};
	for (int i=0;i<17;i++) BStree=add(BStree, tab[i]);
	
	treeTraverseA(BStree);
	printf("\n");
	treeTraverseD(BStree);
	printf("\n");

	printf("Search for a value into the tree:\n");
	printf("Give us the value :\t"); scanf("%d",&s);
	printf("------> Searching \n");
	if(BSearch(BStree, s)) printf("FOUND ..\n");
	else printf("This value %d DON'T exist in the tree.\n",s);

	return 0;
}
