/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:54:47 by jodde             #+#    #+#             */
/*   Updated: 2026/02/27 14:09:55 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <ostream>
#include <string>
#define GREEN  "\033[32m"
#define RED  "\033[31m"
#define RESET  "\033[0m"

class Fixed
{
	private:
		int _fixed;
		static const int _frac = 8;
	public:
	//constructors and destructor
		Fixed();
		Fixed(int const value);
		Fixed(float const value);
		Fixed(Fixed const & src);
		~Fixed();
	//comparison operators
		Fixed& operator=(Fixed const &rhs);
		bool operator>(Fixed const &rhs);
		bool operator<(Fixed const &rhs);
		bool operator>=(Fixed const &rhs);
		bool operator<=(Fixed const &rhs);
		bool operator==(Fixed const &rhs);
		bool operator!=(Fixed const &rhs);
	//arithmetic operators
		Fixed operator+(Fixed const &rhs) const;
		Fixed operator-(Fixed const &rhs) const;
		float operator*(Fixed const &rhs) const;
		float operator/(Fixed const &rhs) const;
	//increment/decrement operators
		Fixed& operator++(); //pre-increment
		Fixed operator++(int); //post-increment
		Fixed& operator--(); //pre-decrement
		Fixed operator--(int); //post-decrement
	//min/max functions
		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed const& min(Fixed const &a, Fixed const &b);
		static Fixed& max(Fixed& a, Fixed& b);
		static Fixed const& max(Fixed const &a, Fixed const &b);
	//accessors
		int getRawBits( void ) const;
		void setRawBits( int const raw );
	//member functions
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& output, Fixed const &fixed);
