/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DPmergeMe.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 15:34:34 by jodde             #+#    #+#             */
/*   Updated: 2026/06/13 16:08:28 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <exception>

class	DPmergeMe
{
	private:
		std::deque<unsigned int>	_deq;
		DPmergeMe();
		
	public:
		DPmergeMe(std::string arg);
		DPmergeMe(VPmergeMe const& src);
		~DPmergeMe();
		DPmergeMe& operator=(DPmergeMe const& src);
	//member functions
		void	fillVec();
		void	displayVec();
};
