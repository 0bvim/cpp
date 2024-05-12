#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
  Intern someRandomIntern;
  AForm *tmp;

  std::cout << GREEN("\nROBOTOMY REQUEST") << std::endl;
  try {
    tmp = someRandomIntern.makeForm("robotomy request", "Bender");
    if (tmp) {
      std::cout << GREEN("Form created successfully!") << std::endl;
      delete tmp;
    }
  } catch (Intern::InvalidFormException &e) {
    std::cout << YELLOW("Form not found!") << std::endl;
  }

  std::cout << GREEN("\nSHRUBBERY CREATION") << std::endl;
  try {
    tmp = someRandomIntern.makeForm("shrubbery creation", "Downtown");
    if (tmp) {
      std::cout << GREEN("Form created successfully!") << std::endl;
      delete tmp;
    }
  } catch (Intern::InvalidFormException &e) {
    std::cout << YELLOW("Form not found!") << std::endl;
  }

  std::cout << GREEN("\nPRESIDENTIAL PARDON") << std::endl;
  try {
    tmp =
        someRandomIntern.makeForm("presidential pardon", "corrupt politician");
    if (tmp) {
      std::cout << GREEN("Form created successfully!") << std::endl;
      delete tmp;
    }
  } catch (Intern::InvalidFormException &e) {
    std::cout << YELLOW("Form not found!") << std::endl;
  }

  std::cout << GREEN("\nTAX EXEMPTION") << std::endl;
  try {
    tmp = someRandomIntern.makeForm("tax exemption", "Bruno Moretti");
    if (tmp) {
      std::cout << GREEN("Form created successfully!") << std::endl;
      delete tmp;
    }
  } catch (Intern::InvalidFormException &e) {
    std::cout << YELLOW("Form not found!") << std::endl;
  }

  std::cout << std::endl;

  return 0;
}
