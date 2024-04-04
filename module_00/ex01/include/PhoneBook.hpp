#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {

private:
	Contact	contactsList[8];

public:
	PhoneBook(void);
	~PhoneBook(void);
	
};

#endif // !PHONEBOOK_HPP
