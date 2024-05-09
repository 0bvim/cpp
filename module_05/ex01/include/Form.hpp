#ifndef FORM_HPP
#define FORM_HPP
#include <string>

class Bureaucrat; // Forward declaration

class Form {
private:
  Form();

  const std::string _name;
  bool _signed;
  const int _gradeToSign;
  const int _gradeToExecute;

public:
  Form(const std::string &name, int gradeToSign, int gradeToExecute);
  ~Form();
  Form(Form const &rhs);
  Form &operator=(Form const &rhs);

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  std::string getName() const;
  bool getSignature() const;
  int getSignGrade() const;
  int getExecuteGrade() const;

  bool beSigned(Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &os, Form const &rhs);

#endif // !FORM_HPP
