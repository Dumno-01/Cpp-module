#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main()
{
	try
	{
		Form lolForm("Lol", 5, 5);
		Form merdeForm("MERDE", 140, 140);
		Bureaucrat Henry("Henry", 120);
		Henry.signForm(merdeForm);
		Henry.signForm(lolForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << "An error was encountered : " << e.what() << '\n';
	}
	return (0);
}