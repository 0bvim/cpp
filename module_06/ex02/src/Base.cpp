#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "D.hpp"
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

Base::~Base() {}

Base *generate() {
  static bool first = true;

  if (first) {
    srand(time(NULL));
    first = false;
  }
  int choice = rand() % 4;
  switch (choice) {
  case 0:
    return new A();
  case 1:
    return new B();
  case 2:
    return new C();
  case 3:
    return new D();
  }
  return NULL;
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << "C" << std::endl;
  else {
    std::cerr << "error: bad casting!" << std::endl;
  }
}

void identify(Base &p) {
  try {
    A a = dynamic_cast<A &>(p);

    std::cout << "A" << std::endl;
    return;
  } catch (std::exception &e) {
    try {
      B b = dynamic_cast<B &>(p);

      std::cout << "B" << std::endl;
      return;
    } catch (std::exception &e) {
      try {
        C c = dynamic_cast<C &>(p);

        std::cout << "C" << std::endl;
        return;
      } catch (std::exception &e) {
        std::cerr << "error: bad casting!" << std::endl;
        return;
      }
    }
  }
  return;
}
