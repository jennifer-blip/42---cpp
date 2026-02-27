/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed_op.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:54:40 by jodde             #+#    #+#             */
/*   Updated: 2026/02/27 12:32:57 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

//comparison operators

Fixed& Fixed::operator=(Fixed const &rhs)
{
	this->_fixed = rhs.getRawBits();
	return (*this);
}

bool Fixed::operator>(Fixed const &rhs)
{
	if (this->getRawBits()>rhs.getRawBits())
		return (true);
	return (false);
}
bool Fixed::operator<(Fixed const &rhs)
{
		if (this->getRawBits()<rhs.getRawBits())
		return (true);
	return (false);
}
bool Fixed::operator>=(Fixed const &rhs)
{
	if (this->getRawBits()>=rhs.getRawBits())
		return (true);
	return (false);
}
bool Fixed::operator<=(Fixed const &rhs)
{
	if (this->getRawBits()<=rhs.getRawBits())
		return (true);
	return (false);
}
bool Fixed::operator==(Fixed const &rhs)
{
	if (this->getRawBits()==rhs.getRawBits())
		return (true);
	return (false);
}
bool Fixed::operator!=(Fixed const &rhs)
{
	if (this->getRawBits()!=rhs.getRawBits())
		return (true);
	return (false);
}

//arithmetic operators
Fixed Fixed::operator+(Fixed const &rhs) const
{
	Fixed tmp;
	tmp.setRawBits(this->getRawBits()+rhs.getRawBits()); 
	return(tmp);
}
Fixed Fixed::operator-(Fixed const &rhs) const
{
	Fixed tmp;
	tmp.setRawBits(this->getRawBits()-rhs.getRawBits()); 
	return(tmp);
}
float Fixed::operator*(Fixed const &rhs) const
{
	return(this->toFloat() * rhs.toFloat());
}
float Fixed::operator/(Fixed const &rhs) const
{
	return(this->toFloat()/rhs.toFloat());
}

//increment/decrement operators
Fixed Fixed::operator++()
{
	this->_fixed++;
	return(*this);
}

Fixed Fixed::operator++(int)	
{
	Fixed tmp = *this;
	++this->_fixed;
	return(tmp);	
}

Fixed Fixed::operator--()
{
	this->_fixed--;
	return(*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	--this->_fixed;
	return(tmp);	
}


//min/max functions
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}
Fixed const& Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}
Fixed const& Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}
