#include <iostream>

int main () {
  int x = 5, y = 15;
  int * p1, *p2;
		// value of	x	y	p1	p2
		//		5	15	uninit	uninit
  p1 = &x;
                //p1 = x's address
  p2 = &y;
                //p2 = y's address
  std::cout << x << "  "<< y << "  "<< p1 <<"  "<< p2 << std:: endl;

  *p1 = 6;
                //modify x from 5 to 6
  std::cout << x << "  "<< y << "  "<< p1 <<"  "<< p2 << std:: endl;

  *p1 = *p2;
                //modify x from 5 to 15 (which is y's value)
  std::cout << x << "  "<< y << "  "<< p1 <<"  "<< p2 << std:: endl;

  p2 = p1;
                //p2 now is holding x's address, so *p2 is pointing to x too
  std::cout << x << "  "<< y << "  "<< p1 <<"  "<< p2 << std:: endl;

  *p1 = *p2+10;
                //x = x + 10; so now x = 15 + 10;
  std::cout << x << "  "<< y << "  "<< p1 <<"  "<< p2 << std:: endl;

  return 0;
}
