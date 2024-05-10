#ifndef SHRRUBBERYCREATIONFORM_HPP
#define SHRRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrrubberyCreationForm : public AForm {
public:
  ShrrubberyCreationForm(const std::string &target);
  ShrrubberyCreationForm(ShrrubberyCreationForm const &rhs);
  ShrrubberyCreationForm &operator=(ShrrubberyCreationForm const &rhs);
  void execute(const Bureaucrat &executor) const;

private:
  ShrrubberyCreationForm();
};

#endif // !SHRRUBBERYCREATIONFROM_HPP
