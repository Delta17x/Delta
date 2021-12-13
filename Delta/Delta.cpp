// Delta.cpp : Defines the entry point for the application.
//


#include <iostream>
#include "include/delta/memory.hpp"
#include "include/delta/type_traits.hpp"
#include "include/delta/exception.hpp"
#include "include/delta/arithmetic.hpp"
#include "include/delta/data.hpp"
#include <cmath>
#include <vector>

class A {};
class B : A {};

int main() {
	dlt::array<int> jeff;
	//dlt::iterator<int> iter(&foo[0], &foo[0] + foo.size());
	for (auto i : jeff) {
		//std::cout << dlt::is_base_of<A, B>::value;
	}


	return 0;
}
