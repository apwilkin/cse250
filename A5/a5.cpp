#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

//add each int without sorting
//do merge sort
//iterate through vector


int main (int argc, char* argv[]) {
	std::fstream fs;
	fs.open (argv[1]);
	std::vector<int> numbers;
	int max = 0;
	int min = 0;
	int median;
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
			numbers.push_back(line_int);			
		}
	}
	std::sort (numbers.begin(), numbers.end());
	median = numbers[(((numbers.size()) - 1)/2)];
	fs.close();
	std::cout << min << " " << median << " " << max <<std::endl;
}
