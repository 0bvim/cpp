#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA {

private:
	Weapon my_weapon;
	std::string _name;

public:
	/* implement constructor with Weapon; */
	HumanA();
	~HumanA();

	void setName(const std::string& name);
	const std::string& getName();
	void setWeaponType(const std::string type);
	const std::string& getWeaponType();
	void attack();
};

#endif // !HUMAN_A_HPP
