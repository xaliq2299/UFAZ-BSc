/*************************************/
/*******  Huffman TREE  H  ***********/
/*************************************/
#ifndef __HT_H_
#define __HT_H_

#include<stdio.h>
#include<stdlib.h>
#include"LL.h"

//Huffman Tree Nodes Structure
typedef struct hNode {
  int val;
  char ch;
  struct hNode *left, *right;
} HuffNode;

//Linked List for huffman
typedef struct hlNode { 
  int sum; // when you do combination of some nodes
  HuffNode *hTree; // it is a pointer to your node it shows that where your node is in hoffman tree
  struct hlNode *pNext;
} HLNode;

int HL_Print(HLNode *pList);
int LLH_sorted_add(HLNode **ppList,int n, HuffNode *new);
HLNode *readList(LLNode *ll);
HuffNode *buildTree(HLNode *myList);
void printHTree(HuffNode *hTree);

//HuffNode *twoLeafs(LLNode *first, LLNode *second);
//HuffNode *mixHTree(HuffNode *old, LLNode *first, LLNode *second);
//HuffNode *twoNodes(HuffNode *old, LLNode *first, LLNode *second);
//void readList(LLNode *pList);


#endif
