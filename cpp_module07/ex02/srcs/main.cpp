/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 08:43:55 by ffreze            #+#    #+#             */
/*   Updated: 2024/09/02 08:45:42 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

int main() {
	std::cout << "------------ strings ------------" << std::endl;
	{
		Array<std::string> test(4);

		test[0] = "Strings";
		test[1] = "Array";
		test[2] = "Copy constructor";
		test[3] = "and copy assignment";

		Array<std::string> copy(test);
		std::cout << copy << std::endl;


		Array<std::string> copyOper = test;
		std::cout << copyOper << std::endl;
	}

	std::cout << "------------ int ------------" << std::endl;
	{
		Array<int> test(3);

		test[0] = 1;
		test[1] = 2;
		test[2] = 3;
		std::cout << test << std::endl;
		try {
			std::cout << test[1000] << std::endl;
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}