#include "Array.hpp"
#include "Defines.hpp"
#include <iostream>

int main() {
  // Test default constructor
  std::cout << GREEN("Testing default constructor:") << std::endl;
  Array<int> arr1;
  std::cout << YELLOW("arr1 size: ") << arr1.size() << std::endl; // Expected: 0

  // Test constructor with size
  std::cout << GREEN("\nTesting constructor with size:") << std::endl;
  unsigned int n = 5;
  Array<int> arr2(n);
  std::cout << YELLOW("arr2 size: ") << arr2.size() << std::endl; // Expected: 5
  for (std::size_t i = 0; i < arr2.size(); ++i) {
    std::cout << MAGENTA("arr2[" << i << "] = ") << arr2[i]
              << std::endl; // Expected: 0 (default initialization)
  }

  // Test copy constructor
  std::cout << GREEN("\nTesting copy constructor:") << std::endl;
  Array<int> arr3(arr2);
  std::cout << YELLOW("arr3 size: ") << arr3.size() << std::endl; // Expected: 5
  for (std::size_t i = 0; i < arr3.size(); ++i) {
    std::cout << MAGENTA("arr3[" << i << "] = ") << arr3[i]
              << std::endl; // Expected: 0
  }

  // Test assignment operator
  std::cout << GREEN("\nTesting assignment operator:") << std::endl;
  Array<int> arr4;
  arr4 = arr2;
  std::cout << YELLOW("arr4 size: ") << arr4.size() << std::endl; // Expected: 5
  for (std::size_t i = 0; i < arr4.size(); ++i) {
    std::cout << MAGENTA("arr4[" << i << "] = ") << arr4[i]
              << std::endl; // Expected: 0
  }

  // Test modifying one array does not affect the copied array
  std::cout
      << GREEN(
             "\nTesting modifying one array does not affect the copied array:")
      << std::endl;
  arr2[0] = 42;
  std::cout << MAGENTA("arr2[0] = ") << arr2[0] << std::endl; // Expected: 42
  std::cout << MAGENTA("arr3[0] = ") << arr3[0] << std::endl; // Expected: 0

  // Test out-of-bounds access
  std::cout << GREEN("\nTesting out-of-bounds access:") << std::endl;
  try {
    std::cout << YELLOW(arr2[10]) << std::endl; // Should throw an exception
  } catch (const std::out_of_range &e) {
    std::cerr << RED("Exception caught: ") << e.what()
              << std::endl; // Expected: out_of_range exception
  }

  // Test const array
  std::cout << GREEN("\nTesting const array:") << std::endl;
  const Array<int> arr5(3);

  std::cout << YELLOW("arr5 size: ") << arr5.size() << std::endl; // Expected: 3
  for (std::size_t i = 0; i < arr5.size(); ++i) {
    std::cout << MAGENTA("arr5[" << i << "] = ") << arr5[i]
              << std::endl; // Expected: 0
  }

  return 0;
}
