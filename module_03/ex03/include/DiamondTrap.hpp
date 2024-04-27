#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

/**
 * @class DiamondTrap
 * @brief A class representing a DiamondTrap, inheriting from ScavTrap and FragTrap.
 */
class DiamondTrap : public ScavTrap, public FragTrap {
public:
  /**
   * @brief Default constructor for DiamondTrap.
   */
  DiamondTrap(void);

  /**
   * @brief Parameterized constructor for DiamondTrap.
   * @param name The name of the DiamondTrap.
   */
  DiamondTrap(const std::string name);

  /**
   * @brief Destructor for DiamondTrap.
   */
  ~DiamondTrap(void);

  /**
   * @brief Copy constructor for DiamondTrap.
   * @param src The DiamondTrap object to copy.
   */
  DiamondTrap(DiamondTrap const &src);

  /**
   * @brief Assignment operator for DiamondTrap.
   * @param rhs The DiamondTrap object to assign.
   * @return A reference to the assigned DiamondTrap object.
   */
  DiamondTrap &operator=(DiamondTrap const &rhs);

  /**
   * @brief Function to perform an attack on a target.
   * @param target The target to attack.
   */
  void attack(const std::string &target);

  /**
   * @brief Function to display information about the DiamondTrap.
   */
  void whoAmI(void);

private:
  std::string _name; ///< The name of the DiamondTrap.
};

#endif // !DIAMONDTRAP_HPP
