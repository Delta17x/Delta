// Delta.cpp : Defines the entry point for the application.
//

#include "include/delta/memory.hpp"
#include "include/delta/type_traits.hpp"
#include "include/delta/exception.hpp"
#include <iostream>


int main() {
	std::cout << dlt::is_reference_v<int&&>;
	return 0;
}
