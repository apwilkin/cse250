#ifndef A7_HPP
#define A7_HPP

#include "symbol.hpp"

// IMPLEMENT YOUR FUNCTION huffman_tree
template <typename Iter>
bnode<symbol>* huffman_tree(Iter first, Iter last) {
	std::vector<symbol> v1 (last - first);
	std::vector<symbol> v2 (last - first);
	for (; first != last; first ++) {
		v1.push_back(*first);
	}
	v2 = v1;
	int smallest;
	int next_smallest;
	
}

// IMPLEMENT YOUR FUNCTION release_tree
void release_tree(bnode<symbol>* root){
	
}

#endif // A7_HPP
