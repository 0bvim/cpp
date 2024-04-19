#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed {
public:
  /* canoncical */
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

private:
  int _fixedValue;
  static const int _raw = 8;
};

std::ostream &operator<<(std::ostream &oStream, const Fixed &nbr);

#endif // FIXED_HPP
