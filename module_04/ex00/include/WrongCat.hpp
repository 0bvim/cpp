#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

/**
 * @class wrongCat
 * @brief A class representing a wrong implementation of a cat.
 *
 * This class inherits from wrongAnimal and provides a specific implementation
 * for a wrong version of a cat.
 */
class wrongCat : public wrongAnimal {
public:
  /**
   * @brief Default constructor.
   */
  wrongCat();

  /**
   * @brief Destructor.
   */
  ~wrongCat();

  /**
   * @brief Copy constructor.
   * @param rhs The wrongCat object to copy.
   */
  wrongCat(wrongCat const &rhs);

  /**
   * @brief Assignment operator.
   * @param rhs The wrongCat object to assign.
   * @return A reference to the assigned wrongCat object.
   */
  wrongCat &operator=(wrongCat const &rhs);

  /**
   * @brief Makes the cat sound.
   *
   * This function makes the cat sound. Since this is a wrong implementation,
   * it may not produce the correct sound.
   */
  void makeSound() const;
};

#endif // !WRONGCAT_HPP
