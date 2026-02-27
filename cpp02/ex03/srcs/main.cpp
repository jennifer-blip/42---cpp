/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:54:30 by jodde             #+#    #+#             */
/*   Updated: 2026/02/27 12:37:43 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
	{
		std::cout<<RED<<"[TEST] 42 subject "<<RESET<<std::endl;
		Fixed	a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::min( a, b ) << std::endl;
	}
	{
		std::cout<<RED<<"[TEST] arithmetic operators"<<RESET<<std::endl;
		Fixed a(5);
		Fixed b(1.1f);

		std::cout<<"valeur de a "<<a<<std::endl;
		std::cout<<"valeur de b "<<b<<std::endl;
		std::cout<<GREEN<<"multiplication a * b = "<<RESET<<a * b<<std::endl;
		std::cout<<GREEN<<"addition a + b = "<<RESET<< a + b<<std::endl;
		std::cout<<GREEN<<"soustraction a - b = "<<RESET<< a - b<<std::endl;
		std::cout<<GREEN<<"division a / b = "<<RESET<<a / b<<std::endl;
	}
		{
		std::cout<<RED<<"[TEST] comparison operators"<<RESET<<std::endl;
		Fixed a(5);
		Fixed b(1);
		Fixed c(1);

		std::cout<<"valeur de a "<<a<<std::endl;
		std::cout<<"valeur de b "<<b<<std::endl;
		std::cout<<GREEN<<"test 1. < operator"<<RESET<<std::endl;
		if (a < b)
			std::cout<<"comparison result "<<"a<b"<<std::endl;
		else
			std::cout<<"comparison result "<<"a>b"<<std::endl;
		std::cout<<GREEN<<"test 2. > operator"<<RESET<<std::endl;
		if (a > b)
			std::cout<<"comparison result "<<"a>b"<<std::endl;
		else
			std::cout<<"comparison result "<<"a<b"<<std::endl;
		std::cout<<GREEN<<"test 3. <= operator"<<RESET<<std::endl;
		if (c <= b)
			std::cout<<"comparison result "<<"c<b"<<std::endl;
		else
			std::cout<<"comparison result "<<"c>b"<<std::endl;
		std::cout<<GREEN<<"test 4. >= operator"<<RESET<<std::endl;
		if (c >= b)
			std::cout<<"comparison result "<<"c>b"<<std::endl;
		else
			std::cout<<"comparison result "<<"c<b"<<std::endl;
	}
	return 0;
}
