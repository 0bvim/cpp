#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <cstdio>
#include <string>

PhoneBook::PhoneBook(void) : currentIndex(0) {
  std::cout << "PhoneBook Constructor Called" << std::endl;
}

PhoneBook::~PhoneBook(void) {
  std::cout << "PhoneBook Destructor Called" << std::endl;
}

std::string namesFun(const std::string msg) {

  std::string input;

  do {
    std::cout << msg;
		std::getline(std::cin, input);
    if (std::cin.eof() || std::cin.fail()) {
      std::cout << "Field cannot be empty. Please try again." << std::endl;
			std::clearerr(stdin);
			std::cin.clear();
    }
  } while (input.empty());
  std::cin.clear();
  return input;
}

void PhoneBook::addContact(void) {
  if (currentIndex < 8) {
    Contact newContact;
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    newContact.setFirstName(namesFun("Enter First Name: "));
    newContact.setLastName(namesFun("Enter Last Name: "));
    newContact.setNickName(namesFun("Enter Nickname: "));
    newContact.setDarkestSecret(namesFun("Enter here the Darkest Secret: "));
  }
}
