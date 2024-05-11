#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <iostream>

#define GOLDEN(text) "\033[1;33m" text "\033[0m"
#define R_SIGN_GRADE 72
#define R_EXEC_GRADE 45

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Creation Form", R_SIGN_GRADE, R_EXEC_GRADE),
      _target("unknow") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Robotomy Creation Form", R_SIGN_GRADE, R_EXEC_GRADE),
      _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
  if (this != &rhs) {
    AForm::operator=(rhs);
    (std::string &)this->_target = rhs._target;
  }
  return *this;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &rhs)
    : AForm("Shruberry Creation Form", R_SIGN_GRADE, R_EXEC_GRADE) {
  *this = rhs;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
  if (!this->getSignature())
    throw AForm::FormNotSignedException();

  if (executor.getGrade() > R_EXEC_GRADE)
    throw AForm::GradeTooLowException();

  std::cout << GOLDEN("Whirrr...zzzz...clink...zzzz...whirrr...") << std::endl;
  if ((rand() + clock()) % 2 == 0) {
    std::cout << GOLDEN("Hey hey, look! " << this->_target
                                          << " was sucessfully robotomized")
              << std::endl;
  } else {
    std::cout << RED("Oh no... " << this->_target << " robotomization failed")
              << std::endl;
  }
}
