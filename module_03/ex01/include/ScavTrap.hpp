#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
  // Enum to define different status types
  enum status { DEAD, ENERGY, DAMAGE, NEG_DMG, EMPTY_ATK, NEG_AMOUNT };

  // Constructors and destructor
  ScavTrap(void); // Default constructor
  ScavTrap(const std::string name); // Parameterized constructor
  ~ScavTrap(void); // Destructor
  ScavTrap(ScavTrap const &src); // Copy constructor
  ScavTrap &operator=(ScavTrap const &rhs); // Assignment operator

  // Member functions
  void attack(const std::string &target); // Function to perform attack
  void guardGate(); // Function for guarding the gate

private:
  // Helper function to print messages based on status
  void messages(status type) const;
};

#endif // !SCAVTRAP_HPP
