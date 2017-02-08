//modified few lines to reorder the heap
//most of it is directly quoted from my lab4

#include <iostream>
#include <vector>
#include <algorithm>
#include "codetree.h"
#include "priorityheap.h"

using namespace std;

//reorder the heap elements
void swapDown(vector<CodeTree :: CodeNode> *heap, int i, int size) {
    int rightChild = 2 * i + 2;
    int leftChild = 2 * i + 1;
    int max = i;

    // find who holds largest element of i and its two children
    if (rightChild < size && heap->at(rightChild).frequency >= heap->at(max).frequency)
    	max = rightChild;
    else if (leftChild < size && heap->at(leftChild).frequency > heap->at(max).frequency)
        max = leftChild;

    // if a child holds largest element, swap i's element to that child
    // and recurse.
    if (max != i) {
        swap(heap->at(i), heap->at(max));
        swapDown(heap, max, size);
    }
}

//put each element in order in a heap
void heapify(vector<CodeTree :: CodeNode> *heap, int size) {
    for (int i = (size - 2) / 2; i >= 0; i--)
        swapDown(heap, i, size);
}

// void bstAlike(vector<CodeTree :: CodeNode> *heap, int i, int size){
//     int rightChild = 2 * i + 2;
//     int leftChild = 2 * i + 1;
//     //int temp = i;

//     if(rightChild < size && leftChild < size){
//         if(heap->at(i)->frequency == heap->at(rightChild)->frequency + heap->at(leftChild)->frequency){
//             if(heap->at(rightChild).frequency < heap->at(leftChild).frequency )
//                 swap(heap->at(rightChild),heap->at(leftChild));
//         }else{
//             CodeTree::CodeNode myNode = find
//         }
//     }
// }

// void bstHeapify(vector<CodeTree :: CodeNode> *heap, int size) {
//     for (int i = (size - 2) / 2; i >= 0; i--)
//         bstAlike(heap, i, size);
// }

void printHeapFreq(vector<CodeTree :: CodeNode> *heap, int size, int index, int d) {
    //formula that will be used in this method
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index+ 2;
    if(rightChild < size)
        printHeapFreq(heap, size, rightChild, d+1);

    if(index < size){
        for(int i = 0; i < d; i++){
            cout << "   ";
        }
        cout << heap->at(index).frequency << endl;
    }

    if(leftChild < size)
        printHeapFreq(heap, size, leftChild, d+1);   
}

void printHeapChar(vector<CodeTree :: CodeNode> *heap, int size, int index, int d) {
    //formula that will be used in this method
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index+ 2;
    if(rightChild < size)
        printHeapChar(heap, size, rightChild, d+1);

    if(index < size){
        for(int i = 0; i < d; i++){
            cout << "   ";
        }
        cout << (char)heap->at(index).charInt << endl;
    }

    if(leftChild < size)
        printHeapChar(heap, size, leftChild, d+1);   
}

//return the min node for current heap
//remove the min node
CodeTree::CodeNode getMinNode(vector<CodeTree :: CodeNode> *heap, int size) {
   int min = 0;
   CodeTree :: CodeNode temp = heap->at(0);

   for( int i = 0; i < size; i++){
     if(heap->at(i).frequency < heap->at(min).frequency){
     		min = i;
        	temp = heap->at(min);
     }
   }

   heap->at(min) = heap->at(size-1);
   heap->pop_back();

   heapify(heap, --size);

   return temp;
}

//insert a new node
void insert(vector<CodeTree::CodeNode> *heap, CodeTree::CodeNode *node){
    heap->push_back(*node);
    heapify(heap, heap->size());
}

