// Towers of Hanoi -------------------------

#include <cstdlib> // for atoi
#include <iostream>
int myArray[10];

void fill_array();
void fill_array(int head, int incr);

int main(void) {
	fill_array();
	fill_array(0, 5);
	return 0;
}

//Q3.(a) the simple fill_array() function
void fill_array(){
	std:: cout << "The elements in myArray are: ";
	std:: cout << "\n";
	int i = 0;
	for(;i < 10;i++){
		myArray[i] = i+1;
		std:: cout << myArray[i];
		std:: cout << "\n";
	}
}

//Q3.(b) modified function fill_array()
void fill_array(int head, int incr){
	std:: cout << "The elements in myArray are: ";
	std:: cout << "\n";
	for(int i = 0; i < 10; i++){
		if (i == 0)
		{
			myArray[i] = head;
			std:: cout << myArray[i];
			std:: cout << "\n";
		}else{
			myArray[i] = myArray[i-1]+incr;
			std:: cout << myArray[i];
			std:: cout << "\n";
		}
	}
}




