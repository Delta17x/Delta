// Delta.cpp : Defines the entry point for the application.
//

#include "include/delta/memory.hpp"
#include "include/delta/type_traits.hpp"
#include "include/delta/exception.hpp"
#include "include/delta/compile_math.hpp"
#include <iostream>


int main() {
	std::cout << dlt::exponent<4, -4>::data;
	return 0;
}
