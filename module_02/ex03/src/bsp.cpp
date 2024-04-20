#include "Point.hpp"

static Fixed abs(Fixed x) {
  if (x < 0)
    return x * -1;
  return x;
}

static Fixed triangleArea(Point const A, Point const B, Point const C) {
  return (abs((A.getX() * (B.getY() - C.getY()) +
							B.getX() * (C.getY() - A.getY()) +
              C.getX() * (A.getY() - B.getY())) / (float)2.0));
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  Fixed abc = triangleArea(a, b, c);
  Fixed pbc = triangleArea(point, b, c);
  Fixed pac = triangleArea(a, point, c);
  Fixed pab = triangleArea(a, b, point);

  if (pab == 0 || pbc == 0 || pac == 0)
    return false;
  return (abc == (pbc + pac + pab));
}
