/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:54:40 by jodde             #+#    #+#             */
/*   Updated: 2026/03/06 09:19:50 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Fixed.hpp"
#define GREEN "\033[32m"
#define RESET "\033[0m"

//fonction d'affichage
static void print(std::string str, bool color)
{
	if (color)
		std::cout << GREEN << str << RESET << std::endl;
	else
    	std::cout << str << std::endl;
}

// constructors and destructor
Fixed::Fixed()
{
    setRawBits(0);
    print("Default constructor called", true);
}
Fixed::Fixed(Fixed const& src)
{
    print("Copy constructor called", true);
    *this = src;
}
Fixed::~Fixed()
{
    print("Destructor called", true);
}

// operators
Fixed &Fixed::operator=(Fixed const& rhs)
{
    print("Copy assignment operator called", true);
    if (this != &rhs)
        this->_fixed = rhs.getRawBits();
    return (*this);
}

// accessors
int Fixed::getRawBits(void) const
{
    print("getRawBits member function called", false);
    return (this->_fixed);
}

void Fixed::setRawBits(int const raw)
{
    this->_fixed = raw;
}
