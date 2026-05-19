/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:34:03 by jodde             #+#    #+#             */
/*   Updated: 2026/05/19 23:09:06 by jodde            ###   ########.fr       */
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
		case (RESET):
			std::cout << "\033[0m" << msg << std::endl;
			break;
		case (NONE):
			std::cout << msg << std::endl;
	}
}
void	displayChar(char input)
{
	std::cout << "char : " << input << std::endl;
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

void	displaySpecial(env *inputType)
{
	if (inputType->PINF || inputType->PINFF)
	{
		display("char : Impossible", NONE);
		display("int : Impossible", NONE);
		display("float : +inff", NONE);
		display("double : +inf", NONE);
		return;
	}
	if (inputType->PINF || inputType->MINF || inputType->PINFF || inputType->MINFF)
	{
		display("char : Impossible", NONE);
		display("int : Impossible", NONE);
		display("float : -inff", NONE);
		display("double : -inf", NONE);
		return;
	}
	if (inputType->NAN || inputType->NANF)
	{
		display("char : Impossible", NONE);
		display("int : Impossible", NONE);
		display("float : nanf", NONE);
		display("double : nan", NONE);
		return;
	}
}