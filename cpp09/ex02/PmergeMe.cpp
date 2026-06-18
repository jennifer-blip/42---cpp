/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 15:34:47 by jodde             #+#    #+#             */
/*   Updated: 2026/06/18 17:31:09 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMe.hpp"
#include <limits> 
#include <algorithm>

////////////// out of class function
void	logError(std::string message)
{
	std::string msg = "ERROR -" + message;
	std::cout << "\033[31m" << msg << "\033[0m" << std::endl;
}

///////////////VPMergeMe - vector class

VPmergeMe::VPmergeMe(){}
VPmergeMe::VPmergeMe(std::string& arg) : PmergeMe() { try {initSort(arg);} catch(std::exception& e) {std::cerr << e.what() << std::endl;}}
VPmergeMe::VPmergeMe(VPmergeMe const& src): PmergeMe<std::vector>(src) {}
VPmergeMe::~VPmergeMe(){}
VPmergeMe& VPmergeMe::operator=(VPmergeMe const& src){  PmergeMe<std::vector>::operator=(src); return (*this);	}

//member functions
void	VPmergeMe::initSort(std::string& arg)
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
	_execTime = clock() - _execTime;	
	sortVec(_cont);	
}


int VPmergeMe::binarySearch(std::vector<unsigned int> &arr, int low, int high, unsigned int x) 
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

// void VPmergeMe::insert(std::vector<unsigned int> &pend, 
//                         std::vector<unsigned int> &main, 
//                         std::vector<std::pair<unsigned int, unsigned int> >& pairs)
// {
//     std::vector<unsigned int> jacob = generateJacob(pend.size());
//     std::vector<bool> inserted(pend.size(), false);
// 	bool isOdd = (pend.size() % 2) != 0;
//     int k = 1;
//     while (k < static_cast<int>(jacob.size()) - 1)
//     {
//         int group_end   = std::min(jacob[k+1], static_cast<unsigned int>(pend.size())) - 1;
//         int group_start = jacob[k];

//         for (int i = group_end; i >= group_start; i--)
//         {
//             if (i >= static_cast<int>(pend.size()))
//                 continue;
// 			if (isOdd && i == group_end) // element impair : pas de partenaire, cherche dans tout main
// 			{
// 				int pos = binarySearch(main, 0, static_cast<int>(main.size()) - 1, pend[i]);
// 				main.insert(main.begin() + pos, pend[i]);
// 				inserted[i] = true;
// 				continue;
// 			}
// 			// La borne haute de binary search : position du bêta partenaire pend[i] est partenaire de main[i] AVANT les insertions→ il faut chercher main[i] dans le main courant
// 			// (si main[i] n'existe plus à sa position originale, on peut simplifier et chercher dans tout main)
//            // element impair : pas de partenaire, cherche dans tout main
//           	int bound = binarySearch(main, 0, static_cast<int>(main.size()) - 1, pairs[i].second);
//             int pos = binarySearch(main, 0, bound, pend[i]);
//             main.insert(main.begin() + pos, pend[i]);
//             inserted[i] = true;
//         }
//         k++;
// 	}
// }
void	VPmergeMe::insert(std::vector<unsigned int> &pend, std::vector<unsigned int> &main, std::vector<std::pair<unsigned int, unsigned int> >& pairs)
{
	std::vector<unsigned int> jacob = generateJacob(pend.size());
	std::vector<bool> inserted(pend.size(), false);

    int k = 1;
	// main.insert(main.begin(), pend.back());
    while (k < static_cast<int>(jacob.size()) - 1)
    {
        int group_end   = std::min(jacob[k+1], static_cast<unsigned int>(pend.size())) - 1;
        int group_start = jacob[k]; // exclus, on part de group_end vers group_start+1
        for (int i = group_end; i >= group_start; i--)
        {
			int	pos;
            if (i >= static_cast<int>(pend.size()))
                continue;
            // La borne haute de binary search : position du bêta partenaire pend[i] est partenaire de main[i] AVANT les insertions→ il faut chercher main[i] dans le main courant
			std::cout << " Inserting pend[" << i << "] = " << pend[i] << std::endl;
			if (i >= static_cast<int>(pairs.size()))
				pos = binarySearch(main, 0, static_cast<int>(main.size()) - 1, pend[i]);
			else
			{
				int bound = binarySearch(main, 0, static_cast<int>(main.size()) - 1, pairs[i].second);
            // (si main[i] n'existe plus à sa position originale, on peut simplifier et chercher dans tout main)
				pos = binarySearch(main, 0, bound, pend[i]);
			}
            main.insert(main.begin() + pos, pend[i]);
            inserted[i] = true;
        }
        k++;
    }
}


void	VPmergeMe::sortVec(std::vector<unsigned int>& data)
{
	if (data.size()	<= 1)
		return;
	size_t 	i = 0; 
	std::vector<std::pair<unsigned int, unsigned int> > pairs;
	std::vector<unsigned int> pend;
	std::vector<unsigned int> main;
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
	sortVec(main);
	// data = main;
	insert(pend, main, pairs);
	data = main;	
}
void	VPmergeMe::displayVec()
{
	std::cout <<"vector content : [ ";
	for (std::vector<unsigned int>::iterator it = _cont.begin(); it != _cont.end(); ++it)
		std::cout << *it << " ";
	std::cout << "]" << std::endl;
	std::cout << "time to fill the vector : " << static_cast<float>(_execTime)/CLOCKS_PER_SEC << "seconds" << std::endl;	
}

void	VPmergeMe::displayVec(std::vector<unsigned int> vec)
{
	std::cout <<"[ ";
	for (std::vector<unsigned int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << "]" << std::endl;
}

void	VPmergeMe::displayVec(std::vector<std::pair<unsigned int, unsigned int> > vec)
{
	std::cout <<"[ ";
	for (std::vector<std::pair<unsigned int, unsigned int> >::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << "< " << it->first << ", " << it->second << " >";
	std::cout << "]" << std::endl;
}

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
	_execTime = clock() - _execTime;		
}
void	DPmergeMe::displayDeq()
{
	std::cout <<"deque content : [ ";
	for (std::deque<unsigned int>::iterator it = _cont.begin(); it != _cont.end(); ++it)
		std::cout << *it << " ";
	std::cout << "]" << std::endl;
	std::cout << "time to fill the deque : " << static_cast<float>(_execTime)/CLOCKS_PER_SEC << "seconds" << std::endl;	
}