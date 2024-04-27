#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

/**
 * @class FragTrap
 * @brief A class representing a FragTrap, inheriting virtually from ClapTrap.
 */
class FragTrap : virtual public ClapTrap {
public:
  /**
   * @brief Default constructor for FragTrap.
   */
  FragTrap(void);

  /**
   * @brief Parameterized constructor for FragTrap.
   * @param name The name of the FragTrap.
   */
  FragTrap(const std::string name);

  /**
   * @brief Destructor for FragTrap.
   */
  ~FragTrap(void);

  /**
   * @brief Copy constructor for FragTrap.
   * @param src The FragTrap object to copy.
   */
  FragTrap(FragTrap const &src);

  /**
   * @brief Assignment operator for FragTrap.
   * @param rhs The FragTrap object to assign.
   * @return A reference to the assigned FragTrap object.
   */
  FragTrap &operator=(FragTrap const &rhs);

  /**
   * @brief Function to perform an attack on a target.
   * @param target The target to attack.
   */
  void attack(const std::string &target);

  /**
   * @brief Function to initiate a high fives gesture.
   */
  void highFivesGuys(void);
};

#endif // !FRAGTRAP_HPP
