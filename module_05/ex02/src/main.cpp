#include <iostream>
#include <cstdlib> // For rand() function
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Define RED macro for colored output
#define RED(text) "\033[1;31m" << text << "\033[0m"

int main() {
    // Create a bureaucrat
    Bureaucrat bureaucrat("John", 50);

    // Test ShrubberyCreationForm
    ShrubberyCreationForm shrubberyForm("garden");
    shrubberyForm.beSigned(bureaucrat);
    shrubberyForm.execute(bureaucrat);

    // Test RobotomyRequestForm
    RobotomyRequestForm robotomyForm("target");
    robotomyForm.beSigned(bureaucrat);
    robotomyForm.execute(bureaucrat);

    // Test PresidentialPardonForm
    PresidentialPardonForm pardonForm("criminal");
    pardonForm.beSigned(bureaucrat);
    pardonForm.execute(bureaucrat);

    // Test executeForm member function of Bureaucrat
    Bureaucrat executingBureaucrat("Alice", 10);
    executingBureaucrat.executeForm(shrubberyForm);
    executingBureaucrat.executeForm(robotomyForm);
    executingBureaucrat.executeForm(pardonForm);

    // Test executing form with insufficient grade
    Bureaucrat lowGradeBureaucrat("LowGrade", 100);
    lowGradeBureaucrat.executeForm(shrubberyForm);
    lowGradeBureaucrat.executeForm(robotomyForm);
    lowGradeBureaucrat.executeForm(pardonForm);

    return 0;
}
