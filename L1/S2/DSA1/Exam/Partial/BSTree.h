#include "queue.h"
#ifndef TREE
#define TREE
typedef struct Node{   
int val;
struct Node *left, *right;
}BSNode;

BSNode *constructTree(int n);
BSNode *add(BSNode *pTree, int n);
void printNode(BSNode *pTree){printf("%d \t", pTree->val);}
void treeTraverseA(BSNode *pTree);
void treeTraverseD(BSNode *pTree);
int treeNodeNumber(BSNode *pTree, int *d);
int treeDepth(BSNode *pTree);
void treePrintLevels(BSNode *root, int *d);
int BSearch(BSNode *pTree, int n);
void treePrintLevel(BSNode *pTree, int level, SFifo *queue);

#endif
