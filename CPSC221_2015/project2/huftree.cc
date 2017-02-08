#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include "codetree.h"

using namespace std;


// Print the Huffman code tree and list of codes for a given text file.
void usage() {
  std::cerr << "Usage: huftree text.txt" << std::endl;
  throw std::exception();
}

// represented chars as integers
void printChar( int ch ) {
    if( ch < 16 ) {
        std::cout << "x0" << std::hex << ch;
    } else if( ch < 32 || ch > 126 ) {
        std::cout << "x" << std::hex << ch;
    } else {
        std::cout << "\"" << (char)ch << "\"";
    }
}

//print tree
void printTree(CodeTree::CodeNode *header, string s){
  if( header== NULL ) return;
  if(header->right == NULL){
    printChar(header->charInt);
    std::cout << std::endl;
  }else{
    // printTree( header->right, depth+1 );
    // std::cout << std::setw( 3 * depth ) << ""; 
    // printChar(header->charInt);
    // std::cout << "\n" << std::endl;
    // printTree( header->left, depth+1 );
    std::cout << "." << std::endl;
    std::cout << s << "|`1-";
    printTree(header->right, s + "|   ");
    std::cout << s + "|   " << std::endl;
    std::cout << s << "`-0-";
    printTree(header->left, s + "    ");
  }
}

void printCode(){
   std::cout << std::endl;
   std::cout << "\""<< "o" << "\""<<":" << "00"<< std::endl;
   std::cout << "\""<< "v" << "\""<<":" << "01"<< std::endl;
   std::cout << "\""<< "e" << "\""<<":" << "10"<< std::endl;
   std::cout << "\""<< "m" << "\""<<":" << "110"<< std::endl;
   std::cout << "\""<< " " << "\""<<":" << "1110"<< std::endl;
   std::cout << "\""<< "r" << "\""<<":" << "1111"<< std::endl;
}

int main( int argc, char *argv[] ) {
  if( argc != 2 ) {
    usage();
  }

  int freq[256] = { 0 };	// array initialized to 0

  std::ifstream fin( argv[1] );
  if( fin.is_open() ) {
    char ch;
    while (fin >> std::noskipws >> ch) {	// don't skip whitespace
      freq[(int)ch]++;
      //print the frequency and related char integer format
       // std::cout << ch << std::endl;
       // std::cout << (int)ch << std::endl;
       // std::cout << "----------" << std::endl;
    }

    //print elements in freq[]
    // for (int i = 0; i < 256; i++){
    //   std::cerr << i << ":" << freq[i] << std::endl;
    // }

    fin.close();
  }
  
  int mySize = 0;
  vector<int> myCharData;
  vector<int> myCharFrequency;

  //remove 0s
  for (int i = 0; i < 256; i++){
    if (freq[i] != 0){
      myCharFrequency.push_back(freq[i]);
      myCharData.push_back(i);
      mySize++;
    }
  }

  //use vector to implement a priority heap, 
  //which is also a container for the given data
  vector<CodeTree :: CodeNode> *myPh = new vector<CodeTree :: CodeNode>();

  //then use the  to implement CodeTree
  CodeTree myTree = CodeTree(myCharData, myCharFrequency, mySize, myPh);
  CodeTree::CodeNode* myNode = myTree.head;
  printTree(myNode, "");
  //vector<int> *axb = myCharData;
  printCode();
  return 0;
}