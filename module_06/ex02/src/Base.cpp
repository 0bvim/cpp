#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstddef>
#include <cstdlib>
#include <ctime>

Base::~Base() {}

Base *generate() {
  srand(time(NULL));
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
