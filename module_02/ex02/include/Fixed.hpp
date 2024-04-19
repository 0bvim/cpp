#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed {
public:
  /* default constructor */
  Fixed(void);
  Fixed(const int iraw);
  Fixed(const float fraw);
  Fixed(Fixed const &src);
  Fixed &operator=(Fixed const &rhs);
  ~Fixed(void);

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

  /* comparison operators */
  bool operator>(const Fixed &nbr);
  bool operator<(const Fixed &nbr);
  bool operator<=(const Fixed &nbr);
  bool operator>=(const Fixed &nbr);
  bool operator==(const Fixed &nbr);
  bool operator!=(const Fixed &nbr);

  /* arithmetic operator */
  Fixed operator+(const Fixed &nbr);
  Fixed operator-(const Fixed &nbr);
  Fixed operator*(const Fixed &nbr);
  Fixed operator/(const Fixed &nbr);

  /* increment and decrement */
  Fixed &operator++(void);
  Fixed operator++(int);
  Fixed &operator--(void);
  Fixed operator--(int);


  static Fixed &min(Fixed &a, Fixed &b);
  static const Fixed &min(const Fixed &a, const Fixed &b);
  static Fixed &max(Fixed &a, Fixed &b);
  static const Fixed &max(const Fixed &a, const Fixed &b);

private:
  int _fixedValue;
  static const int _raw = 8;
};

std::ostream &operator<<(std::ostream &oStream, const Fixed &nbr);

#endif // FIXED_HPP
