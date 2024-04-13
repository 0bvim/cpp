#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB {

private:
	Weapon my_weapon;
	std::string _name;

public:
	/* implement constructor with Weapon; */
	HumanB();
	~HumanB();

	void setName(const std::string& name);
	const std::string& getName();
	void setWeaponType(const std::string type);
	const std::string& getWeaponType();
	void attack();
};

#endif // !HUMANB_HPP
