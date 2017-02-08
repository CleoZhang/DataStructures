#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "priorityheap.h"

using namespace std;

//CodeTree constructor
CodeTree :: CodeTree(vector<int> &charData, vector<int> &charFreq, int size, vector<CodeTree :: CodeNode> *heap){
		int sum = 0;
		//construct 3 new CodeNodes to represent left, right and parent
		CodeTree :: CodeNode *left = new CodeTree :: CodeNode();
		CodeTree :: CodeNode *right = new CodeTree :: CodeNode();
		CodeTree :: CodeNode *parent = new CodeTree :: CodeNode();

		//create a CodeNode for each element
		int index = 0;
		for (; index < size; index ++){
			CodeTree :: CodeNode *newNode = new CodeTree :: CodeNode();
			newNode->charInt = charData.at(index);
			newNode->frequency = charFreq.at(index);
			newNode->left = NULL;
			newNode->right = NULL;
			//add the constructed node to heap
			heap->push_back(*newNode);
		}
		CodeTree::CodeNode *result = new CodeTree::CodeNode();
			// cout << "============Tested Heap============" << endl;
			// printHeapFreq(heap, heap->size(), 0, 0);
			// cout << "------------------------" << endl;
			// printHeapChar(heap,heap->size(), 0, 0);

			// //heapify testing
			// heapify(heap, heap->size());

			// cout << "============Heapify Test============" << endl;
			// //print out the heap
			// printHeapFreq(heap, heap->size(), 0, 0);
			// cout << "------------------------" << endl;
			// printHeapChar(heap,heap->size(), 0, 0);

			// cout << "============getMinNode Test============" << endl;
			// CodeTree :: CodeNode myNode = getMinNode(heap,heap->size());
			// //print out the heap
			// printHeapFreq(heap, heap->size(), 0, 0);
			// cout << "------------------------" << endl;
			// printHeapChar(heap,heap->size(), 0, 0);
			// //print node
			// cout << myNode.frequency << endl;

			// cout << "============Print out result=============" << endl;
			// vector<CodeTree::CodeNode> *parents = new vector<CodeTree :: CodeNode>();
			// vector<CodeTree::CodeNode> *result = new vector<CodeTree :: CodeNode>();
			// for (int i = 0; i < heap->size(); i++){
			//   result->push_back(heap->at(i));
			// }


		//compute parent node for huftree
		while(heap->size() != 1){
			//construct 3 node 
			CodeTree::CodeNode *leaf1 = new CodeTree::CodeNode();
			CodeTree::CodeNode *leaf2 = new CodeTree::CodeNode();
			CodeTree::CodeNode *parent = new CodeTree::CodeNode();
			//get node with smallest frequency in curr heap
			*leaf1 = getMinNode(heap, heap->size());
			*leaf2 = getMinNode(heap, heap->size());
			//compute sum
			sum = leaf1->frequency + leaf2->frequency;

			parent->charInt = -1;
			parent->frequency = sum;
			parent->left = leaf1;
			parent->right = leaf2;

			CodeTree :: CodeNode *myPointer = parent;
			insert(heap, parent);
			heapify(heap, heap->size());
			//parents->push_back(*myPointer);
			//result->push_back(*myPointer);
			result = parent;
		}
			// printHeapFreq(parents, parents->size(), 0, 0);
			// std::cout <<parents->size() << std::endl;
			// cout << "===========================" << endl;

			// for(int i = 0; i < result->size(); i++){
			// 	CodeTree :: CodeNode pointer = result->at(i);
			// 	parents->push_back(pointer);
			// }
			

			// //printHeapFreq(result, result->size(), 0, 0);
			// std::cout <<parents->size() << std::endl;
			// printHeapFreq(parents, parents->size(), 0, 0);
			// cout << "===========================" << endl;
			// heapify(parents, parents->size());	
			// printHeapFreq(parents, parents->size(), 0, 0);
			// cout << "------------------------" << endl;
			// printHeapChar(parents, parents->size(), 0, 0);
			// cout << "===========================" << endl;
			// swap(parents->at(3),parents->at(6));
			// swap(parents->at(8),parents->at(10));
			// printHeapFreq(parents, parents->size(), 0, 0);
			// cout << "------------------------" << endl;
			// printHeapChar(parents, parents->size(), 0, 0);

			// string s = " ";
			// cout << "===========================" << endl;
			// for (int i = 0; i < parents->size(); i++){
			// 	//CodeTree::CodeNode *pointer = heap->at(i);
			// 	treeManager(heap->at(i) , s);
			// }

		head = result;
}

// void printTree(CodeTree::CodeNode *header, int depth){
//   if( header== NULL ) return;
//   printTree( header->right, depth+1 );
//   std::cout << std::setw( 3 * depth ) << ""; // output 3 * d spaces
//   std::cout << header->charInt << std::endl;
//   printTree( header->left, depth+1 );
// }

// void treeManager(CodeTree:: CodeNode *tree, string s){
//     //string s = " ";
//     if(tree == NULL) return;
//     if(tree -> right == NULL){
//         printChar(tree->charInt);
//         std::cout <<std::endl;
//      }else{
//         std::cout << "."<< std::endl;
//         std::cout << s << "|`1-";
//         treeManager(tree->right, s+ "|   ");
//         std::cout << s + "|    " << std::endl;
//         std::cout << "`-0-";
//         treeManager(tree->left, s+ "     ");
//     }
// }

// // represented chars as integers
// void printChar( int ch ) {
//     if( ch < 16 ) {
//         std::cout << "x0" << std::hex << ch;
//     } else if( ch < 32 || ch > 126 ) {
//         std::cout << "x" << std::hex << ch;
//     } else {
//         std::cout << "\"" << (char)ch << "\"";
//     }
// }