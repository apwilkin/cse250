#include <fstream>
#include <iostream>
#include <map>
#include <sstream>


int main (int argc, char* argv[]) {
	std::fstream d_file;
	d_file.open(argv[1]);
	std::string dictionary_line;
	std::map<std::string, int> dictionary;
	if (d_file.is_open()) {
		while (getline(d_file, dictionary_line)) {
			std::string name;
			std::string value_string;			
			int value;
			bool is_name = true;
			for (int i = 0; i < dictionary_line.size(); i++) {
				if (dictionary_line[i] == ' ') {
					is_name = false;
					continue;
				}
				if (is_name) name += dictionary_line[i];
				else value_string += dictionary_line[i];
			}
			std::stringstream(value_string) >> value;
			dictionary.insert (std::pair<std::string,int>(name, value) );
			//add each entry in bst, with ordering based on frequency
		}
	}
	std::string test_name;
    while (std::cin >> test_name) {
    std::cout<< test_name <<std::endl;
    auto search1 = dictionary.find(test_name);
    if (search1 != dictionary.end()) std::cout << "x: " << it->second << "\n";
    //if name is in dictionary print with frequency, then increase frequency
    /*test each name
    make data structure that holds all possible corrections
    check to see if it is the best solution so far, go through map
    	- once frequency is less stop searching
    	- if string.length() is less, then set as new best possible correction
    print with frequency, then increase by one
    If no suggestions exist print - , then add to dictionary with frequency of 1
    */
    }
}
