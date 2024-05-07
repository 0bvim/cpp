#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>

class Bureaucrat {
private:
  const std::string _name;
  int _grade;

public:
  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade is too high"; }
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade is too low"; }
  };

  Bureaucrat(const std::string &name, int grade);
  ~Bureaucrat();
  Bureaucrat(Bureaucrat const &rhs);
  Bureaucrat operator=(Bureaucrat const &rhs);

  std::string getName() const;
  int getGrade() const;

  void incrementGrade();
  void decrementGrade();
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);

#endif // BUREAUCRAT_HPP
