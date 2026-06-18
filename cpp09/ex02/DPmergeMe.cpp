/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DPmergeMe.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 18:01:45 by jodde             #+#    #+#             */
/*   Updated: 2026/06/18 23:16:23 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMe.hpp"
#include <limits> 
#include <algorithm>

///////////////DPMergeMe - deque class

DPmergeMe::DPmergeMe(){}
DPmergeMe::DPmergeMe(std::string& arg) : PmergeMe() { try {initSort(arg);} catch(std::exception& e) {std::cerr << e.what() << std::endl;}}
DPmergeMe::DPmergeMe(DPmergeMe const& src): PmergeMe<std::deque>(src) {}
DPmergeMe::~DPmergeMe(){}
DPmergeMe& DPmergeMe::operator=(DPmergeMe const& src){  PmergeMe<std::deque>::operator=(src); return (*this);	}

//member functions
void	DPmergeMe::initSort(std::string& arg)
{
	std::istringstream iss(arg);
	long nb;

	while(iss >> nb)
	{
		if (nb < 0 || nb > std::numeric_limits<unsigned int>::max())
			throw (std::logic_error("invalid arg format : only unsigned int authorized"));
		_cont.push_back(static_cast<unsigned int>(nb));
	}
	if (!(iss.eof()))
		throw (std::logic_error("invalid arg format"));	
	_execTime = clock();	
	sortDeq(_cont);	
}
int DPmergeMe::binarySearch(std::deque<unsigned int> &arr, int low, int high, unsigned int x) 
{
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < x)
            low = mid + 1;
		else
			high = mid -1;
   }
  return low;
}

void	DPmergeMe::insert(std::deque<unsigned int> &pend, std::deque<unsigned int> &main, std::deque<std::pair<unsigned int, unsigned int> >& pairs)
{
	std::vector<unsigned int> jacob = generateJacob(pend.size());
	std::vector<bool> inserted(pend.size(), false);

    int k = 1;
	{
		int bound = binarySearch(main, 0, static_cast<int>(main.size()) - 1, pairs[0].second);
		int pos = binarySearch(main, 0, bound, pend[0]);
		main.insert(main.begin() + pos, pend[0]);
	}
    while (k < static_cast<int>(jacob.size()) - 1)
    {
        int group_end   = std::min(jacob[k+1], static_cast<unsigned int>(pend.size())) - 1;
        int group_start = jacob[k]; // exclus, on part de group_end vers group_start+1
        for (int i = group_end; i >= group_start; i--)
        {
			int	pos;
            if (i >= static_cast<int>(pend.size()))
                continue;
			if (i >= static_cast<int>(pairs.size()))
				pos = binarySearch(main, 0, static_cast<int>(main.size()) - 1, pend[i]);
			else
			{
				int bound = binarySearch(main, 0, static_cast<int>(main.size()) - 1, pairs[i].second);
				pos = binarySearch(main, 0, bound, pend[i]);
			}
            main.insert(main.begin() + pos, pend[i]);
            inserted[i] = true;
        }
        k++;
    }
}


void	DPmergeMe::sortDeq(std::deque<unsigned int>& data)
{
	if (data.size()	<= 1)
		return;
	size_t 	i = 0; 
	std::deque<std::pair<unsigned int, unsigned int> > pairs;
	std::deque<unsigned int> pend;
	std::deque<unsigned int> main;
	bool	is_odd = ((data.size() % 2));
	while (i < data.size())
	{
		if (is_odd && i == (data.size() - 1))
		{
			pend.push_back(data[i]);
			break;
		}
		if (data[i] > data [i + 1])
			std::swap(data[i], data[i + 1]);
		pairs.push_back(std::make_pair (data[i], data[i + 1]));
		pend.push_back(data[i]);
		main.push_back(data[i + 1]);
		i += 2;
	}
	sortDeq(main);
	insert(pend, main, pairs);
	data = main;
	_execTime = clock() - _execTime;
}
void	DPmergeMe::displayDeq()
{
	std::cout <<"deque content : [ ";
	for (std::deque<unsigned int>::iterator it = _cont.begin(); it != _cont.end(); ++it)
		std::cout << *it << " ";
	std::cout << "]" << std::endl;
	std::cout << "time to sort the deque : " << static_cast<float>(_execTime)/CLOCKS_PER_SEC << "seconds" << std::endl;	
}

void	DPmergeMe::displayDeq(std::deque<unsigned int> deq)
{
	std::cout <<"[ ";
	for (std::deque<unsigned int>::iterator it = deq.begin(); it != deq.end(); ++it)
		std::cout << *it << " ";
	std::cout << "]" << std::endl;
}

void	DPmergeMe::displayDeq(std::deque<std::pair<unsigned int, unsigned int> > deq)
{
	std::cout <<"[ ";
	for (std::deque<std::pair<unsigned int, unsigned int> >::iterator it = deq.begin(); it != deq.end(); ++it)
		std::cout << "< " << it->first << ", " << it->second << " >";
	std::cout << "]" << std::endl;
}