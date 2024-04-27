#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

/**
 * @class ScavTrap
 * @brief A class representing a ScavTrap, inheriting virtually from ClapTrap.
 */
class ScavTrap : public ClapTrap {
public:
  /**
   * @brief Default constructor for ScavTrap.
   */
  ScavTrap(void);

  /**
   * @brief Parameterized constructor for ScavTrap.
   * @param name The name of the ScavTrap.
   */
  ScavTrap(const std::string name);

  /**
   * @brief Destructor for ScavTrap.
   */
  ~ScavTrap(void);

  /**
   * @brief Copy constructor for ScavTrap.
   * @param src The ScavTrap object to copy.
   */
  ScavTrap(ScavTrap const &src);

  /**
   * @brief Assignment operator for ScavTrap.
   * @param rhs The ScavTrap object to assign.
   * @return A reference to the assigned ScavTrap object.
   */
  ScavTrap &operator=(ScavTrap const &rhs);

  /**
   * @brief Function to perform an attack on a target.
   * @param target The target to attack.
   */
  void attack(const std::string &target);

  /**
   * @brief Function for guarding the gate.
   */
  void guardGate();
};

#endif // !SCAVTRAP_HPP
