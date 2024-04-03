#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int main (void) {
	
	Contact instance;

	instance.setFirstName("Vinicius");
	instance.setLastName("Pereira");
	instance.setNickName("Vimni");
	instance.setDarkestSecret("Secret_Key");
	instance.setPhone("999999999");
	
	std::cout << "First Name: " << instance.getFirstName() << std::endl;
	std::cout << "Last Name: " << instance.getLastName() << std::endl;
	std::cout << "NickName: " << instance.getNickName() << std::endl;
	std::cout << "Secret: " << instance.getDarkestSecret() << std::endl;
	std::cout << "Phone: " << instance.getPhone() << std::endl;

	return 0;
}
