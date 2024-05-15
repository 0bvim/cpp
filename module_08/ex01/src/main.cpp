#include "Defines.hpp"
#include "Span.hpp"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <iostream>

// Helper function to generate random numbers
int generateRandomNumber(int min, int max) {
  return min + rand() % (max - min + 1);
}

int main() {
  try {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(NULL)));

    // Create a Span object with a maximum size of 10
    Span span(10);

    // Add some numbers
    span.addNumber(3);
    span.addNumber(7);
    span.addNumber(2);
    span.addNumber(9);
    span.addNumber(1);
    span.addNumber(4);
    span.addNumber(8);
    span.addNumber(6);
    span.addNumber(5);
    span.addNumber(10);

    // Test shortest span
    std::cout << "Shortest span: " << span.shortestSpan() << std::endl;

    // Test longest span
    std::cout << "Longest span: " << span.longestSpan() << std::endl;

    // Test adding a number to a full Span
    std::cout << "Attempting to add a number to a full Span..." << std::endl;
    span.addNumber(11); // This should throw an exception
  } catch (const std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  // Additional testing with larger dataset
  try {
    std::cout << "\nAdditional Testing with Larger Dataset:\n";

    // Create a Span object with a maximum size of 10000
    Span largeSpan(10000);

    // Fill the large span with random numbers
    for (int i = 0; i < 10000; ++i) {
      largeSpan.addNumber(generateRandomNumber(1, 1000000));
    }

    // Test shortest span
    std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;

    // Test longest span
    std::cout << "Longest span: " << largeSpan.longestSpan() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
