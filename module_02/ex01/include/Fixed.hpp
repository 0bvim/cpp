#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

/**
 * @brief The Fixed class represents fixed-point numbers with 8 fractional bits.
 *
 * Fixed-point numbers are a way to represent decimal numbers in binary systems 
 * by allocating a fixed number of bits to the fractional part. In this class, 
 * we allocate 8 bits to represent the fractional part of the number.
 */
class Fixed {
public:
  /**
   * @brief Default constructor initializes the Fixed object to 0.
   */
  Fixed(void);

  /**
   * @brief Int constructor initializes the Fixed object with an integer value.
   *
   * @param iraw The integer value to initialize the Fixed object with.
   */
  Fixed(const int iraw);

  /**
   * @brief Float constructor initializes the Fixed object with a float value.
   *
   * @param fraw The float value to initialize the Fixed object with.
   */
  Fixed(const float fraw);

  /**
   * @brief Copy constructor initializes the Fixed object as a copy of another Fixed object.
   *
   * @param src The Fixed object to copy.
   */
  Fixed(Fixed const &src);

  /**
   * @brief Assignment operator assigns the value of another Fixed object to this object.
   *
   * @param rhs The Fixed object to assign.
   * @return Reference to the assigned Fixed object.
   */
  Fixed &operator=(Fixed const &rhs);

  /**
   * @brief Destructor.
   */
  ~Fixed(void);

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
   * @brief Convert the Fixed object to a floating-point value.
   *
   * @return The floating-point value representation of the Fixed object.
   */
  float toFloat(void) const;

  /**
   * @brief Convert the Fixed object to an integer value.
   *
   * @return The integer value representation of the Fixed object.
   */
  int toInt(void) const;

private:
  int _fixedValue; /**< The raw integer value representing the Fixed object. */
  static const int _raw = 8; /**< The number of fractional bits allocated for the Fixed object. */
};

/**
 * @brief Overloaded stream insertion operator for printing Fixed objects.
 *
 * @param oStream The output stream.
 * @param nbr The Fixed object to print.
 * @return Reference to the output stream.
 */
std::ostream &operator<<(std::ostream &oStream, const Fixed &nbr);

#endif // FIXED_HPP
