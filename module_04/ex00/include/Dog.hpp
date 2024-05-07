#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

/**
 * @brief The Dog class represents a dog.
 * 
 * This class inherits from Animal and provides
 * specific functionality for a dog.
 */
class Dog : public Animal {
public:
  /**
   * @brief Default constructor.
   */
  Dog();

  /**
   * @brief Destructor.
   */
  ~Dog();

  /**
   * @brief Copy constructor.
   * 
   * @param rhs The dog to copy.
   */
  Dog(Dog const &rhs);

  /**
   * @brief Assignment operator.
   * 
   * @param rhs The dog to assign.
   * @return A reference to the assigned dog.
   */
  Dog &operator=(Dog const &rhs);

  /**
   * @brief Make a sound specific to a dog.
   * 
   * This function overrides the makeSound() function
   * in the base class Animal.
   */
  void makeSound() const;
};

#endif // DOG_HPP
