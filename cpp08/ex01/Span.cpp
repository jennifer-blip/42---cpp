/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 11:33:36 by jodde             #+#    #+#             */
/*   Updated: 2026/05/30 13:01:31 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>

void	display(std::string msg, color col)
{
	switch (col)
	{
		case (RED):
		{
			std::cout << "\033[31m" << msg << "\033[0m" << std::endl;
			break;
		}
		case (BROWN):
		{
			std::cout << "\033[33m" << msg << "\033[0m" << std::endl;
			break;
		}
		case (GREEN):
		{
			std::cout << "\033[32m" << msg << "\033[0m" << std::endl;
			break;
		}
		case (BLUE):
		{
			std::cout << "\033[34m" << msg << "\033[0m" << std::endl;
			break;
		}		
		default :
			std::cout << msg << std::endl;
	}
}
//constructors and destructors
Span::Span() {}
Span::Span(unsigned int N): _max(N) {
    display("Span constructor called", BLUE);
}
Span::Span(Span const & src): _max(src.getMax())
{
    this->_vec = src._vec;
    display("Span copy constructor called", BLUE);
}
Span::~Span() { display("Span destructor called", BLUE); }

//assignment operator
Span& Span::operator=(Span const & rhs)
{
    this->_max = rhs.getMax();
    this->_vec = rhs._vec;
    return (*this);
}

//accessors
unsigned int Span::getMax(void) const
{ return (_max); }

unsigned int    Span::getSize(void) const
{ return (this->_vec.size()); }

//member functions
void Span::addNumber(int number)
{
    if (_vec.size() >= _max)
        throw std::length_error("Span is full");
    _vec.push_back(number);
}

void    Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    for(;begin < end; begin++)
        addNumber(*begin);
}

int Span::shortestSpan(void) const
{
    if (_vec.size() <= 1)
        throw std::length_error("Span needs at least 2 elements");
    std::vector<int> sorted(_vec);
    std::sort(sorted.begin(), sorted.end());
    int min_span = std::numeric_limits<int>::max();
    for (size_t i = 0; i + 1 < sorted.size(); i++)
    {
        int diff = sorted[i + 1] - sorted[i];
        if (diff < min_span)
            min_span = diff;
    }
    return (min_span);
}

int Span::longestSpan(void) const
{
    if (_vec.size() <= 1)
        throw std::length_error("Span needs at least 2 elements");
    return (*std::max_element(_vec.begin(), _vec.end())
            - *std::min_element(_vec.begin(), _vec.end()));
}

void Span::displaySpan(void) const
{
    std::vector<int>::const_iterator it;
    for (it = _vec.begin(); it != _vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}
