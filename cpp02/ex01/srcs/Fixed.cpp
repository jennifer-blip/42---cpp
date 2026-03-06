/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:54:40 by jodde             #+#    #+#             */
/*   Updated: 2026/03/06 09:44:35 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Fixed.hpp"
#include <cmath>
#define GREEN "\033[32m"
#define RESET "\033[0m"

// fonction d'affichage
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
    _fixed = 0;
    print("Default constructor called", true);
}
Fixed::Fixed(int const value)
{
    this->_fixed = value << this->_frac;
    print("Int constructor called", true);
}

Fixed::Fixed(float const value)
{
    print("Float constructor called", true);
    this->_fixed = (int)roundf(value * (1 << this->_frac));
}
Fixed::Fixed(Fixed const &cpy)
{
    print("Copy constructor called", true);
    *this = cpy;
}

Fixed::~Fixed()
{
    print("Destructor called", true);
}

// operators
Fixed &Fixed::operator=(Fixed const &rhs)
{
    print("Copy assignment operator called", true);
    if (this != &rhs)
        this->_fixed = rhs.getRawBits();
    return (*this);
}

std::ostream &operator<<(std::ostream &os, Fixed const &rhs)
{
    os << rhs.toFloat();
    return (os);
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

// member functions
float Fixed::toFloat(void) const //fonction pour recuperer la valeur reelle du nombre a virgule fixe
{
    return ((float)this->_fixed / (1 << this->_frac));
}

int Fixed::toInt(void) const //Fonction pour recuperer la partie entiere du nombre a virgule fixe
{
    return (this->_fixed >> this->_frac);
}
