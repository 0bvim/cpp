#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
  // Constructors and destructor
  FragTrap(void); // Default constructor
  FragTrap(const std::string name); // Parameterized constructor
  ~FragTrap(void); // Destructor
  FragTrap(FragTrap const &src); // Copy constructor
  FragTrap &operator=(FragTrap const &rhs); // Assignment operator

  // Member functions
  void attack(const std::string &target); // Function to perform attack
	void highFivesGuys(void);
};

#endif // !FRAGTRAP_HPP
