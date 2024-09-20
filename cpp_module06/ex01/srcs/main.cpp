/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:19:35 by ffreze            #+#    #+#             */
/*   Updated: 2024/09/02 08:42:49 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"
#include <iostream>
#include <inttypes.h>

int main() {
	Data data;

	data.a = 42;
	data.b = 1.23f;
	data.c = 'X';

	std::cout << data.a << "-" << data.b << "-" << data.c << std::endl;

	uintptr_t ptr = Serializer::serialize(&data);
	Data *dataSerialized = Serializer::deserialize(ptr);

	std::cout << dataSerialized->a << "-" << dataSerialized->b << "-" << dataSerialized->c << std::endl;
	return 0;
}