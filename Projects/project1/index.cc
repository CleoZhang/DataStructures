#include <iostream>
#include <fstream>
#include <sstream>
#include <string>       // provides string class
#include <cctype>       // provides isalpha() and tolower()
#include <vector>
#include <algorithm>
#include <iterator>

#include<stdio.h>  
#include<stdlib.h> 

using namespace std;

// The following function should be moved into your skiplist.cc file when you
// write that.  It implements the random bit generation.
#include <ctime>                // for time()
#include <cstdlib>              // for rand(), srand(), and RAND_MAX
#define MAX_LEVEL 25

/*--------------------------Construct a Objects------------------------------*/
//declaration
typedef struct Word {
  string key;
  string pgNum;
  int occNum;
}Word;

typedef struct Node{
  Word* word;
  Node* next[MAX_LEVEL];
}Node;

typedef struct SkipList{
  int level;
  Node* header;
}SkipList;

Word* createWord(string key, string pgNum, int occNum){
  Word* wd = new Word;
  wd->key = key;
  wd->pgNum = pgNum;
  wd->occNum = occNum;
  return wd;
}

Node* createNode(int level, string word){
  Node* nd = new Node;
  Word* wd = createWord(NULL,NULL,0);
  nd->word = wd;
  nd->word->key = word;
  return nd;
}

SkipList* createSkipList(){
  SkipList* sl = new SkipList; 
  sl->level = 0;
  sl->header = createNode(MAX_LEVEL-1, "");
  for (int i = 0; i < MAX_LEVEL; i++){
    sl->header->next[i]=NULL;
  }
  return sl;
}

/*------------------------------Default functions----------------------------------*/
int randBit(void) {             // return a "random" bit
  static int bitsUpperBd=0;
  static int bits;              // store bits returned by rand()
  if( bitsUpperBd == 0 ) {      // refresh store when empty
    bitsUpperBd = RAND_MAX;
    bits = rand();
  }
  int b = bits & 1;
  bits >>= 1;
  bitsUpperBd >>= 1;
  return b;
}


// Remove all characters except letters (A-Z,a-z) from line,
// except keep '-' or '\'' if they are between letters.
void lowercaseWords(string & line) {
  for( string::iterator it = line.begin(); it != line.end(); ++it ) {
    if( !isalpha(*it) ) {
      if( (*it != '-' && *it != '\'') ||
          it == line.begin() || it+1 == line.end() ||
          !isalpha(*(it-1)) || !isalpha(*(it+1)) ) {
        *it = ' ';
      }
    } else {
      *it = tolower(*it);
    }
  }
}

// void print(ostream & output, string & word) {
//   output << word << endl;
// }

/*--------------------------------Add-on Functions---------------------------------*/

string to_string(int &i)
{
    std::stringstream s;
    s << i;
    return s.str();
}

int pgSolver (int & lineNum){
    int pg = lineNum/40 + 1;
    return pg;
}

//find function
Node* find(SkipList* words, string word){
  Node *p,*q;
  p = words->header;
  //search from the top
  int l = words->level;
  for(int i = l-1; i >= 0; i--){
    //int counter = 0;
    while((q = p->next[i])&&(q->word->key <= word)){
      if (q->word->key == word){
        return q;
      }
      p = q;
    }
  }
  return NULL;
}

//insert function
Node* insertSL (SkipList* sl, string obj){
  Node *update[MAX_LEVEL];
  Node *tmp1, *tmp2;
  int l = 0;

  tmp1 = sl->header;
  l = sl->level;

  //search the position from top
  for (int i = l-1; i >= 0; i--){
    while((tmp2 = tmp1->next[i])&&((tmp2->word->key) < obj)){
      tmp1 = tmp2;
    }
    update[i] = tmp1;
  }

  //construct a new node array size
  l = randBit();
  //renew the level if its neccesary
  if (l > (sl->level)){
    for (int i = sl->level; i < l; i++){
        update[i] = sl->header;
    }
    sl->level = l;
  }

  tmp2 = createNode(l, obj);
  //insert node to each linked list
  for (int h = 0; h < l; ++h){
    tmp2->next[h] = update[h]->next[h];
    update[h]->next[h] = tmp2;
  }
  return tmp2;
}

// //store the pg number in the vector within the pageList vector
// string pageManager(int & curPage, int & index, vector< vector<int> > & pageList){
//   string l;
//   //add vals
//   pageList[index].push_back(curPage);
//   //remove duplicates
//   pageList[index].erase( unique( pageList[index].begin(), pageList[index].end() ), pageList[index].end() );
//   //convert vector to string format
//   ostringstream oss;
//   if(!pageList[index].empty()){
//     copy(pageList[index].begin(), pageList[index].end()-1, ostream_iterator<int>(oss, ","));
//     oss << pageList[index].back();
//     l = oss.str();
//   }
//   return l;
// }


// int storeKeys(vector<string> & keysList,string & word){
//     keysList.push_back(word);
//     sort(keysList.begin(),keysList.end());
//     for (int i = 0; i < keysList.size(); i++){
//       if (keysList[i] == word){
//         return i;
//       }
//     }
//     return -1;
// }

// void printList (vector<Word> list){
//   int index = 0;
//   for (; index < list.size(); index++){
//     cout << list[index].key <<"   ("<< list[index].occNum <<")   "<< list[index].pgNum << std:: endl;
//   }
// }

// //print skp list
// void printSL(SkipList &sl){
//   Node *p,*q;
//   int l = sl.level;
//   for(int i = l-1; i >= 0; i--){
//     p = sl.header;
//     while(q = p->next[i]){
//       cout<< p->word << endl;
//       p=q;
//     }
//     cout<< "\n"<< endl;
//   }
//   cout<< "\n" << endl;
// }

/*----------------------------------Main Function----------------------------------*/
int main(int argc, char *argv[]) {
  srand(time(0));
  if( argc != 3 ) {
    cerr << "Usage: " << argv[0] << " book.txt index.txt" << endl;
    exit(1);
  }

  ifstream fin;
  fin.open(argv[1]);
  if( !fin.is_open() ) {
    cerr << "Unable to open " << argv[1] << endl;
    exit(2);
  }

  ofstream fout;
  fout.open(argv[2]);
  if( !fout.is_open() ) {
    cerr << "Unable to open " << argv[2] << endl;
    exit(3);
  }

  //declare the word list here
  SkipList* wordList = createSkipList();
  //declare the line# container
  //vector<int> lines;
  //decalre a line counter
  int lineCounter = 0;
  //declare the pg number container
  //vector< vector<int> > myPages;
  //vector<int> myOcc;
  //int count = 0;
  // Node* next = wordList->header;
  // while (next != NULL){
  //   next = next->next[0];
  //   count++; 
  // }

  // myOcc.assign(count, 0);
  string line, word;
  while( !fin.eof() ) {
    getline(fin,line);
    lineCounter++;
    lowercaseWords(line);
    istringstream iss(line, istringstream::in);
    while( iss >> word ) {
//add-ons calls from here
      //calculate the page number for each incoming word
      int page = pgSolver(lineCounter);

      if (find(wordList, word) != NULL){
        Node* obj = find(wordList, word);
        obj->word->occNum++;
        obj->word->pgNum = obj->word->pgNum + "," + to_string(page);
      }else{
        //store the word in wordList
        Node* tmp = insertSL(wordList,word);
        tmp->word->pgNum = to_string(page);
        tmp->word->occNum = 1; 
      }
    }
  }
  // //write to the output file
  // for(int j = 0; j < outputs.size();j++){
  //    print(fout, outputs[j]);
  // }
}

