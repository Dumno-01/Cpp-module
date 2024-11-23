#include "includes/RPN.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		RPN myRpn(argv[1]);
	}
	else
	{
		std::cout << "need only one argument." << std::endl;
	}
}