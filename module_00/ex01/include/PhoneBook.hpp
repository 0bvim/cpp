#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {

private:
  Contact contactsList[8];
  int currentIndex;

public:
  PhoneBook(void);
  ~PhoneBook(void);

  void addContact(void);
  void searchContact(void);
};

#endif // !PHONEBOOK_HPP
