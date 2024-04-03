#include "Class.hpp"
#include <iostream>

Sample::Sample(void) {
	std::cout << "Constructor Called" << std::endl;
	return;
}

Sample::~Sample(void) {
	std::cout << "Destructor Called" << std::endl;
	return;
}

// const is to how try access have a 'read-only mode'
int	Sample::getFoo(void) const {
	return this->_foo;
}

void	Sample::setFoo(int v) {
	if (v >= 0)
		this->_foo = v;
	return ;
}
