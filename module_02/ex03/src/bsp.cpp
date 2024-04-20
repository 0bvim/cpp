#include "Point.hpp"

static Fixed abs(Fixed x) {
  if (x < 0)
    return x * -1;
  return x;
}

static Fixed triangleArea(Point const p1, Point const p2, Point const p3) {
  return (abs((p1.getX() * (p2.getY() - p3.getY()) +
               (p2.getX() * (p3.getY() - p1.getY())) +
               (p3.getX() * (p1.getY() - p2.getY()))) /
              (float)2.0));
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  Fixed abc = triangleArea(a, b, c);
  Fixed pab = triangleArea(point, a, b);
  Fixed pbc = triangleArea(point, b, c);
  Fixed pca = triangleArea(point, c, a);

  if (pab == 0 || pbc == 0 || pca == 0)
    return false;
  return (pab == pbc) && (pbc == pca);
}
