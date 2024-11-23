/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeList.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr >         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-07 18:38:17 by ffreze            #+#    #+#             */
/*   Updated: 2024-11-07 18:38:17 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/PmergeMe.hpp"

int getPosition(std::list<int> lst, int nb, int begin, int end)
{
	int middle;
	std::list<int>::iterator itLow;
	std::list<int>::iterator itMid;
	std::list<int>::iterator itHigh;

	if (begin == 0 && end == 1)
		return (1);
	itMid = lst.begin();
	middle = (begin + end) / 2;
	for (int i = 1; i < middle; i++)
		itMid++;
	if (middle == 1 && nb < *itMid)
		return (1);
	itLow = itMid;
	itLow--;
	itHigh = itMid;
	itHigh++;
	if (nb > *itLow && nb < *itMid)
		return (middle);
	else if (nb > *itMid && nb < *itHigh)
		return (middle + 1);
	if (nb > *itMid)
		return getPosition(lst, nb, middle, end);
	else
		return getPosition(lst, nb, begin, middle);
}

void merging(std::list<int> *lstBig, std::list<int> lstLittle, int jac)
{
	std::list<int>::iterator itLittle;
	std::list<int>::iterator itBig;
	int pos;

	itLittle = lstLittle.begin();
	itBig = lstBig->begin();
	for (int i = 1; i < jac; i++)
		itLittle++;
	pos = getPosition(*lstBig, *itLittle, 0, lstBig->size());
	for (int i = 1; i < pos; i++)
		itBig++;
	lstBig->insert(itBig, *itLittle);
}

void insert_odd(std::list<int> *lstBig, int odd)
{
	std::list<int>::iterator itBig = lstBig->begin();
	int pos;

	pos = getPosition(*lstBig, odd, 0, lstBig->size());
	for (int i = 1; i < pos; i++)
		itBig++;
	lstBig->insert(itBig, odd);
}

std::list<int> PmergeMe::generateJacobstalLst(size_t size)
{
	std::list<int> jacob;
	jacob.push_back(1);
	if (size >= 3)
		jacob.push_back(3);
	jacob.push_back(2);
	std::list<int>::iterator itFirst = jacob.begin();
	std::list<int>::iterator itScd = jacob.begin();
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

bool contain(int nb, std::list<int> con)
{
	std::list<int>::iterator it;
	std::list<int>::iterator ite = con.end();

	for (it = con.begin(); it != ite; it++)
	{
		if (*it == nb)
			return true;
	}
	return false;
}

std::list<int> PmergeMe::fusionLst(PmergeMe::pairsList lst, bool isOdd, int odd)
{
	std::list<int> lstBig;
	std::list<int> lstLittle;
	std::list<int> jacs;
	std::list<int>::iterator itj;
	pairsList::iterator it;
	std::list<int>::iterator last;

	for (it = lst.begin(); it != lst.end(); it++)
	{
		lstBig.push_back(it->first);
		lstLittle.push_back(it->second);
	}
	jacs = generateJacobstalLst(lstLittle.size());
	for (itj = jacs.begin(); itj != jacs.end(); itj++)
	{
		merging(&lstBig, lstLittle, *itj);
		if (contain(*--lstLittle.end(), lstBig))
			break;
	}

	if (isOdd)
		insert_odd(&lstBig, odd);
	return (lstBig);
}

PmergeMe::pairsList PmergeMe::divideInPairsLst(std::list<int> myLst)
{
	pairsList pairLst;
	std::list<int>::iterator itnow = myLst.begin();
	std::list<int>::iterator itnext;

	while (myLst.size() >= 2)
	{
		itnext = itnow;
		itnext++;
		if (*itnow < *itnext)
		{
			pairLst.push_back(std::pair<int, int>(*itnext, *itnow));
		}
		else
		{
			pairLst.push_back(std::pair<int, int>(*itnow, *itnext));
		}
		myLst.pop_front();
		itnow = itnext;
		itnow++;
		myLst.pop_front();
	}
	return (pairLst);
}

void PmergeMe::sortPairsLst(std::list<std::pair<int, int> > *myLst)
{
	pairsList::iterator it = myLst->begin();
	pairsList::iterator itnext;
	int tmp;

	if (myLst->size() == 1)
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
			it = myLst->begin();
		}
		else
		{
			it = itnext;
		}
		if (it == --myLst->end())
			return;
	}
}

void PmergeMe::lstSort()
{
	clock_t timeBegin, timeEnd;
	bool isOdd = false;
	int odd = 0;
	pairsList tmp;

	if (this->lstPm.size() % 2 == 1)
	{
		isOdd = true;
		odd = *--this->lstPm.end();
		lstPm.pop_back();
	}
	timeBegin = clock();
	tmp = divideInPairsLst(this->lstPm);
	sortPairsLst(&tmp);
	this->lstPm = fusionLst(tmp, isOdd, odd);
	timeEnd = clock();
	this->timeList = static_cast<double>(timeEnd - timeBegin) / CLOCKS_PER_SEC * 1000000;
}

void PmergeMe::displayList() const
{
	std::list<int>::const_iterator it;
	std::list<int>::const_iterator ite = this->lstPm.end();
	size_t i = 0;

	for (it = this->lstPm.begin(); it != ite; it++)
	{
		if (i < 10 || this->lstPm.size() - i < 10)
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