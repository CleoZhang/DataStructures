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
    for(int i = 1; i <= n/5; i++){
        int ranNum1 = rand()% n + 1;
        cout << "I " << ranNum1 << endl;
     } 

    for(int j = 1; j <= n/5; j++){
        cout << "F " << j << endl;
     } 

    for(int m = n/5; m > 0; m--){
        cout << "F " << m << endl;
     } 

    for(int k = 1; k <= n/5; k++){
        int ranNum2 = rand()% (n/5) + 1;
        cout << "F " << ranNum2 << endl;
     } 

    for(int q = n/5; q > 0; q--){
        int ranNum3 = rand()% (n/5) + 1;
        cout << "F " << ranNum3 << endl;
     } 

    return 0;
}