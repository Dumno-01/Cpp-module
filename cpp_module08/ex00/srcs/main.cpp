/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 08:08:56 by ffreze            #+#    #+#             */
/*   Updated: 2024/09/05 08:09:27 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "../includes/easyfind.hpp"

int main() {
//	int array[] = { 1, 2, 3, 4, 5, 6};
	std::vector<int> list;
	for (int i = 0; i < 10; i++) {
		list.push_back(i);
	}
	std::vector<int>::iterator search = easyfind(list, 50);
	std::cout << *search << std::endl;


	search = easyfind(list, 5);
	std::cout << *search << std::endl;
}