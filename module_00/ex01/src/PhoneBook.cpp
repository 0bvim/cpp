#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cctype>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

PhoneBook::PhoneBook(void) : currentIndex(0) {
  std::cout << "PhoneBook Constructor Called" << std::endl;
}

PhoneBook::~PhoneBook(void) {
  std::cout << "PhoneBook Destructor Called" << std::endl;
}

bool nameValidation(const std::string &name) {
  std::string::const_iterator it;
  if (name.empty() || name.size() < 2) {
    std::cout << "Field cannot be empty or have just one character."
              << std::endl;
    return true;
  }
  for (it = name.begin(); it != name.end(); ++it) {
    if (std::isdigit(*it)) {
      std::cout << "Only characters allowed." << std::endl;
      return true;
    }
  }
  return false;
}

std::string namesFun(const std::string msg) {

  std::string input;

  do {
    std::cout << msg << std::endl;
    std::getline(std::cin, input);
    if (std::cin.eof() || std::cin.fail() || nameValidation(input)) {
      input.clear();
      std::clearerr(stdin);
      std::cin.clear();
    }
  } while (input.empty());
  std::cin.clear();
  return input;
}

bool validPhone(const std::string &phone) {
  bool foundDigits, foundPlus, foundCountryCode = false;

  if (phone.empty() || phone.size() < 7 || phone.size() > 10) {
    std::cout << "Empty or invalid phone number." << std::endl;
    return false;
  }
  for (std::string::const_iterator it = phone.begin(); it != phone.end();
       ++it) {
    if (std::isdigit(*it)) {
      foundDigits = true;
    } else if (*it == '+') {
      if (it != phone.begin())
        return false;
      foundPlus = true;
    } else if (*it == '(' || *it == ')' || *it == '-' || *it == ' ') {
    } else {
      return false;
    }
  }
  return foundDigits && (foundPlus || !foundCountryCode);
}

std::string phoneFun(const std::string msg) {
  std::string input;

  do {
    std::cout << msg << std::endl;
    std::getline(std::cin, input);
    if (std::cin.eof() || std::cin.fail()) {
      std::clearerr(stdin);
      std::cin.clear();
    }
  } while (!validPhone(input));
  std::cin.clear();
  return input;
}

void PhoneBook::addContact(void) {
  if (currentIndex == 8)
    currentIndex = 0;
  if (currentIndex < 8) {
    Contact newContact;
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    newContact.setFirstName(namesFun("Enter First Name: "));
    newContact.setLastName(namesFun("Enter Last Name: "));
    newContact.setNickName(namesFun("Enter Nickname: "));
    newContact.setPhone(phoneFun("Enter phone number: "));
    newContact.setDarkestSecret(namesFun("Enter here the Darkest Secret: "));
    contactsList[currentIndex++] = newContact;
    std::cout << "Contact has been added to the PhoneBook!" << std::endl;
  }
}

bool validateIndex(std::string &index, Contact contactsList[8]) {
  std::string::const_iterator it;
  if (index.empty())
    return true;
  for (it = index.begin(); it != index.end(); ++it) {
    if (!std::isdigit(*it)) {
      std::cout << "Only numbers allowed." << std::endl;
      return true;
    }
  }
  int number;
  std::istringstream iss(index);
  iss >> number;
  if (!iss.fail() && iss.eof()) {
    if (number < 1 || number > 8) {
      std::cout << "Only numbers between 1 and 8 are allowed." << std::endl;
      return true;
    }
  }
  number -= 1;
  if (contactsList[number].getFirstName().empty()) {
    std::cout << "Empty index in phone book." << std::endl;
    return true;
  }
  std::cout << "First Name: " << contactsList[number].getFirstName()
            << std::endl;
  std::cout << "Last Name: " << contactsList[number].getLastName() << std::endl;
  std::cout << "Nickname: " << contactsList[number].getNickName() << std::endl;
  std::cout << "Phone number: " << contactsList[number].getPhone() << std::endl;
  std::cout << "Darkest Secret: " << contactsList[number].getDarkestSecret()
            << std::endl;
  return false;
}

void PhoneBook::searchContact(void) {
  std::cout << std::setw(10) << std::setfill(' ') << "Index"
            << "|" << std::setw(10) << std::setfill(' ') << "First Name"
            << "|" << std::setw(10) << std::setfill(' ') << "Last Name"
            << "|" << std::setw(10) << std::setfill(' ') << "Nickname"
            << std::endl;
  for (int i = 0; i < 8; ++i) {
    if (!contactsList[i].getFirstName().empty()) {
      std::cout << std::setw(10) << std::setfill(' ') << (i + 1) << "|"
                << std::setiosflags(std::ios::right) << std::setw(10)
                << std::setiosflags(std::ios::right) << std::setfill(' ')
                << (contactsList[i].getFirstName().length() > 10
                        ? contactsList[i].getFirstName().substr(0, 9) + "."
                        : contactsList[i].getFirstName())
                << "|" << std::setw(10) << std::setiosflags(std::ios::right)
                << std::setfill(' ')
                << (contactsList[i].getLastName().length() > 10
                        ? contactsList[i].getLastName().substr(0, 9) + "."
                        : contactsList[i].getLastName())
                << "|" << std::setw(10) << std::setiosflags(std::ios::right)
                << std::setfill(' ')
                << (contactsList[i].getNickName().length() > 10
                        ? contactsList[i].getNickName().substr(0, 9) + "."
                        : contactsList[i].getNickName())
                << std::endl;
    }
  }
  std::string index;
  do {
    std::cout << "Choose one index to display:" << std::endl;
    std::getline(std::cin, index);
    if (std::cin.eof() || std::cin.fail() ||
        validateIndex(index, contactsList)) {
      index.clear();
      std::clearerr(stdin);
      std::cin.clear();
    }
  } while (index.empty());
  std::cin.clear();
}
