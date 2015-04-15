#ifndef A6_HPP
#define A6_HPP

#include "token.hpp"
#include <stdexcept>
#include <stack>
#include <iostream>


template <typename Iter> double RPN(Iter first, Iter last) {
	std::stack<double> operands;
	double result;
	for (; first != last; first ++) {
		if ((*first).is_operand()){
			operands.push((*first).as_operand());
		}
		else if ((*first).is_operator()) {
				if (operands.size() < 2) throw std::runtime_error("error");
				double one = operands.top();
				operands.pop();
				double two = operands.top();
				operands.pop();
				char the_operator = (*first).as_operator();
				if (the_operator == '/' && one == 0) throw std::runtime_error("error");
				if (the_operator == '+') {
					result = one + two;
				}
				else if (the_operator == '-') {
					result = two - one;
				}
				else if (the_operator == '*') {
					result = one*two;
				}
				else if (the_operator == '/') {
					result = two/one;
				}
				operands.push(result);
			}
		else {throw std::runtime_error("error");}
	}
	if (operands.size() > 1) throw std::runtime_error("error");
	return result;
}
#endif // A6_HPP
