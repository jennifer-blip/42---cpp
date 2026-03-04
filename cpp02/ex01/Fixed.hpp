/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:54:47 by jodde             #+#    #+#             */
/*   Updated: 2026/03/04 13:50:20 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <ostream>
#include <string>

class Fixed
{
  private:
    int _fixed;
    static const int _frac = 8;

  public:
    // constructors and destructor
    Fixed();
    Fixed(int const value);
    Fixed(float const value);
    Fixed(Fixed const &cpy);
    ~Fixed();
    // operator
    Fixed &operator=(Fixed const &rhs);
    // accessors
    int getRawBits(void) const;
    void setRawBits(int const raw);
    // member functions
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, Fixed const &rhs);
