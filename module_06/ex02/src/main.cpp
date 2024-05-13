#include "Base.hpp"
#include "Defines.hpp"
#include <iostream>
#define NL std::cout << std::endl

int main(void) {

  std::cout << BLUE("===STARTING TESTS===") << std::endl;

  for (int i = 0; i < 10; ++i) {
    std::cout << GREEN("===GENERATING BASE=== " << i + 1) << std::endl;
    NL;
    Base *ptr = generate();
    std::cout << RED("===POINTER TEST===") << std::endl;
    identify(ptr);
    std::cout << RED("===REFERENCE TEST===") << std::endl;
    identify(*ptr);
    NL;

    delete ptr;
  }

  return 0;
}
