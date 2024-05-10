#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm()
    : _name("Another Aform in the stack"), _signed(false), _gradeToSign(150),
      _gradeToExecute(150) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
  if (gradeToSign < 1 || gradeToExecute < 1)
    throw GradeTooHighException();
  else if (gradeToSign > 150 || gradeToExecute > 150)
    throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(AForm const &rhs)
    : _name(rhs._name), _signed(rhs._signed), _gradeToSign(rhs._gradeToSign),
      _gradeToExecute(rhs._gradeToExecute) {
  *this = rhs;
}

AForm &AForm::operator=(AForm const &rhs) {
  (std::string &)this->_name = rhs.getName();
  (int &)this->_gradeToSign = rhs.getSignGrade();
  (int &)this->_gradeToExecute = rhs.getExecuteGrade();
  this->_signed = rhs.getSignature();
  return *this;
}

const char *AForm::GradeTooHighException::what(void) const throw() {
  return "AForm: GradeTooHighException";
}

const char *AForm::GradeTooLowException::what(void) const throw() {
  return "AForm: GradeTooLowException";
}

std::string AForm::getName() const { return this->_name; }
bool AForm::getSignature() const { return this->_signed; }
int AForm::getSignGrade() const { return this->_gradeToSign; }
int AForm::getExecuteGrade() const { return this->_gradeToExecute; }

bool AForm::beSigned(Bureaucrat &bure) {
  if (bure.getGrade() <= this->getSignGrade()) {
    this->_signed = true;
    return true;
  } else {
    throw AForm::GradeTooLowException();
  }
  return false;
}

std::ostream &operator<<(std::ostream &os, AForm const &rhs) {
  os << RED(rhs.getName()) << " sign request."
     << RED(" Grade to sign: " << rhs.getSignGrade())
     << RED(". Grade to execute: " << rhs.getExecuteGrade())
                                 << RED(". Is signed: " << (rhs.getSignature() == 1 ? "Yes" : "No"));
  return os;
}
