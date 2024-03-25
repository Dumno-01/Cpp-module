/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:03:31 by ffreze            #+#    #+#             */
/*   Updated: 2024/03/13 22:21:00 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv) 
{
    if (argc < 2) 
	{
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; ++i) 
	{
        for (int j = 0; argv[i][j]; ++j) 
		{
            std::cout << (char)toupper(argv[i][j]);
        }
        if (i < argc - 1) 
		{
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return (0);
}