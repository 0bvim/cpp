#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB() {}

HumanB::HumanB(const std::string& name) : _name(name) {}

HumanB::~HumanB() {}

const std::string &HumanB::getName() { return _name; }

void HumanB::setName(const std::string &name) { _name = name; }

void HumanB::setWeapon(Weapon weapon) { my_weapon = weapon; }

const std::string &HumanB::getWeapon() { return my_weapon.getType(); }

void HumanB::attack() {
  std::cout << this->getName() + " attacks with their " << getWeapon()
            << std::endl;
}
