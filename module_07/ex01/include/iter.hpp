#ifndef ITER_HPP
#define ITER_HPP

#include "Defines.hpp"
#include <cstddef>
#include <iostream>

template <typename T, typename F>
void iter(T *array, size_t lenght, F function) {
  if (!function || !array)
    return;
  for (size_t i = 0; i < lenght; ++i)
    function(*(array + i));
}

template <typename T> void print(const T &val) { std::cout << YELLOW(val); }

template <typename T> void increment(T &val) {
  val += 1;
  std::cout << YELLOW(val);
}

template <typename T> void oddEven(T const &val) {
  std::cout << YELLOW(val << (val % 2 == 0 ? " Even" : " Odd")) << std::endl;
}

#endif // ITER_HPP
