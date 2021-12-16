#include <iostream>
#include "include/delta/memory.hpp"
#include "include/delta/type_traits.hpp"
#include "include/delta/exception.hpp"
#include "include/delta/arithmetic.hpp"
#include "include/delta/containers.hpp"
#include <cmath>
#include <vector>
#include <array>


int main() {
	dlt::array<int> foo(8);
	for (int i = 0; i < 8; i++) {
		foo[i] = i;
	} 



	dlt::array<int>::iterator iter(foo.begin());
	while (iter != foo.end()) {
		std::cout << *iter++ << "\n";
	} 	
	return 0;
}
