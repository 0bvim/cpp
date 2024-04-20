#include "Point.hpp"

Point::Point(void) : _x(0), _y(0){};

Point::Point(const float x, const float y) : _x(x), _y(y){};

Point::Point(const Point &src) { *this = src; };

Point &Point::operator=(const Point &rhs) {
  (Fixed) this->_x = rhs.getX();
  (Fixed) this->_y = rhs.getY();
  return *this;
}

Point::~Point(void){};

Fixed Point::getX(void) const { return this->_x; }

Fixed Point::getY(void) const { return this->_y; }
