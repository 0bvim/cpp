#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shruberry Creation Form", S_SIGN_GRADE, S_EXEC_GRADE),
      _target("unknow") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shruberry Creation Form", S_SIGN_GRADE, S_EXEC_GRADE),
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

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &rhs)
    : AForm("Shruberry Creation Form", S_SIGN_GRADE, S_EXEC_GRADE) {
  *this = rhs;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
  if (!this->getSignature())
    throw AForm::FormNotSignedException();

  if (executor.getGrade() > S_EXEC_GRADE)
    throw AForm::GradeTooLowException();

  const std::string file_name = this->_target + "_shrubberry";

  if (std::ifstream(file_name.c_str()))
    throw ShrubberyCreationForm::FileAlreadyExistException();

  std::ofstream out(file_name.c_str());
  if (!out)
    throw ShrubberyCreationForm::FailedToOpenException();

  out << ASCII_TRESS << std::endl;
}
