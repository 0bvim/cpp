#include "Class.hpp"
#include <iostream>

int main (void) {
	Sample instance;

	/* adding value in a variable using object instance */
	instance.setFoo(42);
	/* with get, you can get value attributed to a variable of object */
	std::cout << "Foo value after set: " << instance.getFoo() << std::endl;
	instance.setFoo(-42);
	std::cout << "Foo value after try to set a negative value: " << instance.getFoo() << std::endl;

	return 0;
}
