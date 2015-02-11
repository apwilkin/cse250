#include <fstream>
#include <iostream>
#include <typeinfo>
#include <sstream>
#include <vector>
#include <math.h>

int main (int argc, char* argv[]){
	if (!(argc == 2)) {
		std::cout << "error" << std::endl;
		return 0;
	}
//	std::cout << "Filename: " << argv[1] << std::endl;
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
						std::cout << "error" << '\n';
						return 0;
					}
//					std::vector<int> kmer_vector_temp (4^k, 0);
//					kmer_vector = kmer_vector_temp;
					kmer_vector.reserve(pow (4,k));
			}
			else {
				if (line_length >= k) {
					for (int i = 0; i < line_length - k + 1; i++) {
						std::string kmer;
//						int ikmer;
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
//						std::cout << "kmer: " << kmer << std::endl;
						//std::stringstream(kmer) >> ikmer;
						int kmer_length = kmer.length();
						int position = 0;
						for (int j = 0; j < kmer_length; j++) {
//							std::cout<< "kmer[j]: " << kmer[j] << std::endl;
							int tempint = kmer[j] - '0';
//							std::cout<< "tempint: " << tempint << std::endl;
							position = position + ((pow (4, k-j-1))*(tempint));
//							std::cout<< "position: " << position << std::endl;
						}
						kmer_vector[position] = kmer_vector[position] + 1;
//						std::cout << "kmer_vector[position]" << kmer_vector[position] << std::endl;
					}
				}
			}						
			line_number ++;
		}
		if (!((line_number - 1) == m)) {
			std::cout << "error" << '\n';
			return 0;
		}
		
		for (int i = 0; i < pow (4, k); i++) {
			if (!kmer_vector[i] == 0) {
//				this is the int that will be used to generate the base 4 kmer string
				int testint = i + 1;
				std::string kmerstring = "";
				for (int j = k - 1; j > -1; j--) {
					int tempint1 = pow (4, j);
					int tempint2 = 2*tempint1;
					int tempint3 = 3*tempint1;
					if ((testint - tempint3) > 0) {
						testint = testint - tempint3;
						kmerstring += "3";
					}
					else if((testint - tempint2) > 0) {
						testint = testint - tempint2;
						kmerstring += "2";
					}
					else if((testint - tempint1) > 0) {
						testint = testint - tempint1;
						kmerstring += "1";
					}
					else {
						kmerstring += "0";
					}
				}
//				std::cout << "kmerstring result: " << kmerstring << std::endl;
				int kmerstring_length = kmerstring.length();
				std::string converted_kmer = "";

				for (int j = 0; j < kmerstring_length; j++) {
					if (kmerstring.at(j) == '0') {
								converted_kmer += 'A';
					}
					else if (kmerstring.at(j) == '1') {
						converted_kmer += 'C';
					}
					else if (kmerstring.at(j) == '2') {
						converted_kmer += 'G';
					}
					else if (kmerstring.at(j) == '3') {
						converted_kmer += 'T';
					}
				}
												
				std::cout << converted_kmer << " " << kmer_vector[i] << std::endl;
			}
		}
		
	}
	fs.close();
	return 0;
}
