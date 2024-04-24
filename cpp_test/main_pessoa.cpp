#include "Pessoa.hpp"
#include <iostream>

int main () {

	Pessoa cadete;

	cadete.setName("Adedayo");
	std::cout << cadete.getName() << std::endl;

	return 0;
}
