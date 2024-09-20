#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

int main() {
	try {
		Bureaucrat bur("pawn", 10);
		Intern randomIntern;
		AForm *form;

		form = randomIntern.makeForm("shrubbery creation", "target");
		if (form == NULL)
			return 1;

		bur.signForm(*form);
		bur.executeForm(*form);
		delete form;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return 0;
}