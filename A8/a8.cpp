#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>


int main (int argc, char* argv[]) {
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
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
		}
	}
	std::string test_name;
    while (std::cin >> test_name) {
    	//check if name in dictionary
   		std::map<std::string, int>::iterator search1 = dictionary.find(test_name);
    	if (search1 != dictionary.end()) {
    		std::cout << test_name << " " << search1->second << std::endl;
    		search1->second += 1;    	
		}
		//else begin correction process
	    else {  
		    int name_size = test_name.size();
		    int possible_corrections = (name_size + 26*(name_size + 1) + 25*name_size);
 		    std::vector<std::string> correction_list(possible_corrections);
 		    /*add in all possible corrections to vector
 		    	-deletion
 		    	-insertion
 		    	-substitution
 		    */
 		    
    		
    		
    		//correction check setup
 		    bool first_correction = true;
 		    std::string correction;
 		    int correction_value;
 	    	
 	    	//correction check
		    for (int i = 0; i < possible_corrections; i++) {
 		   		std::map<std::string, int>::iterator search2 = dictionary.find(correction_list[i]);
 		   		if (search2 != dictionary.end()) {
 		   			//if first match, set correction
 		   			if (first_correction) {
 		   				correction = (correction_list[i]);
 		   				correction_value = search2->second;
 		   				first_correction = false;
 		   			}
 		   			else {
    					//compare frequency
    					if (search2->second <= correction_value) continue;
    					//compare length
    					else if ((correction_list[i]).size()<= correction.size()) continue;
    					//set
    					else {
    						correction = correction_list[i];
    						correction_value = search2->second;
    					}
 		   			}
 		   		}
 	  		}
 	  		//if not in dictionary print then add to dictionary
 	  		if (first_correction) {
 	  			std::cout << "-" << std::endl;
 	  			dictionary.insert (std::pair<std::string,int>(test_name, 1));
 	  		}
 	  		//else print and increase
 	  		else {
 	  			std::cout << correction << " " << correction_value << std::endl;
 	  			std::map<std::string, int>::iterator search3 = dictionary.find(correction);
    			if (search3 != dictionary.end()) {
    				search3->second += 1;    	
				}
 	  		}
   		}
    //if name is in dictionary print with frequency, then increase frequency DONE
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

