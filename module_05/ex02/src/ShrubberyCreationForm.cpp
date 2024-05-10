#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shruberry Creation Form", SIGN_GRADE, EXEC_GRADE),
      _target("unknow") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shruberry Creation Form", SIGN_GRADE, EXEC_GRADE),
      _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
  if (this != &rhs) {
    AForm::operator=(rhs);
    (std::string &)this->_target = rhs._target;
  }
  return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(
    ShrubberyCreationForm const &rhs)
    : AForm("Shruberry Creation Form", SIGN_GRADE, EXEC_GRADE) {
  *this = rhs;
}
