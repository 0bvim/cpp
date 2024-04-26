#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
  enum status { DEAD, ENERGY, DAMAGE, NEG_DMG, EMPTY_ATK, NEG_AMOUNT };

  ScavTrap(void);
	ScavTrap(const std::string name);
  ~ScavTrap(void);
  ScavTrap(ScavTrap const &src);
  ScavTrap &operator=(ScavTrap const &rhs);
	
  void attack(const std::string &target);
	void guardGate();

private:
  void messages(status type) const;
};

#endif // !SCAVTRAP_HPP
