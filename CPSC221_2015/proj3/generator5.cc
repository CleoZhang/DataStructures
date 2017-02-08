#include <iostream>
#include <cstdlib> // for atoi
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char* argv[])
{
    srand (time(NULL));

    if (argc != 2) // remember, argv[0] is the program name
    {
        cerr << "Wrong number of arguments!" << endl;
        return 1; 
    }
  
    int n = atoi(argv[1]);
    for(int i = 1; i <= n/2; i++){
        int ranNum1 = rand()% (n/2) + 1;
        cout << "I " << ranNum1 << endl;
     } 

    for(int j = 1; j <= n/2; j++){
        cout << "F " << j << endl;
     } 

    return 0;
}