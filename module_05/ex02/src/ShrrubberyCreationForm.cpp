#include "ShrrubberyCreationForm.hpp"

ShrrubberyCreationForm::ShrrubberyCreationForm()
    : AForm("Shruberry Creation Form", SIGN_GRADE, EXEC_GRADE),
      _target("unknow") {}

ShrrubberyCreationForm::ShrrubberyCreationForm(const std::string &target)
    : AForm("Shruberry Creation Form", SIGN_GRADE, EXEC_GRADE),
      _target(target) {}

ShrrubberyCreationForm::~ShrrubberyCreationForm() {}

ShrrubberyCreationForm &
ShrrubberyCreationForm::operator=(ShrrubberyCreationForm const &rhs) {
  if (this != &rhs) {
    AForm::operator=(rhs);
    (std::string &)this->_target = rhs._target;
  }
  return *this;
}

ShrrubberyCreationForm::ShrrubberyCreationForm(
    ShrrubberyCreationForm const &rhs)
    : AForm("Shruberry Creation Form", SIGN_GRADE, EXEC_GRADE) {
  *this = rhs;
}
