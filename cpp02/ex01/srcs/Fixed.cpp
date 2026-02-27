/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:54:40 by jodde             #+#    #+#             */
/*   Updated: 2026/02/27 09:38:07 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

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
	_fixed = 0;
	print("Default constructor called");
}
Fixed::Fixed(int const value)
{
	this->_fixed = value << this->_frac;
	print("Int constructor called");
}

Fixed::Fixed(float const value)
{
	this->_fixed = (int)roundf(value * (1 << this->_frac));
	print("Float constructor called");
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

std::ostream& operator<<(std::ostream& output, Fixed const &fixed)
{
	output << fixed.toFloat();
	return (output);
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

//member functions
float Fixed::toFloat( void ) const
{
	return ((float)this->_fixed / (1 << this->_frac));
}

int Fixed::toInt( void ) const
{
	return (this->_fixed >> this->_frac);
}
