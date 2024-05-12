#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(Intern const &rhs) { *this = rhs; }

Intern &Intern::operator=(Intern const &rhs) {
  (void)rhs;
  return *this;
}

const char *Intern::InvalidFormException::what() const throw() {
  return "Invalid form request!";
}

static AForm *robotomyRequest(std::string target) {
  return new RobotomyRequestForm(target);
}

static AForm *shrubberyRequest(std::string target) {
  return new ShrubberyCreationForm(target);
}

static AForm *presidentialRequest(std::string target) {
  return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target) {
  std::string names[3] = {"robotomy request", "shrubbery creation",
                          "presidential pardon"};

  AForm *(*fun[3])(std::string target) = {&robotomyRequest, &shrubberyRequest,
                                          &presidentialRequest};

  for (int i = 0; i < 3; ++i) {
    if (!names[i].compare(name))
      return fun[i](target);
  }
  throw Intern::InvalidFormException();
  return (NULL);
}
