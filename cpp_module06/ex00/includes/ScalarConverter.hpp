/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:38:28 by ffreze            #+#    #+#             */
/*   Updated: 2024/08/12 22:38:30 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <sstream>
#include <climits>
#include <bits/stdc++.h>

class ScalarConverter {
public:
	static void convert(std::string const & literal);

private:
	static void printChar(std::string const & literal);
	static void printInt(std::string const & literal);
	static void printFloat(std::string const & literal);
	static void printDouble(std::string const & literal);

	static bool checkInt(std::string const & literal);
	static bool checkFloat(std::string const & literal);
	static bool checkDouble(std::string const & literal);

	ScalarConverter();
};