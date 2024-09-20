#include "../includes/Bureaucrat.hpp"

int main()
{
	Bureaucrat* henry = NULL;
	try
	{
		henry = new Bureaucrat("Henry", 13);
		for(int i = 0; i < 156; i++)
		{
			henry->degradation();
			std::cout << *henry << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "An error was encountered : " << e.what() << '\n';
	}

	 if (henry)
	{
        delete henry;
   	}
	return (0);
}