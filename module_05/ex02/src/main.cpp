#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

void shruberryTests() {
  /* ShrubberyCreationForm tests */
  std::cout << GREEN("==== SHRUBBERY CREATION FORM TESTS ====") << std::endl;
  std::cout << GREEN("\n=== LOW GRADE TO SIGN FORM ===") << std::endl;
  {
    AForm *a = new ShrubberyCreationForm("home");
    Bureaucrat b("Hermes", 150);

    b.signForm(*a);
    b.executeForm(*a);

    delete a;
  }
  std::cout << GREEN("\n=== LOW GRADE TO EXECUTE FORM ===") << std::endl;
  {
    AForm *a = new ShrubberyCreationForm("home");
    Bureaucrat b("Hermes", 140);

    b.signForm(*a);
    b.executeForm(*a);

    delete a;
  }
  std::cout << GREEN("\n=== CREATING A SHRUBBERY CREATION FORM ===")
            << std::endl;
  {
    AForm *a = new ShrubberyCreationForm("home");
    Bureaucrat b("Hermes", 130);
    Bureaucrat c("Mercury", 1);

    b.signForm(*a);
    b.executeForm(*a);

    delete a;
  }
}

void robotomyTests() {
  /* RobotomyRequestForm tests */
  std::cout << GREEN("\n\n==== ROBOTOMY REQUEST FORM TESTS ====") << std::endl;
  std::cout << GREEN("\n== LOW GRADE TO SIGN FORM ===") << std::endl;
  {
    AForm *a = new RobotomyRequestForm("home");
    Bureaucrat b("Hermes", 73);

    b.signForm(*a); // Grade should be equal or higher than 72!
    b.executeForm(*a);

    delete a;
  }
  std::cout << GREEN("\n=== LOW GRADE TO EXECUTE FORM ===") << std::endl;
  {
    AForm *a = new RobotomyRequestForm("home");
    Bureaucrat b("Hermes", 48);

    b.signForm(*a);
    b.executeForm(*a); // Grade should be equal or higher than 45!

    delete a;
  }
  std::cout << GREEN("\n=== CREATING A ROBOTOMY REQUEST FORM ===") << std::endl;
  {
    AForm *a = new RobotomyRequestForm("Arthur");
    Bureaucrat b("Hermes", 42);
    Bureaucrat c("Mercury", 5);

    b.signForm(*a);
    c.executeForm(*a);
    delete a;
  }
}

void presidentialTests() {
  /* PresidentialPardonForm tests */
  std::cout << GREEN("\n\n==== PRESIDENTIAL REQUEST FORM TESTS ====")
            << std::endl;
  std::cout << GREEN("\n== LOW GRADE TO SIGN FORM ===") << std::endl;
  {
    AForm *a = new PresidentialPardonForm("Renato");
    Bureaucrat b("Hermes", 73);

    b.signForm(*a);
    b.executeForm(*a);

    delete a;
  }
  std::cout << GREEN("\n=== LOW GRADE TO EXECUTE FORM ===") << std::endl;
  {
    AForm *a = new PresidentialPardonForm("pardon");
    Bureaucrat b("Hermes", 48);

    b.signForm(*a);
    b.executeForm(*a);

    delete a;
  }
  std::cout << GREEN("\n=== CREATING A PRESIDENTIAL REQUEST FORM ===")
            << std::endl;
  {
    AForm *a = new PresidentialPardonForm("James");
    Bureaucrat b("Fred", 42);
    Bureaucrat c("Mercury", 5);

    b.signForm(*a);
    c.executeForm(*a);

    delete a;
  }
}

int main(void) {
  shruberryTests();
  robotomyTests();
  presidentialTests();

  return (0);
}
