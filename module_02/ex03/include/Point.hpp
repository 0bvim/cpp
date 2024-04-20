#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
public:
  Point(void);
  Point(const float x, const float y);
  Point(const Point &src);
  Point &operator=(const Point &rhs);
  ~Point(void);

  Fixed getX(void) const;
  Fixed getY(void) const;

private:
  Fixed const _x;
  Fixed const _y;
};

#endif // POINT_HPP
