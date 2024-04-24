#include "Point.hpp"
#include <cstdlib>
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

void test1(void) {
  if (bsp(Point(0, 0), Point(10, 30), Point(20, 0), Point(10, 15)))
    std::cout << "Point is in the triangle" << std::endl;
  else
    std::cout << "Point is not in the triangle" << std::endl;
}

void test2(void) {
  if (bsp(Point(0, 0), Point(10, 30), Point(20, 0), Point(30, 15)))
    std::cout << "Point is in the triangle" << std::endl;
  else
    std::cout << "Point is not in the triangle" << std::endl;
}

int main(void) {
  test1();
  test2();

  return EXIT_SUCCESS;
}
