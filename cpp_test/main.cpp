#include "Class.hpp"
#include <iostream>

int main (void) {
	Sample instance;

	instance.setFoo(42);
	std::cout << "Foo value after set: " << instance.getFoo() << std::endl;
	instance.setFoo(-42);
	std::cout << "Foo value after try to set a negative value: " << instance.getFoo() << std::endl;

	return 0;
}
