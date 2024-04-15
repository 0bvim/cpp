#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _weapon(NULL), _name(name) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon) { _weapon = &weapon; }

void HumanB::attack() const {
  std::cout << this->_name + " attacks with their "
            << (_weapon != NULL ? _weapon->getType() : "hand")
            << std::endl;
}
