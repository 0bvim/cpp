#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

/**
 * @brief The Cat class represents a cat.
 * 
 * This class inherits from Animal and provides
 * specific functionality for a cat.
 */
class Cat : public Animal {
public:
  /**
   * @brief Default constructor.
   */
  Cat();

  /**
   * @brief Destructor.
   */
  ~Cat();

  /**
   * @brief Copy constructor.
   * 
   * @param rhs The cat to copy.
   */
  Cat(Cat const &rhs);

  /**
   * @brief Assignment operator.
   * 
   * @param rhs The cat to assign.
   * @return A reference to the assigned cat.
   */
  Cat &operator=(Cat const &rhs);

  /**
   * @brief Make a sound specific to a cat.
   * 
   * This function overrides the makeSound() function
   * in the base class Animal.
   */
  void makeSound() const;
};

#endif // CAT_HPP
