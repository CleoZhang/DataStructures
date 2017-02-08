#include <iostream>
#include <cstdlib> // for atoi
#include <stdlib.h>

using namespace std;

// 1. insert in increasing order
// 2. find in increasing order
// 3. find in reverse order
int main(int argc, char* argv[])
{
    if (argc != 2) // remember, argv[0] is the program name
    {
        cerr << "Wrong number of arguments!" << endl;
        return 1; 
    }
  
    int n = atoi(argv[1]);
    for(int i = 1; i <= n/3; i++){
        cout << "I " << i << endl;
     } 

    for(int x = 1; x<= n/3; x++){
        cout << "F " << x << endl;
    }

    for(int t = n/3; t>=0; t--){
        cout << "F " << t << endl;
    }
    return 0;
}