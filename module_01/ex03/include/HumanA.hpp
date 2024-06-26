#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA {

private:
	Weapon &_weapon;
	std::string _name;

public:
	/* implement constructor with Weapon; */
	HumanA(std::string name, Weapon &weapon);
	~HumanA();

	void setName(const std::string& name);
	const std::string& getName();
	void setWeapon(Weapon weapon);
	const std::string& getWeapon();
	void attack();
};

#endif // !HUMANA_HPP
