#include <vector>

#ifndef CODETREE_H
#define CODETREE_H

using namespace std;

class CodeTree{
public:
	struct CodeNode{
		int charInt;
		int frequency;
		CodeNode *left;
		CodeNode *right;
	};

	//pointer that points to the first node of tree
	CodeTree :: CodeNode *head;
	//input info
	vector<int> cd;
	vector<int> cf;
	//CodeTree constructor
	CodeTree( vector<int> &charsData, vector<int>& charsFreq, int size, vector<CodeTree::CodeNode> *heap);
	//print Tree&Code as required
	void printTree(CodeTree::CodeNode *header, int depth);
	void printCode();
	void printChar( int ch );
	//format the tree as required
	void treeManager(CodeTree:: CodeNode *tree);
};

#endif