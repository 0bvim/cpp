#include "PhoneBook.hpp"
#include <iostream>
#include <cstdio>

void	clearCin(void) {
	fflush(stdin);
	std::clearerr(stdin);
	std::cin.clear();
}

int main (void) {
	
	PhoneBook book;
	
	while (true) {
		if (std::cin.eof() || std::cin.fail())
			clearCin();
	}

	return 0;
}
