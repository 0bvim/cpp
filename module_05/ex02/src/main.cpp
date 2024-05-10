#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

void testFormAndBureaucrat() {
    std::cout << YELLOW("----- Form and Bureaucrat Tests -----") << std::endl;

    try {
        // Creating a form
        AForm form("Application Form", 50, 25);

        // Creating a bureaucrat
        Bureaucrat bureaucrat("John", 55);

        std::cout << GREEN("Form details:") << std::endl;
        std::cout << form << std::endl;

        // Attempting to sign the form
        std::cout << GREEN("Attempting to sign the form...") << std::endl;
        bureaucrat.signForm(form);

        // Showing form details after signing
        std::cout << GREEN("Form details after signing:") << std::endl;
        std::cout << form << std::endl;

    } catch (std::exception &e) {
        std::cout << RED("Exception caught: " << e.what()) << std::endl;
    }

    try {
        // Creating a form
        AForm form2("Approval Form", 5, 10);

        // Creating a bureaucrat
        Bureaucrat bureaucrat2("Alice", 2);

        std::cout << GREEN("\nForm details:") << std::endl;
        std::cout << form2 << std::endl;

        // Attempting to sign the form
        std::cout << GREEN("Attempting to sign the form...") << std::endl;
        bureaucrat2.signForm(form2);

        // Showing form details after signing
        std::cout << GREEN("Form details after signing:") << std::endl;
        std::cout << form2 << std::endl;

    } catch (std::exception &e) {
        std::cout << RED("Exception caught: " << e.what()) << std::endl;
    }

	
}

void testValidationAndGradeTooHighException() {
    try {
        // Creating a form with invalid grade
        std::cout << YELLOW("----- Testing validation and GradeTooHighException -----") << std::endl;
        std::cout << GREEN("Attempting to create a form with invalid grade...") << std::endl;
        AForm invalidForm("Invalid Form", 150, 25); // Grade too high

    } catch (std::exception &e) {
        std::cout << RED("Exception caught: " << e.what()) << std::endl;
    }
}

int main() {
	testFormAndBureaucrat();
	testValidationAndGradeTooHighException();
	
  return 0;
}
