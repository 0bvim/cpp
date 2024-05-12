#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

#define R_SIGN_GRADE 72
#define R_EXEC_GRADE 45

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential Creation Form", R_SIGN_GRADE, R_EXEC_GRADE),
      _target("unknow") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("Presidential Creation Form", R_SIGN_GRADE, R_EXEC_GRADE),
      _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
  if (this != &rhs) {
    AForm::operator=(rhs);
    (std::string &)this->_target = rhs._target;
  }
  return *this;
}

PresidentialPardonForm::PresidentialPardonForm(
    PresidentialPardonForm const &rhs)
    : AForm("Presidential Creation Form", R_SIGN_GRADE, R_EXEC_GRADE) {
  *this = rhs;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
  if (!this->getSignature())
    throw AForm::FormNotSignedException();

  if (executor.getGrade() > R_EXEC_GRADE)
    throw AForm::GradeTooLowException();

  std::cout << GREEN(this->_target
                     << " has been pardoned by Zaphod Beeblebrox.")
            << std::endl;
}
