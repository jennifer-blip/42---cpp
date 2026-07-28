/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 15:34:34 by jodde             #+#    #+#             */
/*   Updated: 2026/06/27 14:17:56 by jodde            ###   ########.fr       */
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

	public:
		
		PmergeMe(std::string& arg);
		PmergeMe(PmergeMe const& src);
		virtual ~PmergeMe();
		PmergeMe<Container>& operator=(PmergeMe const& src);
		//member functions
		void	initSort(std::string& arg);	
		std::vector<unsigned int> generateJacob(size_t pend_size);
		bool	isSorted(container_type& cont);
		int		binarySearch(container_type &arr, int low, int high, unsigned int x);
		void	insert(container_type &pend, container_type &main, std::vector<std::pair<unsigned int, unsigned int> >& pairs);
		void	sortNum(container_type& data);
		void	displayNum();
		void	displayNum(container_type& vec);
		void	displayPairs(std::vector<std::pair<unsigned int, unsigned int> > const& vec);
};

void	logError(std::string message);

#include "PmergeMe.tpp"
