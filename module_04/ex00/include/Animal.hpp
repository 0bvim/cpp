#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

/**
 * @brief The Animal class represents a generic animal.
 * 
 * This class provides a base interface for all animals.
 */
class Animal {
protected:
  std::string _type; /**< The type of the animal. */

public:
  /**
   * @brief Default constructor.
   */
  Animal(void);

  /**
   * @brief Destructor.
   */
  virtual ~Animal(void);

  /**
   * @brief Copy constructor.
   * 
   * @param rhs The animal to copy.
   */
  Animal(Animal const &rhs);

  /**
   * @brief Assignment operator.
   * 
   * @param rhs The animal to assign.
   * @return A reference to the assigned animal.
   */
  Animal &operator=(Animal const &rhs);

  /**
   * @brief Get the type of the animal.
   * 
   * @return The type of the animal.
   */
  virtual std::string getType(void) const;

  /**
   * @brief Make a sound specific to the animal.
   * 
   * This is a pure virtual function.
   * Subclasses must override this function to provide
   * specific sound behavior.
   */
  virtual void makeSound() const;
};

#endif // ANIMAL_HPP
