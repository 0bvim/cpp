#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>

Base::~Base() {}

Base *generate() {
  static bool first = true;

  if (first) {
    srand(time(NULL));
    first = false;
  }
  int choice = rand() % 3;
  switch (choice) {
  case 0:
    return new A();
  case 1:
    return new B();
  case 2:
    return new C();
  }
  return NULL;
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p))
    std::cout << "A" << std::endl;
  if (dynamic_cast<B *>(p))
    std::cout << "B" << std::endl;
  if (dynamic_cast<C *>(p))
    std::cout << "C" << std::endl;
}

void identify(Base &p) { identify(&p); }
