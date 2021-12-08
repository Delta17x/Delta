// Delta.cpp : Defines the entry point for the application.
//

#include "include/delta/memory.hpp"
#include "include/delta/type_traits.hpp"
#include <iostream>

struct foo {

};

int main() {
	std::cout << sizeof(dlt::detected_or<int, int, int>);
	return 0;
}
