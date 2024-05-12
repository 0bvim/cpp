#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#define P_SIGN_GRADE 25
#define P_EXEC_GRADE 5

class PresidentialPardonForm : public AForm {
private:
  PresidentialPardonForm();
  std::string _target;

public:
  PresidentialPardonForm(const std::string &targe);
  ~PresidentialPardonForm();
  PresidentialPardonForm(PresidentialPardonForm const &rhs);
  PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

  void execute(const Bureaucrat &executor) const;
};

#endif // PRESIDENTIALPARDONFORM_HPP
