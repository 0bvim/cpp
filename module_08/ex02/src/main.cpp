#include "Defines.hpp"
#include "Span.hpp"
#include <climits>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <exception>
#include <iostream>
#include <vector>

// Helper function to generate random numbers
int generateRandomNumber(int min, int max) {
  return min + rand() % (max - min + 1);
}

int main() {
  try {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(NULL)));

    NL;
    // Create a Span object with a maximum size of 10
    std::cout << GREEN("Creating a vector with 10 positions") << std::endl;
    Span span(10);

    // Add some numbers
    int nbs[] = {3, 7, 2, 9, 1, 4, 8, 6, 5, 10};
    for (int i = 0; i < 10; ++i) {
      std::cout << YELLOW("Adding number " << nbs[i] << " to Span")
                << std::endl;
      span.addNumber(nbs[i]);
    }

    NL;
    // Test shortest span
    std::cout << GREEN("Shortest span: ") << span.shortestSpan() << std::endl;

    // Test longest span
    std::cout << GREEN("Longest span: ") << span.longestSpan() << std::endl;

    NL;
    // Test adding a number to a full Span
    std::cout << RED("Attempting to add a number to a full Span...")
              << std::endl;
    std::cout << MAGENTA("Trying to add number 11 to span.") << std::endl;
    span.addNumber(11); // This should throw an exception
  } catch (const std::exception &e) {
    std::cerr << RED("Exception: ") << e.what() << std::endl;
  }

  // Additional testing with larger dataset
  try {
    std::cout << GREEN("\nAdditional Testing with Larger Dataset:\n");

    // Create a Span object with a maximum size of 10000
    std::cout << YELLOW("Creating a large span with 10000 positions")
              << std::endl;
    Span largeSpan(10000);

    // Fill the large span with random numbers
    std::cout << MAGENTA("Adding a randon numbers to the vector") << std::endl;
    for (int i = 0; i < 10000; ++i) {
      largeSpan.addNumber(generateRandomNumber(1, 1000000));
    }
    NL;

    // Test shortest span
    std::cout << GREEN("Shortest span: ") << largeSpan.shortestSpan()
              << std::endl;

    // Test longest span
    std::cout << GREEN("Longest span: ") << largeSpan.longestSpan()
              << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  NL;

  {
    try {
      std::cout << GREEN("Testing my function to add a range numbers")
                << std::endl;

      std::cout << YELLOW("Creating a vector of integers") << std::endl;
      std::vector<int> numbs(10);
      for (int i = 0; i < 10; ++i) {
        numbs.push_back(generateRandomNumber(0, 100));
      }
      Span lastSpan(100);
      std::cout << "numbs size " << numbs.size() << std::endl;
      lastSpan.addRange(numbs.begin(), numbs.end());
      NL;
      std::cout << GREEN("Shortest span: ") << lastSpan.shortestSpan()
                << std::endl;

      // Test longest span
      std::cout << GREEN("Longest span: ") << lastSpan.longestSpan()
                << std::endl;
    } catch (const std::exception &e) {
      std::cerr << "Exception: " << e.what() << std::endl;
    }
  }
  return 0;
}
