#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
public:
  Fixed(void);
  Fixed(int const n);
  Fixed(Fixed const &src);
  Fixed &operator=(Fixed const &rhs);

	int getRawBits(void) const;
	void setRawBits(int const raw);
  ~Fixed(void);

private:
  int _fixedValue;
  static const int _raw = 8;
};

#endif // FIXED_HPP
