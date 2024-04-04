#include <cstdio>
#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	std::cout << "PhoneBook Constructor Called" << std::endl;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "PhoneBook Destructor Called" << std::endl;
}

/* void	clearCin(void) { */
/* 	std::cin.eof(); */
/* 	fflush(stdin); */
/* 	std::clearerr(stdin); */
/* 	std::cin.clear(); */
/* } */
