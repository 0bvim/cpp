#include "Point.hpp"
#include <cstdlib>
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {
  if (bsp(Point(0, 0), Point(20, 0), Point(10, 30), Point(10, 15)))
    std::cout << "Point is in the triangle" << std::endl;
  else
    std::cout << "Point is not in the triangle" << std::endl;
  return EXIT_SUCCESS;
}
