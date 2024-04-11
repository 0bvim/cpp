#include "PhoneBook.hpp"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>

void clearCin(void) {
  std::clearerr(stdin);
  std::cin.clear();
}

std::string prompt(void) {
  std::string user_input;

  std::cout << "Choose one option: " << std::endl;
  std::cout << "Type 'ADD' or 'SEARCH' a contact or 'EXIT' to close program."
            << std::endl;
	std::getline(std::cin, user_input);
  if (std::cin.eof() || std::cin.fail())
    clearCin();
  return user_input;
}

void handleInput(const std::string str, PhoneBook& book) {

  if (!str.compare("ADD")) {
		book.addContact();
  } else if (!str.compare("SEARCH")) {
    book.searchContact();
  } else if (!str.compare("EXIT")) {
    std::cout << "You lost your contacts forever..." << std::endl;
    exit(EXIT_SUCCESS);
  }
}
int main(void) {

  PhoneBook book;
  std::string input;

  std::cout << "Welcome to your lovely PhonoBook!" << std::endl;
  while (true) {
    input = prompt();
    handleInput(input, book);
  }

  return 0;
}
