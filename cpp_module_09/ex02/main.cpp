#include "includes/PmergeMe.hpp"

bool containsDuplicates(const std::list<int>& lst) {
    std::list<int>::const_iterator it, it2;
    for (it = lst.begin(); it != lst.end(); ++it) {
        it2 = it;
        for (++it2; it2 != lst.end(); ++it2) {
            if (*it == *it2) {
                return true;
            }
        }
    }
    return false;
}

bool isSortVec(std::vector<int> vec)
{
	std::vector<int>::const_iterator it, it2;
	for (it = vec.begin(); it != vec.end(); ++it)
	{
		it2 = it;
		for (++it2; it2 != vec.end(); ++it2)
		{
			if (*it > *it2)
				return false;
		}
	}
	return true;
}

bool isSortLst(std::list<int> lst)
{
	std::list<int>::const_iterator it, it2;
	for (it = lst.begin(); it != lst.end(); ++it)
	{
		it2 = it;
		for (++it2; it2 != lst.end(); ++it2)
		{
			if (*it > *it2)
				return false;
		}
	}
	return true;
}

int main(int argc, char **argv)
{
	size_t size_inputs;
	PmergeMe *PM;
	if (argc > 2)
	{
		try
		{
			PM = new PmergeMe(argv);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
			return (-1);
		}
		if (containsDuplicates(PM->getLst()))
		{
			std::cerr << "Number are duplicate\n";
			delete PM;
			return -1;
		}
		if (isSortVec(PM->getVec()))
		{
			std::cerr << "List is already sorted\n";
			delete PM;
			return -1;
		}
		size_inputs = PM->getLst().size();
		std::cout << "Before: ";
		PM->displayList();
		PM->vecSort();
		PM->lstSort();
		std::cout << "After: ";
		PM->displayVector();
		PM->displayList();
		std::cout << "Time to process a range of " << size_inputs << " elements with std::list : " << std::fixed << std::setprecision(5) << PM->getTimeList() << " us\n";
		std::cout << "Time to process a range of " << size_inputs << " elements with std::vector : " << std::fixed << std::setprecision(5) << PM->getTimeVec() << " us\n";
		if (!isSortVec(PM->getVec()) || !isSortLst(PM->getLst()))
			std::cout << "List or vector are not sorted\n";
		else
			std::cout << "List and vector are sorted\n";
		delete PM;
	}
}