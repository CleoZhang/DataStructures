#include <iostream>
#include <stdlib.h>

int main(void){
	// declare varibles
	int guess;
	int ranNum;
	int quit;

	// initialize random seed: 
	srand (time(NULL));

	// generate a random number
	ranNum= rand() % 100 + 1;
	std::cout << ranNum << std::endl;

	while ( guess != ranNum){
		std::cout << "Enter 0 to quit, 1 to continue..."<< std::endl;
		std::cin >> quit;
		if (quit == 1){
			// require a number from the user
			std::cout << "Enter the guess:"<< std::endl;
			std::cin >> guess;
			if (guess == ranNum){
				break;
			}else{
				std::cout << "You got a wrong number, please guess again " << std::endl;
			}
		}else{
			std::cout << "Game Over" << std::endl;
			return 0;
		}
	}
	std::cout << "Yeahhh you got it right! " << std::endl;
	return 1;
}