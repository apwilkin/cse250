#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>


//add each int without sorting
//do merge sort
//iterate through vector


int main (int argc, char* argv[]) {
	std::cout << "filename: " << argv[1] << std::endl;
	std::fstream fs;
	fs.open (argv[1]);
	std::vector<int> numbers;
//	numbers.reserve(2147483647);
	std::cout << "checkpoint 1: " <<std::endl;
	int max = 0;
	int min = 0;
	int median = -1;
	std::string line;
	if (fs.is_open()) {
		while (getline(fs,line)) {
			int line_int;
			std::stringstream(line) >> line_int;
			if (max == 0) {max = line_int;}
			else {
				if (line_int > max) {max = line_int;}
			}
			if (min == 0) {min = line_int;}
			else {
				if (line_int < min) {min = line_int;}
			}
			std::cout << "checkpoint 2: " <<std::endl;
			numbers[line_int] += 1;			
		}
	}
	for (int i = 0; i < 2147483647; i++) {
		if (numbers[i] > 0) {
			if (median == -1) {
				median = i;
			}
			else if (median < numbers[i]) {
				median = i;
			}
		}
	}
	fs.close();
	std::cout << min << median << max <<std::endl;
}