#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

/**
 * @brief The wrongAnimal class represents a generic animal (incorrectly named).
 * 
 * This class provides a base interface for all animals.
 * Note: The class name is incorrect; it should be 'WrongAnimal' instead of 'wrongAnimal'.
 */
class wrongAnimal {
protected:
  std::string _type; /**< The type of the animal. */

public:
  /**
   * @brief Default constructor.
   */
  wrongAnimal();

  /**
   * @brief Destructor.
   */
  ~wrongAnimal();

  /**
   * @brief Copy constructor.
   * 
   * @param rhs The animal to copy.
   */
  wrongAnimal(wrongAnimal const &rhs);

  /**
   * @brief Assignment operator.
   * 
   * @param rhs The animal to assign.
   * @return A reference to the assigned animal.
   */
  wrongAnimal &operator=(wrongAnimal const &rhs);

  /**
   * @brief Get the type of the animal.
   * 
   * @return The type of the animal.
   */
  std::string getType(void) const;

  /**
   * @brief Make a sound specific to the animal.
   * 
   * This function represents a generic sound made by an animal.
   */
  void makeSound() const;
};

#endif // WRONGANIMAL_HPP
