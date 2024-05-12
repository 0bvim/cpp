#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#define SIGN_GRADE 72
#define EXEC_GRADE 45

class RobotomyRequestForm : public AForm {
private:
  RobotomyRequestForm();
  std::string _target;

public:
  RobotomyRequestForm(const std::string &target);
  ~RobotomyRequestForm();
  RobotomyRequestForm(RobotomyRequestForm const &rhs);
  RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

  void execute(const Bureaucrat &executor) const;
};

#endif // ROBOTOMYREQUESTFORM_HPP
