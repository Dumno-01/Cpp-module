/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVec.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr >         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-08 10:24:27 by ffreze            #+#    #+#             */
/*   Updated: 2024-11-08 10:24:27 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/PmergeMe.hpp"

int getPosition(std::vector<int> vec, int nb, int begin, int end)
{
	int middle;
	std::vector<int>::iterator itLow;
	std::vector<int>::iterator itMid;
	std::vector<int>::iterator itHigh;

	if (begin == 0 && end == 1)
		return (1);
	itMid = vec.begin();
	middle = (begin + end) / 2;
	for (int i = 1; i < middle; i++)
		itMid++;
	if (middle == 1 && nb < *itMid)
		return (1);
	itLow = itMid;
	itLow--;
	itHigh = itMid;
	itHigh++;
	if (middle != 1 && (nb > *itLow && nb < *itMid))
		return (middle);
	else if (nb > *itMid && nb < *itHigh)
		return (middle + 1);
	if (nb > *itMid)
		return getPosition(vec, nb, middle, end);
	else
		return getPosition(vec, nb, begin, middle);
}


void merging(std::vector<int> *vecBig, std::vector<int> vecLittle, int jac)
{
	std::vector<int>::iterator itLittle;
	std::vector<int>::iterator itBig;
	int pos;

	itLittle = vecLittle.begin();
	itBig = vecBig->begin();
	for (int i = 1; i < jac; i++)
		itLittle++;
	pos = getPosition(*vecBig, *itLittle, 0, vecBig->size());
	for (int i = 1; i < pos; i++)
		itBig++;
	vecBig->insert(itBig, *itLittle);
}

void insert_odd(std::vector<int> *vecBig, int odd)
{
	std::vector<int>::iterator itBig = vecBig->begin();
	int pos;

	pos = getPosition(*vecBig, odd, 0, vecBig->size());
	for (int i = 1; i < pos; i++)
		itBig++;
	vecBig->insert(itBig, odd);
}

std::vector<int> PmergeMe::generateJacobstalVec(size_t size)
{
	std::vector<int> jacob;
	jacob.reserve(1000000);
	jacob.push_back(1);
	if (size >= 3)
		jacob.push_back(3);
	jacob.push_back(2);
	std::vector<int>::iterator itFirst = jacob.begin();
	std::vector<int>::iterator itScd = jacob.begin();
	int jacobNow = 3;
	int jacobBefore = 3;
	int jacobTmp;

	itScd++;
	if (size <= 3)
		return (jacob);
	while (1)
	{
		if (*itScd + 2 * *itFirst > static_cast<int>(size))
		{
			jacobTmp = size;
			while (jacobTmp - jacobBefore > 1)
			{
				jacob.push_back(jacobTmp);
				jacobTmp--;
			}
			break;
		}
		jacobNow = *itScd + 2 * *itFirst;
		jacob.push_back(jacobNow);
		jacobTmp = jacobNow;
		while (jacobTmp - jacobBefore > 1)
		{
			jacobTmp--;
			jacob.push_back(jacobTmp);
		}
		while (*itFirst != jacobBefore)
			itFirst++;
		while (*itScd != jacobNow)
			itScd++;
		jacobBefore = jacobNow;
	}
	return (jacob);
}

bool contain(int nb, std::vector<int> con)
{
	std::vector<int>::iterator it;
	std::vector<int>::iterator ite = con.end();

	for (it = con.begin(); it != ite; it++)
	{
		if (*it == nb)
			return true;
	}
	return false;
}

std::vector<int> PmergeMe::fusionVec(PmergeMe::pairsVec vec, bool isOdd, int odd)
{
	std::vector<int> vecBig;
	std::vector<int> vecLittle;
	std::vector<int> jacs;
	std::vector<int>::iterator itj;
	pairsVec::iterator it;
	std::vector<int>::iterator last;

	for (it = vec.begin(); it != vec.end(); it++)
	{
		vecBig.push_back(it->first);
		vecLittle.push_back(it->second);
	}
	jacs = generateJacobstalVec(vecLittle.size());
	for (itj = jacs.begin(); itj != jacs.end(); itj++)
	{
		merging(&vecBig, vecLittle, *itj);
		if (contain(*--vecLittle.end(), vecBig))
			break;
	}
	if (isOdd)
		insert_odd(&vecBig, odd);
	return (vecBig);
}

PmergeMe::pairsVec PmergeMe::divideInPairsVec(std::vector<int> myVec)
{
	pairsVec pairVec;
	std::vector<int>::iterator itnow = myVec.begin();
	std::vector<int>::iterator itnext;

	while (1)
	{
		itnext = itnow;
		itnext++;
		if (*itnow < *itnext)
		{
			pairVec.push_back(std::pair<int, int>(*itnext, *itnow));
		}
		else
		{
			pairVec.push_back(std::pair<int, int>(*itnow, *itnext));
		}
		itnow = itnext;
		itnow++;
		if (itnow == myVec.end())
			break;
	}
	return (pairVec);
}

void PmergeMe::sortPairsVec(std::vector<std::pair<int, int> > *myVec)
{
	pairsVec::iterator it = myVec->begin();
	pairsVec::iterator itnext;
	int tmp;

	if (myVec->size() == 1)
		return;
	while (1)
	{
		itnext = it;
		itnext++;
		if (it->first > itnext->first)
		{
			tmp = it->first;
			it->first = itnext->first;
			itnext->first = tmp;
			tmp = it->second;
			it->second = itnext->second;
			itnext->second = tmp;
			it = myVec->begin();
		}
		else
		{
			it = itnext;
		}
		if (it == --myVec->end())
			return;
	}
}

void PmergeMe::vecSort()
{
	clock_t timeBegin, timeEnd;
	bool isOdd = false;
	int odd = 0;
	pairsVec tmp;

	if (this->vecPm.size() % 2 == 1)
	{
		isOdd = true;
		odd = *--this->vecPm.end();
		vecPm.pop_back();
	}
	timeBegin = clock();
	tmp = divideInPairsVec(this->vecPm);
	sortPairsVec(&tmp);
	this->vecPm = fusionVec(tmp, isOdd, odd);
	timeEnd = clock();
	this->timeVec = static_cast<double>(timeEnd - timeBegin) / CLOCKS_PER_SEC * 1000000;
}

void PmergeMe::displayVector() const
{
	std::vector<int>::const_iterator it;
	std::vector<int>::const_iterator ite = this->vecPm.end();
	size_t i = 0;
	
	for (it = this->vecPm.begin(); it != ite; it++)
	{
		if (i < 10 || this->vecPm.size() - i < 10)
			std::cout << *it << " ";
		else
		{
			if (i == 10)
				std::cout << "[...]";
		}
		i++;
	}
	std::cout << "\n";
}