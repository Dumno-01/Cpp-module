#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main() {
	try {
		Bureaucrat bur("pawn", 10);

		std::cout << "---------------- Shrubbery form ----------------" << std::endl;
		ShrubberyCreationForm shrub("Target");
		bur.signForm(shrub);
		bur.executeForm(shrub);

		std::cout << "---------------- Robotomy form ----------------" << std::endl;
		RobotomyRequestForm robot("robot");
		bur.executeForm(robot);
		bur.signForm(robot);
		bur.executeForm(robot);
		bur.executeForm(robot);

		std::cout << "---------------- Presidential form ----------------" << std::endl;
		PresidentialPardonForm pres("toto");
		bur.executeForm(pres);
		bur.signForm(pres);
		bur.executeForm(pres);
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return 0;
}