#include <iostream>
#include <fstream>
#include <sstream>
#include <string>       // provides string class
#include <cctype>       // provides isalpha() and tolower()
#include <vector>
#include <algorithm>
#include <iterator>


using namespace std;

// The following function should be moved into your skiplist.cc file when you
// write that.  It implements the random bit generation.
#include <ctime>                // for time()
#include <cstdlib>              // for rand(), srand(), and RAND_MAX

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

void print(ostream & output, string & word) {
  output << word << endl;
}

//my add-ons start from here

std::string to_string(int &i)
{
    std::stringstream s;
    s << i;
    return s.str();
}
//there is some problem about this method, cannot update the values
void updateData (int & lineNum, string & word, vector<string> & listW, vector<int> & listO, vector< vector<int> > & listP){
  //since we already have the wordlist done, we dont have to check if the word exist here, just update the ocurrences and page numbers
  for(int i = 0; i < listW.size(); i++){
    if(word == listW[i]){
      //update occurences
      listO[i] = listO[i]+1 ;
      //update the page numbers, 40 lines = 1 page
      int pageNum = lineNum/40+1;
      //string s = to_string(pageNum);
      //defile a new vector to store pg# for each word
      listP[i].push_back(pageNum);
      listP[i].erase( unique( listP[i].begin(), listP[i].end() ), listP[i].end() );
    }
  }
}

vector<string> merge(vector<string> & listW, vector<int> & listO, vector< vector<int> > & listP, vector<string> & op){
  int i = 0;
  for (; i < listW.size(); i++){
    ostringstream oss;
    if(!listP[i].empty()){
      copy(listP[i].begin(), listP[i].end()-1, ostream_iterator<int>(oss, ","));
      oss << listP[i].back();
      op[i] = listW[i]+" ("+to_string(listO[i])+") "+oss.str();
    }
  }
  return op;
}

void displayResults(vector<string> & mergedVector){
  int i = 0;
  for (; i < mergedVector.size(); i++){
    cout <<  mergedVector.at(i) << std::endl;
  }
}


int main(int argc, char *argv[]) {
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

  string line, word;
  //declare wordList to store all words in an alphabetical order without duplicates
  int lineCounter = 0;
  vector<string> wordList;
  vector<int> lines;
  vector<string> words;
  //1. first read from the source file for the wordList
  while( !fin.eof() ) {
    getline(fin,line);
    lineCounter++;
    lowercaseWords(line);
    istringstream iss(line, istringstream::in);
    while( iss >> word ) {
      wordList.push_back(word);
      words.push_back(word);
      lines.push_back(lineCounter);
      //print(fout, word);
    }
  }
  sort(wordList.begin(),wordList.end());
  wordList.erase( unique( wordList.begin(), wordList.end() ), wordList.end() );

 //2. initialize the size of myOcurrs and myPage and the myOutputs
  vector<int> myOcurr;      //to record # of occrence for each word
  vector< vector<int> > myPages;   //to store the page#
  vector<string> myOutputs;

  myOcurr.resize(wordList.size());
  myPages.resize(wordList.size());
  myOutputs.resize(wordList.size());
  //3. second read from the source file to do comparison
 for (size_t i = 0; i < words.size(); i++){
    //3. update myOcurr and  myPages here
    updateData (lines[i], words[i], wordList, myOcurr, myPages);
  }
  //4.merge all three elements from three containers to one string as an element in myOutputs
  vector<string> outputs = merge(wordList, myOcurr, myPages, myOutputs);
  //5.display the result on terminal
  displayResults(outputs);
  //6.write each merged element in myOutputs to the output file
  for(int j = 0; j < outputs.size();j++){
     print(fout, outputs[j]);
  }
}