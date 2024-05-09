#include "Bureaucrat.hpp"
#include <iostream>

void bureTest() {
  std::cout << std::endl;
  std::cout << RED("Test increment a high grade.") << std::endl;
  {
    try {
      Bureaucrat john("High Grade Bure", 1);
      std::cout << john << std::endl;

      john.incrementGrade();
      std::cout << john << std::endl;

      john.decrementGrade();
      std::cout << john << std::endl;

      // This should throw GradeTooHighException
    } catch (std::exception &e) {
      std::cerr << "Exception: " << e.what() << std::endl;
    }
  }
  std::cout << std::endl;
  std::cout << RED("Test decrement a low grade.") << std::endl;
  {
    try {
      Bureaucrat john("Low Grade Bure", 150);
      std::cout << john << std::endl;

      john.decrementGrade();
      std::cout << john << std::endl;

      john.incrementGrade();
      std::cout << john << std::endl;

      // This should throw GradeTooHighException
    } catch (std::exception &e) {
      std::cerr << "Exception: " << e.what() << std::endl;
    }
  }
  std::cout << std::endl;
  std::cout << RED("Now different grade") << std::endl;
  {
    try {
      Bureaucrat john("Mid Grade", 75);
      std::cout << john << std::endl;

      john.incrementGrade();
      std::cout << john << std::endl;

      john.decrementGrade();
      std::cout << john << std::endl;

      while (john.getGrade() > 42)
        john.incrementGrade();
      std::cout << john << std::endl;

      // This should throw GradeTooHighException
    } catch (std::exception &e) {
      std::cerr << "Exception: " << e.what() << std::endl;
    }
  }
}

int main() {
  bureTest();
  return 0;
}
