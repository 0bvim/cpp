#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

// Define RED macro for colored output
#define RED(text) "\033[1;31m" << text << "\033[0m"

int main(void) {
	/* ShrubberyCreationForm tests */
	std::cout << "==== SHRUBBERY CREATION FORM TESTS ===="
		<< std::endl;
	std::cout << "\n=== LOW GRADE TO SIGN FORM ==="
		<< std::endl;
	{
		AForm *a = new ShrubberyCreationForm("home");
		Bureaucrat b("Hermes", 150);

		b.signForm(*a); // Grade should be equal or higher than 147!
		b.executeForm(*a);

		delete a;
	}
	std::cout << "\n=== LOW GRADE TO EXECUTE FORM ==="
		<< std::endl;
	{
		AForm *a = new ShrubberyCreationForm("home");
		Bureaucrat b("Hermes", 140);

		b.signForm(*a);
		b.executeForm(*a); // Grade should be equal or higher than 137!

		delete a;
	}
	std::cout << "\n=== CREATING A SHRUBBERY CREATION FORM ==="
		<< std::endl;
	{
		AForm *a = new ShrubberyCreationForm("home");
		Bureaucrat b("Hermes", 130);
		Bureaucrat c("Mercury", 1);

		b.signForm(*a);
		b.executeForm(*a);

		delete a;
	}
	/* RobotomyRequestForm tests */
	std::cout << "\n\n==== ROBOTOMY REQUEST FORM TESTS ===="
		<< std::endl;
	std::cout << "\n== LOW GRADE TO SIGN FORM ==="
		<< std::endl;
	{
		AForm *a = new RobotomyRequestForm("home");
		Bureaucrat b("Hermes", 73);

		b.signForm(*a); // Grade should be equal or higher than 72!
		b.executeForm(*a);

		delete a;
	}
	std::cout << "\n=== LOW GRADE TO EXECUTE FORM ===" 
		<< std::endl;
	{
		AForm *a = new RobotomyRequestForm("home");
		Bureaucrat b("Hermes", 48);

		b.signForm(*a);
		b.executeForm(*a); // Grade should be equal or higher than 45!

		delete a;
	}
	std::cout << "\n=== CREATING A ROBOTOMY REQUEST FORM ==="
		<< std::endl;
	{
		AForm *a = new RobotomyRequestForm("Arthur");
		Bureaucrat b("Hermes", 42);
		Bureaucrat c("Mercury", 5);

		b.signForm(*a);
		c.executeForm(*a);

		delete a;
	}
	return (0);
}
