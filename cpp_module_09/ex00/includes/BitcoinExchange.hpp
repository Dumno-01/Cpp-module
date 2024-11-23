/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr >         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-18 08:01:04 by ffreze            #+#    #+#             */
/*   Updated: 2024-10-18 08:01:04 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <map>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <algorithm>

class BitcoinExchange
{
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &be);
	BitcoinExchange &operator=(const BitcoinExchange &be);
	int get_info_from_files(std::string path);
	void displayBTCExchange(std::string path);
	typedef std::map<std::string, double>::iterator mIterator;
	typedef std::pair<std::string, double> pairInput;
	typedef std::pair<std::string, double> pairBase;
private:
	std::map<std::string, double> base;
	double calc_exchange(std::string sDateInput);
};

#include <iostream>

#endif