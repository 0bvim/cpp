#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
public:
  ClapTrap(void);
  ~ClapTrap(void);

  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

private:
  unsigned int energyPoints;
  unsigned int hitPoints;
  unsigned int attackDamage;
};

#endif // !CLAPTRAP_HPP
