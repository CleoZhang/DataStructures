#include <iostream>
#include <cstdlib> // for atoi
    
using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 2) // remember, argv[0] is the program name
    {
        cerr << "Wrong number of arguments!" << endl;
        return 1; 
    }
    int n = atoi(argv[1]);
    for(int i = 1; i <= n/3; i++) {
        cout << "I " << i << endl;
    }

    for(int k = 1; k <= n/3; k++) {
        cout << "F " << k << endl;
    }

    for(int j = n/3; j > 0 ; j--) {
        cout << "R " << j << endl;
    }
    return 0;
}