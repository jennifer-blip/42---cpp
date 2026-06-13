/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VPmergeMe.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 15:34:47 by jodde             #+#    #+#             */
/*   Updated: 2026/06/13 17:19:51 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./VPmergeMe.hpp"
#include <limits> 

void	logError(std::string message)
{
	std::string msg = "ERROR -" + message;
	std::cout << "\033[31m" << msg << "\033[0m" << std::endl;
}

VPmergeMe::VPmergeMe(){}
VPmergeMe::VPmergeMe(std::string arg){try {fillVec(arg);} catch(std::exception& e) {std::cerr << e.what() << std::endl;}}
VPmergeMe::VPmergeMe(VPmergeMe const& src){*this = src;}
VPmergeMe::~VPmergeMe(){}
VPmergeMe& VPmergeMe::operator=(VPmergeMe const& src)
{
	this->_vec = src._vec;
	return (*this);	
}
//member functions
void	VPmergeMe::fillVec(std::string& arg)
{
	std::istringstream iss(arg);
	long nb;

	while(iss >> nb)
	{
		if (nb < 0 || nb > std::numeric_limits<unsigned int>::max())
			throw (std::logic_error("invalid arg format : only unsigned int authorized"));
		_vec.push_back(static_cast<unsigned int>(nb));
	}
	if (!(iss.eof()))
		throw (std::logic_error("invalid arg format"));			
}
void	VPmergeMe::displayVec()
{
	std::cout <<"vector content : [ ";
	for (std::vector<unsigned int>::iterator it = _vec.begin(); it != _vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << "]" << std::endl;	
}
	