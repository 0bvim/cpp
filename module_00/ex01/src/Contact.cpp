#include <iostream>
#include <string>
#include "Contact.hpp"

Contact::Contact(void) {
	std::cout << "Constructor Called" << std::endl;
}

Contact::~Contact(void) {
	std::cout << "Destructor Called" << std::endl;
}

void	Contact::setFirstName(const std::string &firstName) {
	this->_firstName = firstName;
}

void	Contact::setLastName(const std::string &lastName) {
	this->_lastName = lastName;
}

void	Contact::setNickName(const std::string &nickName) {
	this->_nickName = nickName;
}

void	Contact::setDarkestSecret(const std::string &darkestSecret) {
	this->_darkestSecret = darkestSecret;
}

void	Contact::setPhone(const std::string &phone) {
	this->_phone = phone;
}

std::string	Contact::getFirstName(void) {
	return this->_firstName;
}

std::string	Contact::getLastName(void) {
	return this->_lastName;
}

std::string	Contact::getNickName(void) {
	return this->_nickName;
}

std::string	Contact::getDarkestSecret(void) {
	return this->_darkestSecret;
}

std::string	Contact::getPhone(void) {
	return this->_phone;
}

