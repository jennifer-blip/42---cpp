/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:54:40 by jodde             #+#    #+#             */
/*   Updated: 2026/03/03 15:49:54 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

//constructors and destructor
Fixed::Fixed()
{
	_fixed = 0;
}
Fixed::Fixed(int const value)
{
	this->_fixed = value << this->_frac;
}

Fixed::Fixed(float const value)
{
	this->_fixed = (int)roundf(value * (1 << this->_frac));
}
Fixed::Fixed(Fixed const & src)
{
	*this = src;
}

Fixed::~Fixed(){}

//accessors
int Fixed::getRawBits( void ) const
{
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

//stream operator
std::ostream& operator<<(std::ostream& output, Fixed const &fixed)
{
	output << fixed.toFloat();
	return (output);
}
