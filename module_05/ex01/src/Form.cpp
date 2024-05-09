#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form()
    : _name("Another form in the stack"), _signed(false), _gradeToSign(150),
      _gradeToExecute(150) {}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
  if (gradeToSign < 1 || gradeToExecute < 1)
    throw GradeTooHighException();
  else if (gradeToSign > 150 || gradeToExecute > 150)
    throw GradeTooLowException();
}

Form::~Form() {}

Form::Form(Form const &rhs)
    : _name(rhs._name), _signed(rhs._signed), _gradeToSign(rhs._gradeToSign),
      _gradeToExecute(rhs._gradeToExecute) {
  *this = rhs;
}

Form &Form::operator=(Form const &rhs) {
  (std::string &)this->_name = rhs.getName();
  (int &)this->_gradeToSign = rhs.getSignGrade();
  (int &)this->_gradeToExecute = rhs.getExecuteGrade();
  this->_signed = rhs.getSignature();
  return *this;
}

const char *Form::GradeTooHighException::what(void) const throw() {
  return "Form: GradeTooHighException";
}

const char *Form::GradeTooLowException::what(void) const throw() {
  return "Form: GradeTooLowException";
}

std::string Form::getName() const { return this->_name; }
bool Form::getSignature() const { return this->_signed; }
int Form::getSignGrade() const { return this->_gradeToSign; }
int Form::getExecuteGrade() const { return this->_gradeToExecute; }

bool Form::beSigned(Bureaucrat &bure) {
  if (bure.getGrade() <= this->getSignGrade()) {
    this->_signed = true;
    return true;
  } else {
    throw Form::GradeTooLowException();
  }
  return false;
}

std::ostream &operator<<(std::ostream &os, Form const &rhs) {
  os << RED(rhs.getName()) << " sign request."
     << RED(" Grade to sign: " << rhs.getSignGrade())
     << RED(". Grade to execute: " << rhs.getExecuteGrade())
                                 << RED(". Is signed: " << (rhs.getSignature() == 1 ? "Yes" : "No"));
  return os;
}
