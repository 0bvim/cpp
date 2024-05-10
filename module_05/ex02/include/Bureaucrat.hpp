#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>

// Color macros for console output
#define RED(text) "\033[1;31m" << text << "\033[0m"
#define GREEN(text) "\033[1;32m" << text << "\033[0m"
#define YELLOW(text) "\033[1;33m" << text << "\033[0m"

class AForm; // Forward declaration

class Bureaucrat {
private:
  Bureaucrat();
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
  Bureaucrat(const Bureaucrat &rhs);
  Bureaucrat &operator=(const Bureaucrat &rhs);

  std::string getName() const;
  int getGrade() const;

  void signForm(AForm &f);
  void incrementGrade();
  void decrementGrade();
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);

#endif // BUREAUCRAT_HPP
