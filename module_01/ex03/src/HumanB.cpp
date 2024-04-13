#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB() {}

HumanB::~HumanB() {}

const std::string &HumanB::getName() { return _name; }

void HumanB::setName(const std::string &name) { _name = name; }

void HumanB::setWeaponType(const std::string type) { my_weapon.setType(type); }

const std::string &HumanB::getWeaponType() { return my_weapon.getType(); }

void HumanB::attack() {
  std::cout << this->getName() + " attacks with their " << getWeaponType()
            << std::endl;
}
