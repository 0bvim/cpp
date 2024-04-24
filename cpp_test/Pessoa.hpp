#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <cstddef>
#include <string>

class Pessoa {
public:
  Pessoa();
  ~Pessoa();

  std::string getName(void) const;
  std::size_t getAge(void) const;

  void setName(const std::string name);
  void setAge(const std::size_t age);

private:
  std::string _name;
  std::size_t _age;
};

#endif // !PESSOA_HPP
