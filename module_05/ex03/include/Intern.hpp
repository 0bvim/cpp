#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <exception>

class Intern {
public:
  class InvalidFormException : public std::exception {
  public:
    const char *what() const throw();
  };

  Intern();
  ~Intern();
  Intern(Intern const &rhs);
  Intern &operator=(Intern const &rhs);

  AForm *makeForm(std::string name, std::string target);
};

#endif // INTERN_HPP
