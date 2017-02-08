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
    for(int i = 1; i <= n/4; i++){
        int ranNum1 = rand()% n + 1;
        cout << "I " << ranNum1 << endl;
     } 

    for(int j = 1; j <= n/4; j++){
        cout << "R " << j << endl;
     } 

    for(int m = n/4; m > 0; m--){
        cout << "R " << m << endl;
     } 

    for(int k = 1; k <= n/4; k++){
        int ranNum2 = rand()% (n/4) + 1;
        cout << "R " << ranNum2 << endl;
     } 

    return 0;
}