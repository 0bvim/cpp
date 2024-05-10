#ifndef SHRRUBBERYCREATIONFORM_HPP
#define SHRRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <exception>
#define ASCII_TRESS                                                            \
  "               ,@@@@@@@,\n"                                                 \
  "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"                                     \
  "    ,&%%&%&&%,@@@@@/@@@@@@,8888\88/8o\n"                                    \
  "   ,%&\%&&%&&%,@@@\@@@/@@@88\88888/88'\n"                                   \
  "   %&&%&%&/%&&%@@\@@/ /@@@88888\88888'\n"                                   \
  "   %&&%/ %&%%&&@@\ V /@@' `88\8 `/88'\n"                                    \
  "   `&%\ ` /%&'    |.|        \ '|8'\n"                                      \
  "       |o|        | |         | |\n"                                        \
  "       |.|        | |         | |\n"                                        \
  "    \\/ ._\//_/__/  ,\_//__\\/.  \_//__/_"

#define SIGN_GRADE 145
#define EXEC_GRADE 137

class ShrrubberyCreationForm : public AForm {
private:
  ShrrubberyCreationForm();
  std::string _target;

public:
  ShrrubberyCreationForm(const std::string &target);
  ~ShrrubberyCreationForm();
  ShrrubberyCreationForm(ShrrubberyCreationForm const &rhs);
  ShrrubberyCreationForm &operator=(ShrrubberyCreationForm const &rhs);

  void execute(const Bureaucrat &executor) const;

  class FileAlreadyExistException : public std::exception {
  public:
    virtual const char *what() const throw() { return "File already exists."; }
  };

  class FailedToOpenException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Failed opening file"; }
  };
};

#endif // !SHRRUBBERYCREATIONFROM_HPP
