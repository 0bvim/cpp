#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Bureaucrat; // Forward declaration

/**
 * @brief The Form class represents a form with a name, signing status, and required signing grades.
 */
class Form {
private:
  /**
   * @brief Default constructor (not accessible).
   */
  Form();

  const std::string _name; ///< The name of the form.
  bool _signed; ///< Indicates whether the form is signed or not.
  const int _gradeToSign; ///< The grade required to sign the form.
  const int _gradeToExecute; ///< The grade required to execute the form.

public:
  /**
   * @brief Constructs a new Form object with the specified parameters.
   * @param name The name of the form.
   * @param gradeToSign The grade required to sign the form.
   * @param gradeToExecute The grade required to execute the form.
   */
  Form(const std::string &name, int gradeToSign, int gradeToExecute);

  /**
   * @brief Destroys the Form object.
   */
  ~Form();

  /**
   * @brief Copy constructor.
   * @param rhs The Form object to copy.
   */
  Form(Form const &rhs);

  /**
   * @brief Assignment operator.
   * @param rhs The Form object to assign.
   * @return A reference to the assigned Form object.
   */
  Form &operator=(Form const &rhs);

  /**
   * @brief Exception class for when the grade required to sign the form is too high.
   */
  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  /**
   * @brief Exception class for when the grade required to sign the form is too low.
   */
  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  /**
   * @brief Gets the name of the form.
   * @return The name of the form.
   */
  std::string getName() const;

  /**
   * @brief Checks if the form is signed.
   * @return True if the form is signed, false otherwise.
   */
  bool getSignature() const;

  /**
   * @brief Gets the grade required to sign the form.
   * @return The grade required to sign the form.
   */
  int getSignGrade() const;

  /**
   * @brief Gets the grade required to execute the form.
   * @return The grade required to execute the form.
   */
  int getExecuteGrade() const;

  /**
   * @brief Signs the form by a bureaucrat.
   * @param b The bureaucrat who wants to sign the form.
   * @return True if the form is successfully signed, false otherwise.
   */
  bool beSigned(Bureaucrat &b);
};

/**
 * @brief Overloaded output stream operator to print a Form object.
 * @param os The output stream.
 * @param rhs The Form object to print.
 * @return The modified output stream.
 */
std::ostream &operator<<(std::ostream &os, Form const &rhs);

#endif // !FORM_HPP
