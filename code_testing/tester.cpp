#include <iostream>
#include<vector>


int main () {
	std::vector<int> first;
	std::vector<int> second (4, 100);
	//int ia = a - '0';
	std::cout << second[1] << std::endl;
	first = second;
	first[1] = 3;
	std::cout << first[1] << std::endl;
	std::cout << "The contents of second are:";
  	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	int tempint = kmer[j] - '0';
	return 0;
}
