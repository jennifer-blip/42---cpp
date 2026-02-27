/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:54:40 by jodde             #+#    #+#             */
/*   Updated: 2026/02/27 09:12:03 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
//namespace anonymous pour les fonctions d'affichage
namespace
{
	void print(std::string str)
	{
		std::cout << str << std::endl;
	}
}

//constructors and destructor
Fixed::Fixed()
{
	setRawBits(0);
	print("Default constructor called");
}
Fixed::Fixed(Fixed const & src)
{
	print("Copy constructor called");
	*this = src;
}
Fixed::~Fixed()
{
	print("Destructor called");
}

//operators
Fixed& Fixed::operator=(Fixed const &rhs)
{
	print("Copy assignment operator called");
	this->_fixed = rhs.getRawBits();
	return (*this);
}

//accessors
int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed);
}

void Fixed::setRawBits( int const raw )
{
	this->_fixed = raw;
}
