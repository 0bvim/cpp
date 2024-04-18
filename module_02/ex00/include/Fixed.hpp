#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
public:
  Fixed(void);
  Fixed(int const n);
  Fixed(Fixed const &src);
  Fixed &operator=(Fixed const &rhs);

  ~Fixed(void);

private:
  int _fixedValue;
  static const int raw;
};

#endif // FIXED_HPP
