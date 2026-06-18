/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 15:34:34 by jodde             #+#    #+#             */
/*   Updated: 2026/06/18 17:53:03 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <exception>
#include <ctime>

template <template <class, class> class Container>
class	PmergeMe
{
	typedef Container<unsigned int, std::allocator<unsigned int> > container_type;
	protected:
		container_type _cont;
		clock_t							_execTime;
		PmergeMe(): _execTime(clock()) {}
		
	public:
		
		PmergeMe(std::string& arg){ _execTime = clock();}
		PmergeMe(PmergeMe const& src){*this = src;}
		virtual ~PmergeMe(){}
		PmergeMe<Container>& operator=(PmergeMe const& src){ this->_cont = src._cont; this-> _execTime = src._execTime; return (*this);}
		//member functions
		virtual void	initSort(std::string& arg) = 0;	
		std::vector<unsigned int> generateJacob(size_t pend_size)
		{
			std::vector<unsigned int> jacob;
    		jacob.push_back(0);
    		jacob.push_back(1);
   			while (jacob.back() < static_cast<unsigned int>(pend_size))
        		jacob.push_back(jacob[jacob.size()-1] + 2 * jacob[jacob.size()-2]);
			return jacob;
		}
		bool	isSorted(container_type& cont)
		{
			if (cont.size() < 2)
        		return (true);
			typename container_type::iterator it = cont.begin();
			typename container_type::iterator next = it;
			++next;
			while(next != cont.end())
			{
				if (*it > *next)
				{
					std::cout << false <<std::endl;
					return (false);
				}
				++it;
				++next;
			}
			std::cout << true <<std::endl;
			return (true);
		}
};

class	VPmergeMe : public PmergeMe<std::vector>
{
	public:
		VPmergeMe();
		VPmergeMe(std::string& arg);
		VPmergeMe(VPmergeMe const& src);
		~VPmergeMe();
		VPmergeMe& operator=(VPmergeMe const& src);
	//member functions
		void	initSort(std::string& arg);
		void	sortVec(std::vector<unsigned int>& data);
		void	displayVec();
		void	displayVec(std::vector<unsigned int> vec);
		void	displayVec(std::vector<std::pair<unsigned int, unsigned int> > vec);
		void	insert(std::vector<unsigned int> &pend, std::vector<unsigned int> &main, std::vector<std::pair<unsigned int, unsigned int> >& pairs);
		int		binarySearch(std::vector<unsigned int> &arr, int low, int high, unsigned int x); 
	
};

class	DPmergeMe : public PmergeMe<std::deque>
{
	public:
		DPmergeMe();
		DPmergeMe(std::string& arg);
		DPmergeMe(DPmergeMe const& src);
		~DPmergeMe();
		DPmergeMe& operator=(DPmergeMe const& src);
	//member functions
		void	initSort(std::string& arg);
		void	sortDeq(std::deque<unsigned int>& data);
		void	displayDeq();
		void	displayDeq(std::deque<unsigned int> deq);
		void	displayDeq(std::deque<std::pair<unsigned int, unsigned int> > deq);
		void	insert(std::deque<unsigned int> &pend, std::deque<unsigned int> &main, std::deque<std::pair<unsigned int, unsigned int> >& pairs);
		int		binarySearch(std::deque<unsigned int> &arr, int low, int high, unsigned int x); 
	
};

void	logError(std::string message);