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

void	Sample::bar(void) {
	std::cout << "Calling a member function" << std::endl;
}
