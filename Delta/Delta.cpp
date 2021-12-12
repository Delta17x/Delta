// Delta.cpp : Defines the entry point for the application.
//


#include <iostream>
#include "include/delta/memory.hpp"
#include "include/delta/type_traits.hpp"
#include "include/delta/exception.hpp"
#include "include/delta/arithmetic.hpp"
#include "include/delta/iterator.hpp"
#include <cmath>


int main() {
	// Create an array of floats with 5 elements.
	float* foo = new float[6] {0, 1, 2, 3, 4, 5};
	// Create an iterator that starts at index 4 (element 5) and ends at index 0 (element 1).
	dlt::iterator<float> iter(foo, foo + 5);
	iter.jump(4);
	iter.jump(-3);
	std::cout << iter[5];
	// Delete the array.
	delete[] foo;
	return 0;
}
