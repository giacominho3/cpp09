#pragma once

#include <iostream>
#include <vector>
#include <list>

class PmergeMe
{
	private:
		std::vector<int> vect;
		std::list<int> lst;

	public:
		PmergeMe();
		PmergeMe(std::string args);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
		void sortVect();
		void sortList();
};