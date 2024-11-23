/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr >         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-18 10:30:18 by ffreze            #+#    #+#             */
/*   Updated: 2024-10-18 10:30:18 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		BitcoinExchange be;
		be.displayBTCExchange(argv[1]);
	}
	else
	{
		std::cout << "Need an argument." << std::endl;
	}
}