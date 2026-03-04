/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:54:40 by jodde             #+#    #+#             */
/*   Updated: 2026/03/04 15:25:52 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Fixed.hpp"
#include <cmath>

// constructors and destructor
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
Fixed::Fixed(Fixed const &src)
{
    *this = src;
}

Fixed::~Fixed()
{
}

// accessors
int Fixed::getRawBits(void) const
{
    return (this->_fixed);
}

void Fixed::setRawBits(int const raw)
{
    this->_fixed = raw;
}

// member functions
float Fixed::toFloat(void) const
{
    return ((float)this->_fixed / (1 << this->_frac));
}

int Fixed::toInt(void) const
{
    return (this->_fixed >> this->_frac);
}

// comparison operators
Fixed &Fixed::operator=(Fixed const &rhs)
{
    if (this != &rhs)
        this->_fixed = rhs.getRawBits();
    return (*this);
}

bool Fixed::operator>(Fixed const &rhs)
{
    if (this->getRawBits() > rhs.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator<(Fixed const &rhs)
{
    if (this->getRawBits() < rhs.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator>=(Fixed const &rhs)
{
    if (this->getRawBits() >= rhs.getRawBits())
        return (true);
    return (false);
}
bool Fixed::operator<=(Fixed const &rhs)
{
    if (this->getRawBits() <= rhs.getRawBits())
        return (true);
    return (false);
}
bool Fixed::operator==(Fixed const &rhs)
{
    if (this->getRawBits() == rhs.getRawBits())
        return (true);
    return (false);
}
bool Fixed::operator!=(Fixed const &rhs)
{
    if (this->getRawBits() != rhs.getRawBits())
        return (true);
    return (false);
}

// arithmetic operators
Fixed Fixed::operator+(Fixed const &rhs) const
{
    Fixed tmp;
    tmp.setRawBits(this->getRawBits() + rhs.getRawBits());
    return (tmp);
}
Fixed Fixed::operator-(Fixed const &rhs) const
{
    Fixed tmp;
    tmp.setRawBits(this->getRawBits() - rhs.getRawBits());
    return (tmp);
}
Fixed Fixed::operator*(Fixed const &rhs) const
{
    Fixed tmp;
	int64_t product = (int64_t)this->getRawBits() * rhs.getRawBits(); 
    tmp.setRawBits((int)(product) >> this->_frac);
    return (tmp);
}
Fixed Fixed::operator/(Fixed const &rhs) const
{
    Fixed tmp;
	int64_t dividend = ((int64_t)this->getRawBits() << this->_frac); 
    tmp.setRawBits((int) (dividend / rhs.getRawBits()));
    return (tmp);
}

// increment/decrement operators
Fixed &Fixed::operator++()
{
    this->_fixed++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    ++this->_fixed;
    return (tmp);
}

Fixed &Fixed::operator--()
{
    this->_fixed--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    --this->_fixed;
    return (tmp);
}

// min/max functions
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}
Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}
Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}
// stream operator
std::ostream &operator<<(std::ostream &os, Fixed const &rhs)
{
    os << rhs.toFloat();
    return (os);
}
