#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

/**
 * @class Cat
 * @brief Represents a cat, inheriting from the Animal class.
 *
 * This class represents a cat, which is a specific type of animal.
 * It inherits properties and behaviors from the Animal class and has
 * its own additional features.
 */
class Cat : public Animal {
private:
  Brain *brain; /**< Pointer to the brain of the cat. */

public:
  /**
   * @brief Default constructor.
   * 
   * Constructs a Cat object with a default constructed Brain.
   */
  Cat();

  /**
   * @brief Destructor.
   * 
   * Destroys the Cat object and deallocates memory for the Brain.
   */
  ~Cat();

  /**
   * @brief Copy constructor.
   * 
   * Constructs a new Cat object as a copy of another Cat object.
   * Performs a deep copy of the Brain.
   * 
   * @param rhs The Cat object to be copied.
   */
  Cat(Cat const &rhs);

  /**
   * @brief Assignment operator.
   * 
   * Assigns the contents of another Cat object to this Cat object.
   * Performs a deep copy of the Brain.
   * 
   * @param rhs The Cat object to be assigned.
   * @return A reference to this Cat object.
   */
  Cat &operator=(Cat const &rhs);

  /**
   * @brief Makes the cat sound.
   * 
   * Produces the sound typically associated with a cat.
   */
  void makeSound() const;

  /**
   * @brief Gets the brain of the cat.
   * 
   * @return A pointer to the Brain object representing the cat's brain.
   */
  Brain *getBrain(void) const;
};

#endif // !CAT_HPP
