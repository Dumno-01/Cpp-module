/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr >         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-07 14:12:26 by ffreze            #+#    #+#             */
/*   Updated: 2024-11-07 14:12:26 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP9_PMERGEME_HPP
#define CPP9_PMERGEME_HPP
#include <vector>
#include <string>
#include <limits>
#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <list>
#include <iomanip>
#include <utility>

class PmergeMe
{
public:
	class NumericError : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &Pm);
	PmergeMe(char **argv);
	PmergeMe &operator=(const PmergeMe &Pm);

	void vecSort();
	void displayVector() const;
	std::vector<int> getVec() const;

	void lstSort();
	std::list<int> getLst() const;
	void displayList() const;

	double getTimeList() const;
	double getTimeVec() const;

	typedef std::list<std::pair<int, int> > pairsList;
	typedef std::vector<std::pair<int, int> > pairsVec;
private:
	std::list<int> generateJacobstalLst(size_t size);
	std::list<int> fusionLst(pairsList lst, bool isOdd, int odd);
	void sortPairsLst(pairsList *myLst);
	pairsList divideInPairsLst(std::list<int> lst);

	std::vector<int> generateJacobstalVec(size_t size);
	std::vector<int> fusionVec(pairsVec lst, bool isOdd, int odd);
	void sortPairsVec(pairsVec *myLst);
	pairsVec divideInPairsVec(std::vector<int> lst);

	std::vector<int> vecPm;
	std::list<int> lstPm;
	double timeList;
	double timeVec;
};

#endif