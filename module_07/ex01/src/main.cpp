#include "Defines.hpp"
#include "iter.hpp"
#include <iostream>

int main(void) {
  int nbs[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 9};
  char letter[] = {'f', 't', '*', 'w', 'h', 'y'};

  std::cout << GREEN("Printing numbers: ");
  ::iter(nbs, 12, ::print<int>);
  NL;

  std::cout << GREEN("Printing chars: ");
  ::iter(letter, 6, ::print<char>);
  NL;

  std::cout << GREEN("Increment int values: ");
  ::iter(nbs, 12, ::increment<int>);
  NL;

  std::cout << GREEN("Increment char values: ");
  ::iter(letter, 6, ::increment<char>);
  NL;

  NL;
  std::cout << GREEN("Odd or Even int values: ") << std::endl;
  ::iter(nbs, 12, ::oddEven<int>);
  NL;

  std::cout << GREEN("Odd or Even char values: ") << std::endl;
  ::iter(letter, 6, ::oddEven<char>);
  NL;

  return 0;
}
