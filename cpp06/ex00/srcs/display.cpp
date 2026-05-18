/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:34:03 by jodde             #+#    #+#             */
/*   Updated: 2026/05/18 12:49:38 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/display.hpp"
#include <iostream>
#include <iomanip>
#include <string>

void	display(std::string msg, color col)
{
	switch (col)
	{
		case (RED):
		{
			std::cout << "\033[31m" << msg << "\033[0m" << std::endl;
			break;
		}
		case (BROWN):
		{
			std::cout << "\033[33m" << msg << "\033[0m" << std::endl;
			break;
		}
		case (GREEN):
		{
			std::cout << "\033[32m" << msg << "\033[0m" << std::endl;
			break;
		}
		case (BLUE):
		{
			std::cout << "\033[34m" << msg << "\033[0m" << std::endl;
			break;
		}		
		default :
			std::cout << msg << std::endl;
	}
}
void	displayChar(std::string input)
{
	std::cout << std::fixed << std::setprecision(1) << "char : " << input << std::endl;
}
void	displayInt(int input)
{
	std::cout << std::fixed << std::setprecision(1) << "int : " << input << std::endl;
}
void	displayFloat(float input)
{
	std::cout << std::fixed << std::setprecision(1) << "float : " << input << "f" << std::endl;
}
void	displayDouble(double input)
{
	std::cout << std::fixed << std::setprecision(1) << "double : " << input << std::endl;
}