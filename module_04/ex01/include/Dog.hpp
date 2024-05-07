#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

/**
 * @class Dog
 * @brief Represents a dog, inheriting from the Animal class.
 *
 * This class represents a dog, which is a specific type of animal.
 * It inherits properties and behaviors from the Animal class and has
 * its own additional features.
 */
class Dog : public Animal {
private:
  Brain *brain; /**< Pointer to the brain of the dog. */

public:
  /**
   * @brief Default constructor.
   * 
   * Constructs a Dog object with a default constructed Brain.
   */
  Dog();

  /**
   * @brief Destructor.
   * 
   * Destroys the Dog object and deallocates memory for the Brain.
   */
  ~Dog();

  /**
   * @brief Copy constructor.
   * 
   * Constructs a new Dog object as a copy of another Dog object.
   * Performs a deep copy of the Brain.
   * 
   * @param rhs The Dog object to be copied.
   */
  Dog(Dog const &rhs);

  /**
   * @brief Assignment operator.
   * 
   * Assigns the contents of another Dog object to this Dog object.
   * Performs a deep copy of the Brain.
   * 
   * @param rhs The Dog object to be assigned.
   * @return A reference to this Dog object.
   */
  Dog &operator=(Dog const &rhs);

  /**
   * @brief Makes the dog sound.
   * 
   * Produces the sound typically associated with a dog.
   */
  void makeSound() const;

  /**
   * @brief Gets the brain of the dog.
   * 
   * @return A pointer to the Brain object representing the dog's brain.
   */
  Brain *getBrain(void) const;
};

#endif // !DOG_HPP
