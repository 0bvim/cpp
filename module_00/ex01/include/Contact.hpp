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
	~Contact(void);

	void setFirstName(const std::string &_firstName);
	void setLastName(const std::string &_firstName);
	void setNickName(const std::string &_firstName);
	void setDarkestSecret(const std::string &_firstName);
	void setPhone(const std::string &_firstName);

	std::string getFirstName(void);
	std::string getLastName(void);
	std::string getNickName(void);
	std::string getDarkestSecret(void);
	std::string getPhone(void);
};

#endif // !CONTACT_HPP
