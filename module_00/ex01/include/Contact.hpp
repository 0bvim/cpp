#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _darkestSecret;
	std::string _phone;


public:
	Contact();

	~Contact();
	std::string getFirstName();
	void setFirstName(const std::string&_firstName);
};

#endif // !CONTACT_HPP
