#include <iostream>
#include <ctime>
#include <cstdlib>

int * x;
//add global variable comps here
int comps = 0;

void swap(int & a, int & b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int randint(int a, int b) {
	return a + (rand() % (b - a + 1));
}

//do the comparison and sort the array out
void quicksort(int a, int b) {

	if (a >= b) return;
	int p = randint(a,b); // pivot
	swap(x[a], x[p]);
	int m = a;
	int i;
	// in-place partition:
	for (i = a+1; i <= b; i++) {
		//add comps to record comparason number
		comps++;
		if (x[i] < x[a])
			swap(x[++m], x[i]);
	}
	swap(x[a],x[m]);
	quicksort(a, m-1);
	quicksort(m+1, b);

}

//record the# of comparison without sorting
int qc(int n){
	if (n <= 1)
		return 0;

	int counter = n-1;

	//git a random pivot location
	//(0)-------(ran)-------(n)
	int ran = randint(0,n);
	//record the # of comparison for the left part (0-ran)
	counter += qc(ran-1);
	counter += qc(n-ran);
	return counter;
}

//the given code
float c(int n) {
       if (n <= 1) return 0;
       float sum = 0.0;
       for (int m=1; m <= n; m++)
         sum += n-1 + c(m-1) + c(n-m);
       return sum / n;
}

#define NN 3000
#define ITERATION 100

int main(int argc, char *argv[]) {
	srand(time(0));

	// change the following code
	int it = ITERATION;
	int totalComps = 0;

	while(it > 0){	
		x = new int[NN];

		for (int i=0; i<NN; ++i) {
			x[i] = rand() % NN;
		}
		
		quicksort(0, NN-1);
		// for (int i=0; i<NN; ++i) {
		// 	std::cout << x[i] << " ";
		// }
		// std::cout << std::endl;

		totalComps += comps;
		comps = 0;
		it--;
		delete[] x;
	}

	int avg = totalComps/ITERATION;
	std::cout << totalComps << std:: endl;
	std::cout << avg << std:: endl;
	std::cout << "-----call qc-----" << std:: endl;
	std::cout << qc(NN) << std:: endl;
	std::cout << "-----call c-----" << std:: endl;
	std::cout << c(5) << std:: endl;
	std::cout << c(10) << std:: endl;
	std::cout << c(15) << std:: endl;

	return 0;
}