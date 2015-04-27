#ifndef A7_HPP
#define A7_HPP

#include "symbol.hpp"
#include <iostream>
#include <queue>

// IMPLEMENT YOUR FUNCTION huffman_tree

class Compare_symbol {
public:
    bool operator()(bnode<symbol>* b1, bnode<symbol>* b2) {
    	return b1.value()<b2.value();
	}
};

template <typename Iter>
bnode<symbol>* huffman_tree(Iter first, Iter last) {
	std::priority_queue<bnode<symbol>, std::vector<symbol>, Compare_symbol> q;
	int size = 0;
	for (; first != last; first ++) {
		bnode<symbol> = 
		q.push(*first);
		size++;
	}
	std::cout<< "size" << size <<std::endl;
	
	
}

// IMPLEMENT YOUR FUNCTION release_tree
void release_tree(bnode<symbol>* root){
	//go left (release tree left)
	//go right (release tree right)
	//delete root
}

#endif // A7_HPP
