#include "Class.hpp"
#include <iostream>

int main (void) {
	Sample test;

	test.foo = 42;
	std::cout << "Number in foo: " << test.foo << std::endl;
	test.bar();

	return 0;
}
