/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr >         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-18 08:12:24 by ffreze            #+#    #+#             */
/*   Updated: 2024-10-18 08:12:24 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	this->get_info_from_files("./data.csv");
}

BitcoinExchange::~BitcoinExchange()
{
	this->base.erase(base.begin(), base.end());
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &be)
{
	this->base.erase(base.begin(), base.end());
	this->base.insert(be.base.begin(), be.base.end());
	return *this;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &be)
{
	this->base.erase(base.begin(), base.end());
	this->base.insert(be.base.begin(), be.base.end());
}

bool isFileEmpty(std::ifstream& file)
{
 return file.peek() == std::ifstream::traits_type::eof();
}

bool verif_date_string(std::string s)
{
	if (s[4] != '-' || s[7] != '-')
		return false;
	for (int i = 0; i < 4; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return false;
	}
	for (int i = 5; i < 7; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return false;
	}
	for (int i = 8; i < 10; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return false;
	}
	return true;
}

bool leap_year(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				return true;
			else
				return false;
		}
		else
			return true;
	}
	else
		return false;
}

int* get_date_ints(std::string s)
{
	int* date = new int[3];
	std::string temp;

	temp = s.substr(0, 4);
	date[0] = atoi(temp.c_str());
	temp = s.substr(5, 2);
	date[1] = atoi(temp.c_str());
	temp = s.substr(8, 2);
	date[2] = atoi(temp.c_str());
	return date;
}

bool verif_date_number(std::string s)
{
	int* date = get_date_ints(s);

	if (date[0] < 0 || date[1] <= 0 || date[1] > 12 || date[2] < 0 || s < "2009-01-02")
	{
		delete[] date;
		return (false);
	}
	if (date[1] == 2)
	{
		if (leap_year(date[0]))
		{
			if (date[2] > 29)
			{
				delete[] date;
				return (false);
			}
		}
		else
		{
			if (date[2] > 28)
			{
				delete[] date;
				return (false);
			}
		}
	}
	else
	{
		if (date[1] % 2 == 0)
		{
			if (date[2] > 30)
			{
				delete[] date;
				return (false);
			}
		}
		else
		{
			if (date[2] > 31)
			{
				delete[] date;
				return (false);
			}
		}
	}
	delete[] date;
	return (true);
}

double BitcoinExchange::calc_exchange(std::string sDateInput)
{
	std::map<std::string, double>::iterator itlow;

	itlow = this->base.lower_bound(sDateInput);
	if (itlow == this->base.end())
		itlow--;
	if (itlow->first > sDateInput)
		itlow--;
	return (itlow->second);
}

void BitcoinExchange::displayBTCExchange(std::string path)
{
	double rate = 0;
	std::ifstream inputFile;
	char tmp;
	std::string line;
	std::string nbBtcTmp;
	double nbBtc = 0;
	std::string date;

		inputFile.open(path.c_str(), std::ifstream::in);
	if (inputFile.fail())
 {
   std::cout << "Can't open file: " << path << std::endl;
   exit(EXIT_FAILURE);
 }
if (isFileEmpty(inputFile))
{
 std::cout << "Input file is empty" << std::endl;
 inputFile.close();
 exit(EXIT_FAILURE);
}
	while (inputFile.good())
	{
		tmp = inputFile.get();
		if (tmp == '\n')
			break;
	}
	while (inputFile.good())
	{
		tmp = inputFile.get();
		if (tmp == '\n' || inputFile.eof())
		{
			if (line.find("|") == std::string::npos || !verif_date_string(line) || !verif_date_number(line))
			{
				std::cerr << "ERROR: bad input => " << line << std::endl;
				line.erase(line.begin(), line.end());
				continue;
			}
			date = line.substr(0, line.find('|') - 1);
			nbBtcTmp = line.substr(line.find('|') + 2, line.size() - line.find('|'));
			nbBtc = atof(nbBtcTmp.c_str());
			nbBtcTmp.erase(nbBtcTmp.begin(), nbBtcTmp.end());
			if (nbBtc < 0)
			{
				std::cerr << "ERROR: not a positive number." << std::endl;
				line.erase(line.begin(), line.end());
				date.erase(date.begin(), date.end());
				continue ;
			}
			if (nbBtc > 1000)
			{
				std::cerr << "ERROR: too large a number." << std::endl;
				line.erase(line.begin(), line.end());
				date.erase(date.begin(), date.end());
				continue ;
			}
			rate = calc_exchange(date);
			std::cout << date << " => " << nbBtc << " = " << rate * nbBtc << std::endl;
			line.erase(line.begin(), line.end());
			date.erase(date.begin(), date.end());
		}
		else
			line.push_back(tmp);
	}
inputfile.close();
}

int BitcoinExchange::get_info_from_files(std::string path)
{
	std::string line;
	std::ifstream myfile;
	char tmp;
	std::map<std::string, double> map;
	std::string date;
	std::string value;

		myfile.open(path.c_str(), std::ifstream::in);
	if (myfile.fail())
 {
   std::cout << "Can't open file: " << path << std::endl;
   exit(EXIT_FAILURE);
 }
	if (isFileEmpty(myfile))
{
 std::cout << "Data file is empty" << std::endl;
 myfile.close();
 exit(EXIT_FAILURE);
}
	while (myfile.good())
	{
		tmp = myfile.get();
		if (tmp == '\n')
			break;
	}
	while (myfile.good())
	{
		tmp = myfile.get();
		if (tmp == '\n' || myfile.eof())
		{
			date = line.substr(0, line.find(','));
			value = line.substr(line.find(',') + 1, (line.size() - line.find(',')) - 1);
			map.insert(map.begin(),std::pair<std::string, double>(date, atof(value.c_str())));
			date.erase(date.begin(), date.end());
			value.erase(date.begin(), date.end());
			line.erase(line.begin(), line.end());
		}
		else
		{
			line.push_back(tmp);
		}
	}
	this->base = map;
	myfile.close();
	return (0);
}