#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
public:
  ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &src);
	ClapTrap &operator=(ClapTrap const &rhs);
  ~ClapTrap(void);

  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

	unsigned int getHitPoints(void);
	unsigned int getEnergypoint(void);
	unsigned int getAttackDamage(void);
	void setHitPoints(unsigned int);
	void setEnergypoint(unsigned int);
	void setAttackDamage(unsigned int);

private:
	std::string _name;
  unsigned int _energyPoints;
  unsigned int _hitPoints;
  unsigned int _attackDamage;
};

#endif // !CLAPTRAP_HPP
