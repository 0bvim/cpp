#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {
private:
  std::string _input;
  std::stack<int> _stack;
  RPN();

public:
  RPN(const std::string input);
  ~RPN();
  RPN(const RPN &rhs);
  RPN &operator=(const RPN &rhs);

  class InvalidExpressionException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

	bool validateInput(const std::string &str);
  int calculate(void);
};

#endif // !RPN_HPP
