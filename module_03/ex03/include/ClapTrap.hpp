#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

/**
 * @brief The ClapTrap class represents a generic robot.
 */
class ClapTrap {
public:
  /**
   * @brief Enumeration of different status types.
   */
  enum status { DEAD, ENERGY, DAMAGE, NEG_DMG, EMPTY_ATK, NEG_AMOUNT };

  /**
   * @brief Default constructor.
   */
  ClapTrap(void);

  /**
   * @brief Parameterized constructor.
   * @param name The name of the ClapTrap.
   */
  ClapTrap(const std::string name);

  /**
   * @brief Copy constructor.
   * @param src The ClapTrap object to copy.
   */
  ClapTrap(ClapTrap const &src);

  /**
   * @brief Assignment operator overload.
   * @param rhs The ClapTrap object to assign.
   * @return Reference to the assigned ClapTrap object.
   */
  ClapTrap &operator=(ClapTrap const &rhs);

  /**
   * @brief Destructor.
   */
  ~ClapTrap(void);

  /**
   * @brief Attacks a target.
   * @param target The target to attack.
   */
  void attack(const std::string &target);

  /**
   * @brief Takes damage.
   * @param amount The amount of damage to take.
   */
  void takeDamage(unsigned int amount);

  /**
   * @brief Repairs the ClapTrap.
   * @param amount The amount to repair.
   */
  void beRepaired(unsigned int amount);

  /**
   * @brief Gets the name of the ClapTrap.
   * @return The name of the ClapTrap.
   */
  std::string getName(void) const;

  /**
   * @brief Gets the hit points of the ClapTrap.
   * @return The hit points of the ClapTrap.
   */
  unsigned int getHitPoints(void) const;

  /**
   * @brief Gets the energy points of the ClapTrap.
   * @return The energy points of the ClapTrap.
   */
  unsigned int getEnergypoint(void) const;

  /**
   * @brief Gets the attack damage of the ClapTrap.
   * @return The attack damage of the ClapTrap.
   */
  unsigned int getAttackDamage(void) const;

  /**
   * @brief Sets the name of the ClapTrap.
   * @param name The name to set.
   */
  void setName(const std::string name);

  /**
   * @brief Sets the hit points of the ClapTrap.
   * @param hp The hit points to set.
   */
  void setHitPoints(unsigned int hp);

  /**
   * @brief Sets the energy points of the ClapTrap.
   * @param ep The energy points to set.
   */
  void setEnergyPoint(unsigned int ep);

  /**
   * @brief Sets the attack damage of the ClapTrap.
   * @param atk The attack damage to set.
   */
  void setAttackDamage(unsigned int atk);

	/**
	 * @brief Prints messages based on status type.
	 * @param type The status type.
	 */
	void messages(status type) const;

protected:
  std::string _name; /**< The name of the ClapTrap. */
  unsigned int _energyPoints; /**< The energy points of the ClapTrap. */
  unsigned int _hitPoints; /**< The hit points of the ClapTrap. */
  unsigned int _attackDamage; /**< The attack damage of the ClapTrap. */

};

#endif // !CLAPTRAP_HPP
