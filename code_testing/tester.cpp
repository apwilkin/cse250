#include <iostream>
#include <vector>
#include <math.h>
#include <sstream>

int main () {

	int one = 4^2;
	int two = pow (4, 2);
	std::cout << one << std::endl;
	std::cout << two << std::endl;
	
	int Number = 123234;
	std::string result;
	std::ostringstream convert;
	convert << Number;
	result = convert.str();
	result += "sdaf";
	std::cout << "result: " << result << std::endl;
	int grandtotal = 0;
	for (int i = 0; i < 10; i++) {
		int tempint = pow (4, i);
		grandtotal += tempint;  
	}
	std::cout << "grand total: " << grandtotal << std::endl;
	
	for (int i = 10 - 1; i > -1; i--) {
		std::cout << "i: " << i << std::endl;
	}
	int what = 3;
	int powint = pow
	std::cout << pow(what, 3);
	
	
//3 5
//ACTGTCATGTTG
//CACCAGACT
//GCTAGCTACCAGTG
//TCGTATGCTGACACCTG
//AGCTATT

	

//	std::vector<int> first;
//	std::vector<int> second (4, 100);
//	int ia = a - '0';
//	std::cout << second[1] << std::endl;
//	first = second;
//	first[1] = 3;
//	std::cout << first[1] << std::endl;
//	std::cout << "The contents of second are:";
//  	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//	int tempint = kmer[j] - '0';
	return 0;
}
