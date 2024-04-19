#ifndef FIXED_HPP
#define FIXED_HPP

/**
 * @brief The Fixed class represents a fixed-point number with 8 fractional bits.
 * 
 * Fixed-point numbers are used to represent decimal numbers in binary systems 
 * by allocating a fixed number of bits to the fractional part. In this class, 
 * we allocate 8 bits to represent the fractional part of the number.
 */
class Fixed {
public:
  /**
   * @brief Default constructor.
   * 
   * Initializes the Fixed object to 0.
   */
  Fixed(void);

  /**
   * @brief Copy constructor.
   * 
   * Initializes the Fixed object as a copy of another Fixed object.
   * 
   * @param src The Fixed object to copy.
   */
  Fixed(Fixed const &src);

  /**
   * @brief Assignment operator.
   * 
   * Assigns the value of another Fixed object to this object.
   * 
   * @param rhs The Fixed object to assign.
   * @return Reference to the assigned Fixed object.
   */
  Fixed &operator=(Fixed const &rhs);

  /**
   * @brief Get the raw integer representation of the Fixed object.
   * 
   * @return The raw integer value representing the Fixed object.
   */
  int getRawBits(void) const;

  /**
   * @brief Set the raw integer representation of the Fixed object.
   * 
   * @param raw The raw integer value to set.
   */
  void setRawBits(int const raw);

  /**
   * @brief Destructor.
   */
  ~Fixed(void);

private:
  int _fixedValue; /**< The raw integer value representing the Fixed object. */
  static const int _raw = 8; /**< The number of fractional bits allocated for the Fixed object. */
};

#endif // FIXED_HPP
