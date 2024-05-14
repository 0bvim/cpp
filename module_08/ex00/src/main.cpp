#include "Defines.hpp"
#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

int main() {
  NL;
  std::cout << GREEN("Starting tests with vector") << std::endl;
  try {
    std::vector<int> vec;
    for (int i = 1; i <= 10; ++i) {
      std::cout << YELLOW("Adding to vector value: " << i) << std::endl;
      vec.push_back(i);
    }
    NL;

    std::cout << GREEN("Trying to find number 3 in vector") << std::endl;
    std::vector<int>::iterator it = easyfind(vec, 3);
    std::cout << MAGENTA("Found in vector: ") << *it << std::endl;
    NL;

    std::cout << GREEN("Trying to find number 42 in vector") << std::endl;
    it = easyfind(vec, 42); // This should throw an exception
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  NL;
  std::cout << GREEN("Starting tests with list") << std::endl;
  try {
    std::list<int> lst;
    for (int i = 1; i < 10; ++i) {
      std::cout << YELLOW("Adding to list value: " << (i * 10)) << std::endl;
      lst.push_back(i * 10);
    }
    NL;
    std::cout << GREEN("Trying to find number 30 in list") << std::endl;
    std::list<int>::iterator it = easyfind(lst, 30);
    std::cout << MAGENTA("Found in list: ") << *it << std::endl;
    NL;

    std::cout << GREEN("Trying to find number 100 in list") << std::endl;
    it = easyfind(lst, 100); // This should throw an exception
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
