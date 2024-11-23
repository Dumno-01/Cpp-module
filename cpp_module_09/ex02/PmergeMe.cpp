/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr >         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-07 15:26:50 by ffreze            #+#    #+#             */
/*   Updated: 2024-11-07 15:26:50 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() 
{
	this->vecPm.erase(this->vecPm.begin(), this->vecPm.end());
	this->lstPm.erase(this->lstPm.begin(), this->lstPm.end());
}

PmergeMe::PmergeMe(char **argv)
{
	long int tmp = 0;
	int j = 0;
	for (size_t i = 1; argv[i] != NULL; i++)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= 48 && argv[i][j] <= 57))
				throw NumericError();
			j++;
		}
		tmp = atoi(argv[i]);
		if (tmp > std::numeric_limits<int>::max() || tmp < 0)
		{
			this->lstPm.erase(this->lstPm.begin(), this->lstPm.end());
			throw NumericError();
		}
		this->lstPm.push_back(tmp);
		this->vecPm.push_back(tmp);
	}
}

PmergeMe::PmergeMe(const PmergeMe &Pm) : vecPm(Pm.vecPm), lstPm(Pm.lstPm) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &Pm)
{
	this->lstPm = Pm.lstPm;
	this->vecPm = Pm.vecPm;
	return *this;
}

const char *PmergeMe::NumericError::what() const throw()
{
	return "Error with inputs";
}

double PmergeMe::getTimeList() const
{
	return this->timeList;
}

double PmergeMe::getTimeVec() const
{
	return this->timeVec;
}

std::list<int> PmergeMe::getLst() const
{
	return this->lstPm;
}

std::vector<int> PmergeMe::getVec() const
{
	return this->vecPm;
}