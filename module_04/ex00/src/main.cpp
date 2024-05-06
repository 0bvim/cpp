#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {
  {
    std::cout << "\nSubject test\n" << std::endl;

    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete i;
    delete j;
  }
  std::cout << "\nWrong animal test\n" << std::endl;
  {
    const wrongCat *thunder = new wrongCat();
    const wrongAnimal *meta = new wrongCat();
    const Animal *j = new Dog();
    const wrongAnimal *i = new wrongCat();
    std::cout << thunder->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    thunder->makeSound(); // will output the cat sound
    meta->makeSound();    // will output the wrong animal sound.
		delete thunder;
    delete meta;
    delete i;
    delete j;
  }

  return EXIT_SUCCESS;
}
