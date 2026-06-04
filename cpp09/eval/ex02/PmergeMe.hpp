#pragma once
#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <ctime>

class PmergeMe
{
private:
	std::vector<int>	_vec;
	std::deque<int>	_deq;

	void	mergeInsertVector(std::vector<int>& v);
	void	mergeInsertDeque(std::deque<int>& d);
	std::vector<int>	jacobsthalSequence(int n);
	void	parseInput(int argc, char** argv);

	template<typename Container>
	void printContainer(const std::string& label, const Container& c) const {
		std::cout << label;
		typename Container::const_iterator	it = c.begin();
		int	count = 0;
		for (; it != c.end() && count < 10; ++it, ++count)
			std::cout << *it << " ";
		if (c.size() > 10)
			std::cout << "[...]";
		std::cout << std::endl;
	}
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe&	operator=(const PmergeMe& other);
	~PmergeMe();

	void	run(int argc, char** argv);
};