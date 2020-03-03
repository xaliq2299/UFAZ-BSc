/*************************************/
/*******BINARY SEARCH TREE************/
/*************************************/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define DIGITS 2

typedef struct Node{   
	int val;
	struct Node *left, *right;
}BSNode;
//------------------------------------------
BSNode *constructTree(int n){
	BSNode *pTree = (BSNode*) malloc(sizeof(BSNode));
	pTree->val = n;
	pTree->left=pTree->right = NULL;

	return pTree;
}
//------------------------------------------
BSNode *add(BSNode *pTree, int n){
	if(pTree == NULL)	pTree = constructTree(n);
	
	if(pTree->val > n)
		pTree->left = add(pTree->left, n);
	else if (pTree->val < n) 
		pTree->right = add(pTree->right, n);
	else return pTree;
//iterative adding 
/*
  SNode *pCur=*ppTree;
  if(*ppTree == NULL){
    pNew->nVal=n;
    pNew->pLC=pNew->pRC=NULL;
    *ppTree=pNew;
    return 1;
  }
 
  while( pCur->pLC || pCur->pRC){
    if(n>pCur->nVal && pCur->pRC){
      pCur=pCur->pRC;
      continue;
    }
    else if(n<pCur->nVal && pCur->pLC){
      pCur=pCur->pLC;
      continue;
    }
    else break;
}  	
  
  if(n>pCur->nVal){
    pCur->pRC=pNew;
    pNew->nVal=n;
    pNew->pRC=pNew->pLC=NULL;
  }
  else if(n<pCur->nVal){
    pCur->pLC=pNew;
    pNew->nVal=n;
    pNew->pRC=pNew->pLC=NULL;
  }
  */
}
//PRINTING A TREE EVEN IF NOT BALANCED
int digits(int num){
	int n=0;
	while(num!=0){
		n++;
		num/=10;
	}
	return n;	
}
//------------------------------------------
void treePrint(BSNode *pTree){
	printf("%d\t", pTree->val);
}
//------------------------------------------
void treeTraverseA(BSNode *pTree){
	if(pTree!=NULL && pTree->left != NULL)
		treeTraverseA(pTree->left);
	printf("%d\n", pTree->val); //treePrint(pTree);
	if(pTree!=NULL && pTree->right != NULL)
		treeTraverseA(pTree->right);
}
//------------------------------------------
void treeTraverseD(BSNode *pTree){	
	if(pTree!=NULL && pTree->right != NULL)
		treeTraverseD(pTree->right);
	printf("%d\n", pTree->val); //treePrint(pTree); 
	if(pTree!=NULL && pTree->left != NULL)
		treeTraverseD(pTree->left);
}
//------------------------------------------
int treeNodeNumber(BSNode *pTree, int *d){
	if(pTree != NULL){
		treeNodeNumber(pTree->left, d);
		//Counting
		*d++;
		treeNodeNumber(pTree->right, d);
	}
	return *d;
}
//------------------------------------------
int treeDepth(BSNode *pTree){
	if(pTree == NULL)	return 0;
	else{
		int left = treeDepth(pTree->left);
		int right = treeDepth(pTree->right);
	
	if(left>right)	{
		//printf("the left is incremented, NOW left = %d\n", left+1);
		return left+1;}
		else
		{
			//printf("the left is incremented, NOW left = %d\n", left+1);
			return right+1;
		}		
	}
}
//------------------------------------------
void treePrintLevel(BSNode *pTree, int level){
	//int i=0;
	int depth = treeDepth(pTree);
	if(pTree != NULL){
		if(level == 1) { treePrint(pTree); for (int i=0;i<2*digits(pTree->val)*(pow(2,depth-(level)-1)-1);i++)// problem
		printf(" ");}
	else if( level > 1){
			treePrintLevel(pTree->left, level-1);
			treePrintLevel(pTree->right, level-1);
		}
	}
}
//------------------------------------------
void treePrintLevels(BSNode *pTree, int *d){
	int depth = treeDepth(pTree);
	for(int i=0;i<=*d;i++){
		for(int j=0;j<digits(pTree->val)*(pow(2,depth-(i+1))-1);j++)
			printf(" ");//optional
		//depth--;
		treePrintLevel(pTree, i+1);
		//printf("\n");
		for(int c=0;c<16;c++)	printf(" ");
		//printf("/");
		printf("\n");
	}
	
	printf("\b");
}
//----------------------------------------------------------------------
void spaces(int depth, int level, int op){
	if(op==0) { //printf("d=%d,l=%d \n",depth,level);//spaces before we start printing numbers
    	for(int i=0;i<(DIGITS)*(pow(2,depth-level)-1); i++) printf(" "); // the only problem with digits
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
void treePrintL(BSNode *pTree, int depth, int level, int cl){ //printing with spaces between numbers
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
void treePrint(BSNode *pTree, int *d){
	for (int i=1;i<=*d;i++) {
		spaces(*d,i,0);
		treePrintL(pTree, *d, i, i); printf("\n");
		//branches(*d,i);printf("\n");
	}
}
//------------------------------------------
int BSearch(BSNode *pTree, int n){
	if(pTree == NULL)	return 0;
	else{
		if(pTree->val == n) return 1;
		else if (pTree->val > n)	BSearch(pTree->left, n);
		else if (pTree->val < n)	BSearch(pTree->right, n);
		
	else  return 0;
	}
}
//-----------------------------------------
BSNode *successor(BSNode *pTree){
	if(pTree->right == NULL) return NULL;
	else return successor(pTree->right);
}
//-----------------------------------------
BSNode *min(BSNode *pTree){
	if(pTree->left == NULL)	return pTree;
	else
	{
		return min(pTree->left);
	}
}
//------------------------------------------
void delete(int x, BSNode *pTree){
	//three cases:
	//1.leaf 2.one child 3.two child
	BSNode *q;
	if(pTree != NULL){
		if(pTree->val < x) delete(x, pTree->right);
		else if(pTree->val > x)	delete(x, pTree->left);
		else{
			if(pTree->left == NULL && pTree->right == NULL){ // leaf case
				pTree->val = 0;
				//free(pTree);
				//parent should point to NULL value
			}
			else if(pTree->left == NULL)	pTree = pTree->right;
			else if(pTree->right == NULL)	pTree = pTree->left;
			else{
				q = successor(pTree);
				pTree->val = q->val;
				delete(q->val, pTree->right);
			}
		}
	}	
}

int main(){
	BSNode *BStree=NULL;
	int d=0, s; int *depth; depth=&d;

	//Add Nodes
//int tab[]={78,55,98,59,34,22,95,5,9,456,6985,3,4658,12,99,100,150};
int tab[] = {50, 25, 75, 12, 27, 55, 90, 10, 14, 26, 40, 52, 57, 85, 95};
	for (int i=0;i<15;i++) BStree=add(BStree, tab[i]);
	

	treeTraverseA(BStree);
	printf("\n");
	treeTraverseD(BStree);
	printf("\n");

	printf("\nNumber of elements inside the tree: %d\n", treeNodeNumber(BStree, &d));
	printf("Search for a value into the tree:\n");
	printf("Give us the value :\t"); scanf("%d",&s);
	printf("------> Searching \n");
	if(BSearch(BStree, s)) printf("FOUND ..\n");
	else printf("This value %d DON'T exist in the tree.\n",s);

	treePrint(BStree, &d);

	return 0;
}
