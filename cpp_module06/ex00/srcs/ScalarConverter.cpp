/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:31:18 by ffreze            #+#    #+#             */
/*   Updated: 2024/08/12 22:38:00 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal) {
	if (literal.length() < 1) {
		std::cout << "The input must not be empty" << std::endl;
		return ;
	}
	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "+inf" || literal == "inf" || literal == "inff" || literal == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (checkFloat(literal)) {
		printFloat(literal);
	}
	else if (checkDouble(literal)) {
		printDouble(literal);
	}
	else if (checkInt(literal)) {
		printInt(literal);
	}
	else if (literal.length() == 1 && std::isprint(literal[0])) {
		printChar(literal);
	}
}

void ScalarConverter::printChar(const std::string &literal) {
	char c = literal[0];
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::printInt(const std::string &literal) {
	long value = 0;
	std::istringstream s(literal);
	s >> value;

	char c = static_cast<char>(value);
	if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (value >= INT_MIN && value <= INT_MAX)
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::printFloat(const std::string &literal) {
	float value = atof(literal.c_str());
	char c = static_cast<char>(value);
	if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (value >= static_cast<float>(INT_MIN) && value <= static_cast<float>(INT_MAX))
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::printDouble(const std::string &literal) {
	double value = atof(literal.c_str());
	char c = static_cast<char>(value);
	if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (value >= static_cast<float>(INT_MIN) && value <= static_cast<float>(INT_MAX))
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if (static_cast<float>(value) >= FLT_MIN && static_cast<float>(value) <= FLT_MAX)
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

bool ScalarConverter::checkInt(const std::string &literal) {
	size_t j = 0;
	if (literal[j] == '-' || literal[j] == '+') {
		j++;
	}
	for (size_t i = j; i < literal.length(); i++) {
		if (!std::isdigit(literal[i])) {
			return false;
		}
	}
	return true;
}

bool ScalarConverter::checkFloat(const std::string &literal) {
	if (literal.find('.') != std::string::npos) {
		float value = atof(literal.c_str());
		return value == floorf(value);
	}
	return false;
}

bool ScalarConverter::checkDouble(const std::string &literal) {
	if (literal.find('.') != std::string::npos) {
		double value = atof(literal.c_str());
		return value == floor(value);
	}
	return false;
}