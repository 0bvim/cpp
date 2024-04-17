#include "Integer.hpp"
#include <iostream>

int main (void) {

	Integer x(30);
	Integer y(20);
	Integer z(10);

	std::cout << "Value of x : " << x << std::endl;
	std::cout << "Value of y : " << y << std::endl;
	y = Integer(12);
	std::cout << "Value of y : " << y << std::endl;
	std::cout << "Value of z : " << z << std::endl;
	z = x + y;
	std::cout << "Value of z : " << z << std::endl;
	return 0;
}
