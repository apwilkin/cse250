#ifndef A2
#define A2

#include <algorithm>

class A2 {
	public:
	//default constructor
	
	//copy constructor
	A2(const A2& a2) {
	}
	
	//(assignment) operator
	A2& operator=(const A2& a2) {
	}
	//indexing operator
	
	~A2 { delete[] ptr_; } //destructor
	
	private:
		int rows_;
		int columns_;
		T* ptr;

}

#endif
