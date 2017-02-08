#include <iostream>
#include <vector>
#include "codetree.h"

using namespace std;

#ifndef PRIORITYHEAP_H
#define PRIORITYHEAP_H

//void newNode(CodeTree :: CodeNode *myNode, CodeTree::TreeNode *left, CodeTree::TreeNode * right);

void swapDown(std::vector<CodeTree::CodeNode> *heap, int i, int size);
void heapify(std::vector<CodeTree::CodeNode> *heap, int size);
void printHeapFreq(std::vector<CodeTree::CodeNode> *heap, int size, int node, int d);
void printHeapChar(std::vector<CodeTree::CodeNode> *heap, int size, int node, int d);
CodeTree::CodeNode getMinNode(std::vector<CodeTree::CodeNode>* heap, int size);
void insert(std::vector<CodeTree::CodeNode> *heap, CodeTree::CodeNode *node);
// void bstAlike(vector<CodeTree :: CodeNode> *heap, int i, int size);
// void bstHeapify(vector<CodeTree :: CodeNode> *heap, int size);
void treeManager(CodeTree:: CodeNode *tree, string s);
void printChar( int ch );

#endif