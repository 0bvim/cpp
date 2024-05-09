#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void bureTest() {
  std::cout << std::endl;
  std::cout << ("Test increment a high grade.") << std::endl;
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
  std::cout << ("Test decrement a low grade.") << std::endl;
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
  std::cout << ("Now different grade") << std::endl;
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

void formTest(void) {
  std::cout << "=== CREATING A FORM ===" << std::endl;
  {
    Form a("Affidavit", 100, 30);

    std::cout << a << std::endl;
  }
  std::cout << "=== CREATING A LOW GRADE FORM ===" << std::endl;
  {
    try {
      Form a("Affidavit", 151, 30);

      std::cout << a << std::endl;
    } catch (std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  std::cout << "\n=== CREATING A HIGH GRADE FORM ===" << std::endl;
  {
    try {
      Form a("Affidavit", 0, 30);

      std::cout << a << std::endl;
    } catch (std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  std::cout << "\n=== BUREAUCRAT SIGNING A FORM ===" << std::endl;
  {
    Bureaucrat a("Hermes", 50);
    Form b("Visa", 100, 30);

    std::cout << "Bureaucrat: " << a << std::endl;
    std::cout << "Form: " << b << std::endl;
    a.signForm(b);
  }
  std::cout << "\n=== LOW GRADE BUREAUCRAT TRIES TO SIGN A FORM ==="
            << std::endl;
  {
    Bureaucrat a("Hermes", 150);
    Form b("Visa", 100, 30);

    a.signForm(b);
  }
}

int main() {
  bureTest();
  std::cout << std::endl;
  formTest();
  return 0;
}
