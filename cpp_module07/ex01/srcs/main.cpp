/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 08:43:55 by ffreze            #+#    #+#             */
/*   Updated: 2024/09/02 08:45:54 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"
#include <iostream>

template <typename T>
static void printItem(T const & item) {
	std::cout << item << std::endl;
}

int main() {
	std::cout << "--------- INT ---------" << std::endl;
	int arr[5] = {2, 5, 78, 24, -12};
	iter(arr, 5, printItem);

	std::cout << "--------- STRING ---------" << std::endl;
	std::string arrStr[5] = {"2", "string", "template", "test\n", "%^*&"};
	iter(arrStr, 5, printItem);
}