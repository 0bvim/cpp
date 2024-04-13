#include <cstdlib>
#include <iostream>
#include <string>

int main(void) {
  std::string msg = "HI THIS IS BRAIN";
  std::string *ptr = &msg;
  std::string &ref = msg;

  std::cout << "Mem address of msg string: " << &msg << std::endl;
  std::cout << "Mem address of ptr string: " << &ptr << std::endl;
  std::cout << "Mem address of ref string: " << &ref << std::endl;

  std::cout << "Value of msg string: " << msg << std::endl;
  std::cout << "Value of ptr string: " << *ptr << std::endl;
  std::cout << "Value of ref string: " << ref << std::endl;

  return EXIT_SUCCESS;
}
