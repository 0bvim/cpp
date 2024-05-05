#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

Character::Character() : _name("none") {
	for (int i = 0; i < 4; ++i) {
		_inventory[i] = NULL;
	}
	std::cout << "Character constructor called." << std::endl;
}

Character::Character(std::string const &name) : _name(name) {
	for (int i = 0; i < 4; ++i) {
		_inventory[i] = NULL;
	}
	std::cout << "Character name constructor called." << std::endl;
}

Character::Character(Character const &rhs) {
	std::cout << "Character copy constructor called." << std::endl;
	*this = rhs;
}

Character::~Character() {
	std::cout << "Character destructor called." << std::endl;
	for (int i = 0; i < 4; ++i) {
		delete _inventory[i];
	}
}

Character &Character::operator=(Character const &rhs) {
	std::cout << "Character assignmemnt constructor called." << std::endl;
	if (this != &rhs) {
		this->_name = rhs._name;
		for (int i = 0; i < 4; ++i) {
			if (rhs._inventory[i]) {
				this->_inventory[i] = rhs._inventory[i]->clone();
			} else {
				this->_inventory[i] = NULL;
			}
		}
	}
	return *this;
}

std::string const &Character::getName() const { return _name; }

void Character::equip(AMateria *m) {
	for (int i = 0; i < 4; ++i) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4) {
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target) {
	if (idx >= 0 && idx < 4 && _inventory[idx] != NULL) {
		_inventory[idx]->use(target);
  }
}
