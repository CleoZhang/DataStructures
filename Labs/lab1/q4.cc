#include <cstdlib> // for atoi
#include <iostream>

// prototype 
void moveDisks(int n, const char* FROM, const char* VIA, const char* TO);

int main(int argc, char *argv[]) {
//argc = # of commands typed in Terminal + 1
//argv[] = the commands typed in Terminal are stored in the form of array
  if (argc != 2) {
  	//at least 1 command (./programName) is typed in for executing the program.
    std::cout << "Usage: " << argv[0] << " number_of_disks" << std::endl;
    return -1;
  }
  //the second command typed in Terminal should be an integar indicating the # of disks
  int n = atoi(argv[1]);
  moveDisks(n, "peg A", "peg B", "peg C");
  return 0;
}

// put your moveDisks() function here 
void moveDisks(int n, const char* FROM, const char* VIA, const char* TO){
	if( n != 0 ){
		moveDisks(n-1, FROM, TO, VIA);
		//std::cout <<  FROM << "--" << VIA << "--" << TO << std::endl;
		std::cout << "Move disk from " << FROM << " to " << TO << std::endl;
		//std::cout << "Move disk from " << VIA << " to " << TO << std::endl;
		moveDisks(n-1,VIA,FROM,TO);
		//std::cout <<  FROM << "--" << VIA << "--" << TO << std::endl;
		//std::cout <<  "===========================" << std::endl;
	}
}
