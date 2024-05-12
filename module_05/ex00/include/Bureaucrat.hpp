#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>

/**
 * @brief The Bureaucrat class represents a bureaucrat with a name and a grade.
 */
class Bureaucrat {
private:
  const std::string _name; /* The name of the bureaucrat. */
  int _grade;              /* The grade of the bureaucrat. */

  static const int _minGrade = 150;
  static const int _maxGrade = 1;

public:
  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade is too high"; }
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade is too low"; }
  };

  /**
   * @brief Constructs a new Bureaucrat object with default values.
   */
  Bureaucrat();

  /**
   * @brief Constructs a new Bureaucrat object with the specified name and
   * grade.
   * @param name The name of the bureaucrat.
   * @param grade The grade of the bureaucrat.
   */
  Bureaucrat(const std::string &name, int grade);

  /**
   * @brief Destroys the Bureaucrat object.
   */
  ~Bureaucrat();

  /**
   * @brief Copy constructor.
   * @param rhs The Bureaucrat object to copy.
   */
  Bureaucrat(Bureaucrat const &rhs);

  /**
   * @brief Assignment operator.
   * @param rhs The Bureaucrat object to assign.
   * @return A reference to the assigned Bureaucrat object.
   */
  Bureaucrat &operator=(Bureaucrat const &rhs);

  /**
   * @brief Gets the name of the bureaucrat.
   * @return The name of the bureaucrat.
   */
  std::string getName() const;

  /**
   * @brief Gets the grade of the bureaucrat.
   * @return The grade of the bureaucrat.
   */
  int getGrade() const;

  /**
   * @brief Increments the grade of the bureaucrat by 1.
   */
  void incrementGrade();

  /**
   * @brief Decrements the grade of the bureaucrat by 1.
   */
  void decrementGrade();
};

/**
 * @brief Overloaded output stream operator to print a Bureaucrat object.
 * @param os The output stream.
 * @param bureaucrat The Bureaucrat object to print.
 * @return The modified output stream.
 */
std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);

#endif // BUREAUCRAT_HPP
