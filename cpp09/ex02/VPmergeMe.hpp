/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VPmergeMe.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 15:34:34 by jodde             #+#    #+#             */
/*   Updated: 2026/06/13 16:34:46 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <exception>

class	VPmergeMe
{
	private:
		std::vector<unsigned int>	_vec;
		VPmergeMe();
		
	public:
		VPmergeMe(std::string arg);
		VPmergeMe(VPmergeMe const& src);
		~VPmergeMe();
		VPmergeMe& operator=(VPmergeMe const& src);
	//member functions
		void	fillVec(std::string& arg);
		void	displayVec();
	
};

void	logError(std::string message);