// Delta.cpp : Defines the entry point for the application.
//


#include <iostream>
#include "include/delta/memory.hpp"
#include "include/delta/type_traits.hpp"
#include "include/delta/exception.hpp"
#include "include/delta/arithmetic.hpp"
#include "include/delta/containers.hpp"
#include <cmath>
#include <vector>

class A {};
class B : A {};

int main() {
	dlt::array<int> foo(8);
	for (int i = 0; i < 8; i++) {
		foo[i] = i;
	}
	dlt::array<int>::iterator iter(&foo[0]);
	while (iter != foo.end()) 	{
		std::cout << *iter++ << "\n";
	}
	return 0;
}
