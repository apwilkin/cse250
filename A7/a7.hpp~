#ifndef A7_HPP
#define A7_HPP

#include "symbol.hpp"
#include <iostream>
#include <queue>

// IMPLEMENT YOUR FUNCTION huffman_tree

class Compare_symbol {
public:
    bool operator()(bnode<symbol>* b1, bnode<symbol>* b2) {
    	//return b1.value()<b2.value();
    	return ((b1)->value.count > ((b2)->value.count)
    	|| (!((b2)->value.count > (b1)->value.count) && ((b1)->value.value > (b2)->value.value)));
	}
};

template <typename Iter>
bnode<symbol>* huffman_tree(Iter first, Iter last) {
	std::priority_queue<bnode<symbol>*, std::vector<bnode<symbol>* >, Compare_symbol> q;
	//int size = 0;
	for (; first != last; first ++) {
		q.push(new bnode<symbol>(*first));
		//size++;
	}
	//std::cout<< "size" << size <<std::endl;
	while (q.size() > 1) {
		bnode<symbol>* smallest = q.top();
		q.pop();
		bnode<symbol>* next_smallest = q.top();
		q.pop();
		int sum = smallest->value.count + next_smallest->value.count;
		q.push(new bnode<symbol>(symbol(0,sum), smallest, next_smallest));	
		//get smallest
		//pop
		//get next smallest
		//pop
		//add values
		//add/make new node with left child smallest, right child next smallest, value = 0, count sum

	}
	
	return q.top();	
}

// IMPLEMENT YOUR FUNCTION release_tree
void release_tree(bnode<symbol>* root){
//	if (!(root->left->value.value == 0) && !(root->left->value.count == 0)) {
	//if (!(root->left == 0)) {
	//if (root->left->value.value != 0) {
	
	if (root->left != 0) {	
		release_tree(root->left);
		
	}
	
//	if (!(root->right->value.value == 0) && !(root->right->value.count == 0)) {
	//if (!(root->right == 0)) {
	//if (root->left->value.value != 0) {
	if (root->left != 0) {
		release_tree(root->right);
	}
	delete root;
	//go left (release tree left)
	//go right (release tree right)
	//delete root
}

#endif // A7_HPP
