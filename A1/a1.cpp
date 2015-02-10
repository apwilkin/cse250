#include <fstream>
#include <iostream>
#include <typeinfo>
#include <sstream>
#include <vector>

int main (int argc, char* argv[]){
	if (!(argc == 2)) {
		std::cout << "error 1" << std::endl;
		return 0;
	}
	//std::cout << "Filename: " << argv[1] << std::endl;
	std::fstream fs;
	fs.open (argv[1]);
	std::string line;
	int line_number = 0;
	int k = 0;
	int m = 0;
	std::vector<int> kmer_vector;
	if (fs.is_open()) {
		while ( getline (fs,line) ) {
			int line_length = line.length();
			if (line_number == 0) {
					std::string first;
					std::string second;
					bool second_string = false;
					for (int i=0; i< line_length; i++) {
						if (!second_string) {
							if (!(line.at(i) == ' ')) {
								first += line.at(i);
							}
							else {
								second_string = true;
							}
						}
						else {
							second += line.at(i);
						}
					}
					std::stringstream(first) >> k;
					std::stringstream(second) >> m;
					if (!(m>1) || !(k>=3) || !(k<=10)) {
						std::cout << "error 2" << '\n';
						return 0;
					}
					std::vector<int> kmer_vector_temp (4^k, 0);
					kmer_vector = kmer_vector_temp;
			}
			else {
				if (line_length >= k) {
					for (int i = 0; i < line_length - k + 1; i++) {
						std::string kmer;
						//int ikmer;
						for (int j = 0; j < k; j++) {
							if (line.at(i + j) == 'A') {
								kmer += '0';
							}
							else if (line.at(i + j) == 'C') {
								kmer += '1';
							}
							else if (line.at(i + j) == 'G') {
								kmer += '2';
							}
							else if (line.at(i + j) == 'T') {
								kmer += '3';
							}
						}
						std::cout << "kmer: " << kmer << std::endl;
						//std::stringstream(kmer) >> ikmer;
						int kmer_length = kmer.length();
						int position = 0;
						for (int j = 0; j < kmer_length; j++) {
							std::cout<< "kmer[j]: " << kmer[j] << std::endl;
							int tempint = kmer[j] - '0';
							std::cout<< "tempint: " << tempint << std::endl;
							position = position + (4^(k-j-1)*(tempint));
							std::cout<< "position: " << position << std::endl;
						}
						kmer_vector[position] = kmer_vector[position] + 1;
						std::cout << kmer_vector[position] << std::endl;
					}
				}
			}						
			line_number ++;
		}
		if (!((line_number - 1) == m)) {
			std::cout << "error 3" << '\n';
			return 0;
		}
		//iterate through array and print kmers
	}
	fs.close();
	return 0;
}
