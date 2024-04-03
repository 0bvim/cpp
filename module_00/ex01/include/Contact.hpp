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
	Contact(void);
	Contact(
		std::string _firstName,
		std::string _lastName,
		std::string _nickName,
		std::string _darkestSecret,
		std::string _phone);
	~Contact();

	void setFirstName(const std::string&_firstName);
	void setLastName(const std::string&_firstName);
	void setNickName(const std::string&_firstName);
	void setDarkestSecret(const std::string&_firstName);
	void setPhone(const std::string&_firstName);

	std::string getFirstName(const std::string&_firstName);
	std::string getLastName(const std::string&_firstName);
	std::string getNickName(const std::string&_firstName);
	std::string getDarkestSecret(const std::string&_firstName);
	std::string getPhone(const std::string&_firstName);
};

#endif // !CONTACT_HPP
