#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

/**
 * @class Brain
 * @brief Represents the brain of an entity.
 *
 * This class represents the brain of an entity and holds a collection of ideas.
 */
class Brain {
private:
  std::string ideas[100]; /**< Array to store ideas in the brain. */

public:
  /**
   * @brief Default constructor.
   * 
   * Constructs a Brain object with an empty collection of ideas.
   */
  Brain();

  /**
   * @brief Destructor.
   * 
   * Destroys the Brain object.
   */
  ~Brain();

  /**
   * @brief Copy constructor.
   * 
   * Constructs a new Brain object as a copy of another Brain object.
   * Performs a deep copy of the ideas array.
   * 
   * @param rhs The Brain object to be copied.
   */
  Brain(Brain const &rhs);

  /**
   * @brief Assignment operator.
   * 
   * Assigns the contents of another Brain object to this Brain object.
   * Performs a deep copy of the ideas array.
   * 
   * @param rhs The Brain object to be assigned.
   * @return A reference to this Brain object.
   */
  Brain &operator=(Brain const &rhs);
};

#endif // !BRAIN_HPP
