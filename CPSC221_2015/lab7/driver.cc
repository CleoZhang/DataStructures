#include "Hashtable.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;


void usage(char* argv[]) {
	cerr << "Usage: " << argv[0] << " scheme numberOfKeys sizeOfTable" << endl;
	exit(-1);
}

int main(int argc, char *argv[]) {
	int n, m;
	srand(time(0));

	if (argc == 1) {
		cout << "Running your test code..." << endl;

	     cout << "\n";
	     cout << "===========Test#0============== ";
	     cout << "\n";
	     Hashtable H00(1000003);
	     for (int i = 0; i < 950000; i++) {
	         H00.qinsert(rand() + 1);
	     }
	     cout << "Quadratic with 950000 keys and size 1000003: ";
	     H00.printStats();
	     cout << "--------------------------------";
	     cout << "\n";
	     Hashtable H01(1000003);
	     for (int i = 0; i < 950000; i++) {
	         H01.linsert(rand() + 1);
	     }
	     cout << "Linear with 950000 keys and size 1000003: ";
	     H01.printStats();
	     cout << "--------------------------------";
	     cout << "\n";
	     Hashtable H02(1000003);
	     for (int i = 0; i < 950000; i++) {
	         H02.dinsert(rand() + 1);
	     }
	     cout << "Double with 950000 keys and size 1000003: ";
	     H02.printStats();
	     cout << "--------------------------------";
	     cout << "\n";
	     Hashtable H03(1000003);
	     for (int i = 0; i < 950000; i++) {
	         H03.tinsert(rand() + 1);
	     }
	     cout << "Triple with 950000 keys and size 1000003: ";
	     H03.printStats();

	     cout << "\n";

	     /* ADD YOUR TEST CODE HERE */
	     cout << "\n";
	     cout << "===========Test#1============== ";
	     cout << "\n";
	     Hashtable H10(1000003);
	     for (int i = 0; i < 900000; i++) {
	         H10.qinsert(rand() + 1);
	     }
	     cout << "Quadratic with 900000 keys and size 1000003: ";
	     H10.printStats();
	     cout << "--------------------------------";
	     cout << "\n";
	     Hashtable H11(1000003);
	     for (int i = 0; i < 900000; i++) {
	         H11.linsert(rand() + 1);
	     }
	     cout << "Linear with 900000 keys and size 1000003: ";
	     H11.printStats();
	     cout << "--------------------------------";
	     cout << "\n";
	     Hashtable H12(1000003);
	     for (int i = 0; i < 900000; i++) {
	         H12.dinsert(rand() + 1);
	     }
	     cout << "Double with 900000 keys and size 1000003: ";
	     H12.printStats();
	     cout << "--------------------------------";
	     cout << "\n";
	     Hashtable H13(1000003);
	     for (int i = 0; i < 900000; i++) {
	         H13.tinsert(rand() + 1);
	     }
	     cout << "Triple with 900000 keys and size 1000003: ";
	     H13.printStats();

	     cout << "\n";
	     cout << "===========Test#2============== ";
	     cout << "\n";
	     Hashtable H20(1000003);
	     for (int i = 0; i < 800000; i++) {
	         H20.qinsert(rand() + 1);
	     }
	     cout << "Quadratic with 800000 keys and size 1000003: ";
	     H20.printStats();
	     cout << "--------------------------------";
	     cout << "\n";
	     Hashtable H21(1000003);
	     for (int i = 0; i < 800000; i++) {
	         H21.linsert(rand() + 1);
	     }
	     cout << "Linear with 800000 keys and size 1000003: ";
	     H21.printStats();
	     cout << "--------------------------------";
	     cout << "\n";
	     Hashtable H22(1000003);
	     for (int i = 0; i < 800000; i++) {
	         H22.dinsert(rand() + 1);
	     }
	     cout << "Double with 800000 keys and size 1000003: ";
	     H22.printStats();
	     cout << "--------------------------------";
	     cout << "\n";
	     Hashtable H23(1000003);
	     for (int i = 0; i < 800000; i++) {
	         H23.tinsert(rand() + 1);
	     }
	     cout << "Triple with 800000 keys and size 1000003: ";
	     H23.printStats();
	     cout << "\n";
	     cout << "===========Test#3============== ";
	     cout << "\n";
	     Hashtable H30(1000003);
	     for (int i = 0; i < 700000; i++) {
	         H30.qinsert(rand() + 1);
	     }
	     cout << "Quadratic with 700000 keys and size 1000003: ";
	     H30.printStats();
	     cout << "--------------------------------";
	     cout << "\n";
	     Hashtable H31(1000003);
	     for (int i = 0; i < 700000; i++) {
	         H31.linsert(rand() + 1);
	     }
	     cout << "Linear with 700000 keys and size 1000003: ";
	     H31.printStats();
	     cout << "--------------------------------";
	     cout << "\n";
	     Hashtable H32(1000003);
	     for (int i = 0; i < 700000; i++) {
	         H32.dinsert(rand() + 1);
	     }
	     cout << "Double with 700000 keys and size 1000003: ";
	     H32.printStats();
	     cout << "--------------------------------";
	     cout << "\n";
	     Hashtable H33(1000003);
	     for (int i = 0; i < 700000; i++) {
	         H33.tinsert(rand() + 1);
	     }
	     cout << "Triple with 700000 keys and size 1000003: ";
	     H33.printStats();
	     cout << "\n";
	     cout << "===========Test#4============== ";
	     cout << "\n";
	     Hashtable H40(1000003);
	     for (int i = 0; i < 600000; i++) {
	         H40.qinsert(rand() + 1);
	     }
	     cout << "Quadratic with 600000 keys and size 1000003: ";
	     H40.printStats();
	     cout << "--------------------------------";
	     cout << "\n";
	     Hashtable H41(1000003);
	     for (int i = 0; i < 600000; i++) {
	         H41.linsert(rand() + 1);
	     }
	     cout << "Linear with 600000 keys and size 1000003: ";
	     H41.printStats();
	     cout << "--------------------------------";
	     cout << "\n";
	     Hashtable H42(1000003);
	     for (int i = 0; i < 600000; i++) {
	         H42.dinsert(rand() + 1);
	     }
	     cout << "Double with 600000 keys and size 1000003: ";
	     H42.printStats();
	     cout << "--------------------------------";
	     cout << "\n";
	     Hashtable H43(1000003);
	     for (int i = 0; i < 600000; i++) {
	         H43.tinsert(rand() + 1);
	     }
	     cout << "Triple with 600000 keys and size 1000003: ";
	     H43.printStats();
	     cout << "\n";
	     cout << "===========Test#5============== ";
	     cout << "\n";
	     Hashtable H50(1000003);
	     for (int i = 0; i < 500000; i++) {
	         H50.qinsert(rand() + 1);
	     }
	     cout << "Quadratic with 500000 keys and size 1000003: ";
	     H50.printStats();
	     cout << "--------------------------------";
	     cout << "\n";
	     Hashtable H51(1000003);
	     for (int i = 0; i < 500000; i++) {
	         H51.linsert(rand() + 1);
	     }
	     cout << "Linear with 500000 keys and size 1000003: ";
	     H51.printStats();
	     cout << "--------------------------------";
	     cout << "\n";
	     Hashtable H52(1000003);
	     for (int i = 0; i < 500000; i++) {
	         H52.dinsert(rand() + 1);
	     }
	     cout << "Double with 500000 keys and size 1000003: ";
	     H52.printStats();
	     cout << "--------------------------------";
	     cout << "\n";
	     Hashtable H53(1000003);
	     for (int i = 0; i < 500000; i++) {
	         H53.tinsert(rand() + 1);
	     }
	     cout << "Triple with 500000 keys and size 1000003: ";
	     H53.printStats();
		 cout << "\n";	     
	     cout << "===========Test#6============== ";
	     cout << "\n";
	     Hashtable H60(1000003);
	     for (int i = 0; i < 400000; i++) {
	         H60.qinsert(rand() + 1);
	     }
	     cout << "Quadratic with 400000 keys and size 1000003: ";
	     H60.printStats();
	     cout << "--------------------------------";
	     cout << "\n";
	     Hashtable H61(1000003);
	     for (int i = 0; i < 400000; i++) {
	         H61.linsert(rand() + 1);
	     }
	     cout << "Linear with 400000 keys and size 1000003: ";
	     H61.printStats();
	     cout << "--------------------------------";
	     cout << "\n";
	     Hashtable H62(1000003);
	     for (int i = 0; i < 400000; i++) {
	         H62.dinsert(rand() + 1);
	     }
	     cout << "Double with 400000 keys and size 1000003: ";
	     H62.printStats();
	     cout << "--------------------------------";
	     cout << "\n";
	     Hashtable H63(1000003);
	     for (int i = 0; i < 400000; i++) {
	         H63.tinsert(rand() + 1);
	     }
	     cout << "Triple with 400000 keys and size 1000003: ";
	     H63.printStats();
	     cout << "\n";
	     cout << "===========Test#7============== ";
	     cout << "\n";
	     Hashtable H70(1000003);
	     for (int i = 0; i < 300000; i++) {
	         H70.qinsert(rand() + 1);
	     }
	     cout << "Quadratic with 300000 keys and size 1000003: ";
	     H70.printStats();
	     cout << "--------------------------------";
	     cout << "\n";
	     Hashtable H71(1000003);
	     for (int i = 0; i < 300000; i++) {
	         H71.linsert(rand() + 1);
	     }
	     cout << "Linear with 300000 keys and size 1000003: ";
	     H71.printStats();
	     cout << "--------------------------------";
	     cout << "\n";
	     Hashtable H72(1000003);
	     for (int i = 0; i < 300000; i++) {
	         H72.dinsert(rand() + 1);
	     }
	     cout << "Double with 300000 keys and size 1000003: ";
	     H72.printStats();
	     cout << "--------------------------------";
	     cout << "\n";
	     Hashtable H73(1000003);
	     for (int i = 0; i < 300000; i++) {
	         H73.tinsert(rand() + 1);
	     }
	     cout << "Triple with 300000 keys and size 1000003: ";
	     H73.printStats();
	     cout << "\n";
	     cout << "===========Test#8============== ";
	     cout << "\n";
	     Hashtable H80(1000003);
	     for (int i = 0; i < 200000; i++) {
	         H80.qinsert(rand() + 1);
	     }
	     cout << "Quadratic with 200000 keys and size 1000003: ";
	     H80.printStats();
	     cout << "--------------------------------";
	     cout << "\n";
	     Hashtable H81(1000003);
	     for (int i = 0; i < 200000; i++) {
	         H81.linsert(rand() + 1);
	     }
	     cout << "Linear with 200000 keys and size 1000003: ";
	     H81.printStats();
	     cout << "--------------------------------";
	     cout << "\n";
	     Hashtable H82(1000003);
	     for (int i = 0; i < 200000; i++) {
	         H82.dinsert(rand() + 1);
	     }
	     cout << "Double with 200000 keys and size 1000003: ";
	     H82.printStats();
	     cout << "--------------------------------";
	     cout << "\n";
	     Hashtable H83(1000003);
	     for (int i = 0; i < 200000; i++) {
	         H83.tinsert(rand() + 1);
	     }
	     cout << "Triple with 200000 keys and size 1000003: ";
	     H83.printStats();
	     cout << "\n";
	     cout << "===========Test#9============== ";
	     cout << "\n";
	     Hashtable H90(1000003);
	     for (int i = 0; i < 100000; i++) {
	         H90.qinsert(rand() + 1);
	     }
	     cout << "Quadratic with 100000 keys and size 1000003: ";
	     H90.printStats();
	     cout << "--------------------------------";
	     cout << "\n";
	     Hashtable H91(1000003);
	     for (int i = 0; i < 100000; i++) {
	         H91.linsert(rand() + 1);
	     }
	     cout << "Linear with 100000 keys and size 1000003: ";
	     H91.printStats();
	     cout << "--------------------------------";
	     cout << "\n";
	     Hashtable H92(1000003);
	     for (int i = 0; i < 100000; i++) {
	         H92.dinsert(rand() + 1);
	     }
	     cout << "Double with 100000 keys and size 1000003: ";
	     H92.printStats();
	     cout << "--------------------------------";
	     cout << "\n";
	     Hashtable H93(1000003);
	     for (int i = 0; i < 100000; i++) {
	         H93.tinsert(rand() + 1);
	     }
	     cout << "Triple with 100000 keys and size 1000003: ";
	     H93.printStats();

		return 0;
	}
	
	if (argc != 4) {
		usage(argv);
	}
	n = atoi(argv[2]);
	m = atoi(argv[3]);
	Hashtable H(m);
	
	switch(argv[1][0]) {
	case 'l':
		for (int i=0; i<n; ++i) {
			H.linsert(rand() + 1);
		}
		//    H.print();
		cout << "Linear: ";  
		H.printStats();
		break;
	case 'q':
		for (int i=0; i<n; ++i) {
			H.qinsert(rand() + 1);
		}
		//    H.print();
		cout << "Quadratic: ";
		H.printStats();
		break;
	case 'd':
		for (int i=0; i<n; ++i) {
			H.dinsert(rand() + 1);
		}
		//    H.print();
		cout << "Double Hashing: "; 
		H.printStats();
		break;
	default:
		usage(argv);
	}
}

