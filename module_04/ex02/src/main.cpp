#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {
  {
    std::cout << "\nSubject test\n" << std::endl;

    const AAnimal *j = new Dog();
    const AAnimal *i = new Cat();
    delete j; // should not create a leak
    delete i;
  }
  std::cout << "\nMy tests\n" << std::endl;
  {
    const int arraySize = 4;
    AAnimal *animals[arraySize];

    for (int i = 0; i < arraySize / 2; ++i) {
      animals[i * 2] = new Dog();
      animals[i * 2 + 1] = new Cat();
    }
    for (int i = 0; i < arraySize / 2; ++i) {
      animals[i * 2]->getBrain()->setIdea("What does the fox say?", 0);
      animals[i * 2 + 1]->getBrain()->setIdea(
          "Ring-ding-ding-ding-dingeringeding! "
          "Gering-ding-ding-ding-dingeringeding! "
          "Gering-ding-ding-ding-dingeringeding",
          0);
    }
		std::cout << std::endl;
    std::cout << "Do you mind know what the animals are thinking?" << std::endl;
		for(int i = 0; i < arraySize; ++i) {
			std::cout << animals[i]->getBrain()->getIdea(0) << std::endl;
		}
		
        /* Delete animals */
        for (int i = 0; i < arraySize; ++i) {
      delete animals[i];
    }
  }
  std::cout << "\nWrong animal test\n" << std::endl;
  {
    const wrongAnimal *meta = new wrongCat();
    const AAnimal *j = new Dog();
    const wrongAnimal *i = new wrongCat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete i;
    delete j;
  }
  return EXIT_SUCCESS;
}
