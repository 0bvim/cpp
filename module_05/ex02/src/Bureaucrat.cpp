#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>
#include <iostream>
#include <ostream>

Bureaucrat::Bureaucrat() : _name("not set"), _grade(0) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) {
  if (grade > 150)
    throw GradeTooHighException();
  else if (grade < 1)
    throw GradeTooHighException();
  _grade = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs) { *this = rhs; }

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
  if (this != &rhs) {
    this->_grade = rhs._grade;
    const_cast<std::string &>(this->_name) = rhs._name;
  }
  return *this;
}

std::string Bureaucrat::getName() const { return this->_name; }

int Bureaucrat::getGrade() const { return this->_grade; }

void Bureaucrat::signForm(AForm &f) {
  try {
    f.beSigned(*this);
    std::cout << RED(this->_name) << " signed " << f.getName() << std::endl;
  } catch (AForm::GradeTooLowException &e) {
    std::cout << RED(_name) << " couldn't sign " << f.getName()
              << " because: " << e.what() << std::endl;
  }
}

void Bureaucrat::executeForm(AForm const &form) {
  try {
    form.execute(*this);
    std::cout << _name << " executed " << form.getName() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << _name << " couldn't execute " << form.getName() << " because "
              << e.what() << std::endl;
  }
}

void Bureaucrat::incrementGrade() {
  if (this->_grade > 1) {
    this->_grade--;
  } else {
    throw GradeTooHighException();
  }
}

void Bureaucrat::decrementGrade() {
  if (this->_grade < 150) {
    this->_grade++;
  } else {
    throw GradeTooLowException();
  }
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
  return os;
}
