#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DIGITS 2

typedef struct Node{   
	int val;
	struct Node *left, *right;
	int height;// the difference between right and left depths
}AVLNode;

int digits(int num){
	int n=0;
	while(num!=0){
		n++;
		num/=10;
	}
	return n;	
}

int treeDepth(AVLNode *pTree){
	if(pTree == NULL)	return 0;
	else if(pTree->right == NULL && pTree->left == NULL) return 0;
	else{
		int left = treeDepth(pTree->left);
		int right = treeDepth(pTree->right);
		
		if(left>right)
			return left+1;
		else
			return right+1;	
	}
}
//-------------------------------------------------------
AVLNode* BSearch(AVLNode *pTree, int n){
	if(pTree == NULL)	return NULL;
	else{
		if(pTree->val == n) return pTree;
		else if (pTree->val > n)	BSearch(pTree->left, n);
		else if (pTree->val < n)	BSearch(pTree->right, n);
		
	else  return NULL;
	}
}
//--------------------------------------------------------
AVLNode *constructTree(int n){
	AVLNode *pTree = (AVLNode*) malloc(sizeof(AVLNode));
	pTree->val = n;
	pTree->left=pTree->right = NULL;

	return pTree;
}
//--------------------------------------------------------
int getBalance(AVLNode *pTree, int n){
	int a;
	AVLNode *new = BSearch(pTree, n);
	if(new == NULL)	{printf("%d doesnt exist in tree\n", n); return 1;}
	else{
		a = treeDepth(new->left)-treeDepth(new->right);		
	}
	
	return a;
}
//----------------------------------------------------------
int height(AVLNode *pTree){
	return treeDepth(pTree);
}
//----------------------------------------------------------
AVLNode rightRotation(AVLNode *pTree){
	AVLNode *temp1;
	AVLNode *temp2;
		
	temp1 = pTree->left;
	temp2 = temp1->right;
	temp1->right = pTree;
	pTree->left = temp2;
	
	return *temp1;
}
//-----------------------------------------------------------
void insert(AVLNode **ppTree, int n){
	if(*ppTree == NULL)	*ppTree = constructTree(n);
	
	if((*ppTree)->val > n)
		insert(&(*ppTree)->left, n);
	else if ((*ppTree)->val < n)
		insert(&(*ppTree)->right, n);	
}
//----------------------------------------------------------------------
void spaces(int depth, int level, int op){
	if(op==0) { //printf("d=%d,l=%d \n",depth,level);//spaces before we start printing numbers
    	for(int i=0;i<(DIGITS)*(pow(2,depth-level)-1); i++) printf(" ");
    }
	else if(op==1) { //printf("d=%d,l=%d \n",depth,level);//spaces between numbers
		if(depth == level) {for(int i=0;i<(DIGITS)*(pow(2,depth-level)); i++) printf(" ");}
		else {for(int i=0;i<2*(DIGITS)*(pow(2,depth-level)-1)+DIGITS; i++) printf(" ");}
	}
	else if(op==2) { //spaces for case of between branches
		for(int i=0;i<(DIGITS)*(pow(2,depth-level)-1); i++) printf(" ");}
}
//----------------------------------------------------------------------
void branches(int depth, int level){
	if (depth != level){
		spaces(depth,level-1,0);
		for (int i=0;i<pow(2,level);i++)
		if (i%2==0) {printf("/"); spaces(depth,level,2);}
		else {printf("\\"); spaces(depth,level,2);}
	}
}
//----------------------------------------------------------------------
void treePrintL(AVLNode *pTree, int depth, int level, int cl){ //printing with spaces between numbers
	if (pTree!=NULL){
		if (level==1) {
			printf("%d",pTree->val); spaces(depth,cl,1);
		}
		else if (level>1){
			treePrintL(pTree->left, depth, level-1, cl);
			treePrintL(pTree->right, depth, level-1, cl);
		}
	}
	else {//printing an empty space for numbers !
		if (level==1) {printf("00"); spaces(depth,cl,1);}
	}
}
//---------------------------------------------------------------------
void treePrint(AVLNode *pTree, int *d){
	for (int i=1;i<=*d;i++) {
		spaces(*d,i,0);
		treePrintL(pTree, *d, i, i); printf("\n");
		//branches(*d,i);printf("\n");
	}
}
//------------------------------------------
int main(){
	AVLNode *myTree = NULL;
	int d=4;
	
	int tab[] = {50, 25, 75, 30, 2, 1};
	for (int i=0;i<6;i++) insert(&myTree, tab[i]);
	treePrint(myTree, &d);
	printf("%d\n", height(myTree) );
	printf("%d\n", getBalance(myTree, 50) );
	printf("%d\n", treeDepth(myTree) );
	
	return 0;
}
