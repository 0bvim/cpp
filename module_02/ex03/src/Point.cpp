#include "Point.hpp"

Point::Point(void) : _x(Fixed()), _y(Fixed()){};

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)){};

Point::Point(const Point &src) { *this = src; };

Point &Point::operator=(const Point &rhs) {
  (Fixed &)this->_x = rhs.getX();
  (Fixed &)this->_y = rhs.getY();
  return *this;
}

Point::~Point(void){};

Fixed Point::getX(void) const { return this->_x; }

Fixed Point::getY(void) const { return this->_y; }
