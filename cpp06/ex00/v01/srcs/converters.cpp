/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 23:57:16 by jodde             #+#    #+#             */
/*   Updated: 2026/05/18 14:11:28 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "../includes/converters.hpp"
#include "../includes/display.hpp"

void	charConverter(const std::string& input, env *inputType)
{
	int		i;
	(void)inputType;
	std::istringstream iss(input);
	
	iss >> i;
	if (i > 31 && i < 128)
	{
		displayChar(std::string(1, static_cast<char>(i)));
		return;
	}
	if (i > 0 && i < 32)
	{
		displayChar("Non displayable");
		return;
	}
	else
		displayChar("Impossible");
	return;
}

void	intConverter(const std::string& input, env *inputType)
{
	int	i;
	if (inputType->value == env::CHAR)
	{
		displayInt((static_cast<int>(input[0])));
	}
	else
	{
		std::istringstream iss(input);
		iss >> i;
		displayInt(i);
	}
}
void	doubleConverter(const std::string& input, env *inputType)
{
	double	d;
	if (inputType->value == env::CHAR)
		displayDouble((static_cast<double>(input[0])));
	else
	{
		std::istringstream iss(input);
		iss >> d;
		displayDouble(d);
	}
}

void	floatConverter(const std::string& input, env *inputType)
{
	float	f;
	if (inputType->value == env::CHAR)
		displayFloat((static_cast<float>(input[0])));
	else
	{
		std::istringstream iss(input);
		iss >> f;
		displayFloat(f);
	}
}

void	specialOutput(env *specialType, const std::string& input)
{
	if (specialType->PINF || specialType->PINFF)
	{
		std::cout << std::setprecision(2) << "char: impossible" << std::endl;
		if (specialType->PINFF)
		{
			std::cout << std::setprecision(2) << "int: +inf" << std::endl;
			std::cout << std::setprecision(2) << "float: " << input << std::endl;
			std::cout << std::setprecision(2) << "double: +inf" << std::endl;
		}
		else
		{
			std::cout << std::setprecision(2) << "int: "<< input << std::endl;
			std::cout << std::setprecision(2) << "float: " << input << "f" << std::endl;
			std::cout << std::setprecision(2) << "double: " << input << std::endl;
		}
	}
	else if (specialType->MINF || specialType->MINFF)
	{
		std::cout << std::setprecision(2) << "char: impossible" << std::endl;
		
		if (specialType->MINFF)
		{
			std::cout << std::setprecision(2) << "int: -inf" << std::endl;
			std::cout << std::setprecision(2) << "float: " << input << std::endl;
			std::cout << std::setprecision(2) << "double: -inf" << std::endl;
		}
		else
		{
			std::cout << std::setprecision(2) << "int: " << input << std::endl;
			std::cout << std::setprecision(2) << "float: " << input << "f" << std::endl;
			std::cout << std::setprecision(2) << "double: " << input << std::endl;
		}
	}
	else if (specialType->NAN || specialType->NANF)
	{
		std::cout << std::setprecision(2) << "char: impossible" << std::endl;
		
		if (specialType->NANF)
		{
			std::cout << std::setprecision(2) << "int: nan" << std::endl;
			std::cout << std::setprecision(2) << "float: " << input << std::endl;
			std::cout << std::setprecision(2) << "double: nan" << std::endl;
		}
		else
		{
			std::cout << std::setprecision(2) << "int: " << input << std::endl;
			std::cout << std::setprecision(2) << "float: " << input << "f" << std::endl;
			std::cout << std::setprecision(2) << "double: " << input << std::endl;
		}
	}
}