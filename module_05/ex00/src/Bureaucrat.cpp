#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : _name(name), _grade(grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const &rhs) { *this = rhs; }

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
  if (this != &rhs) {
    this->_grade = rhs._grade;
    const_cast<std::string &>(this->_name) = rhs._name;
  }
  return *this;
}

std::string Bureaucrat::getName() const { return this->_name; }

int Bureaucrat::getGrade() const { return this->_grade; }

void Bureaucrat::incrementGrade() {
  if (this->_grade == 1) {
    std::cout << "This Bureaucrat are at the highest grade." << std::endl;
    return;
  }
  this->_grade--;
  std::cout << "Grade of this Bureaucrat now are " << this->_grade << std::endl;
}

void Bureaucrat::decrementGrade() { 
  if (this->_grade == 150) {
    std::cout << "This Bureaucrat are at the lowest grade." << std::endl;
    return;
  }
  this->_grade++;
  std::cout << "Grade of this Bureaucrat now are " << this->_grade << std::endl;
}
