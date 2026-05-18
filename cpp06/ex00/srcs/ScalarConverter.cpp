/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 22:48:07 by jodde             #+#    #+#             */
/*   Updated: 2026/05/18 12:54:03 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include <ctype.h>
#include "../includes/ScalarConverter.hpp"
#include "../includes/converters.hpp"
#include "../includes/display.hpp"

ScalarConverter::ScalarConverter(void){ }

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
    *this = src;
}

ScalarConverter::~ScalarConverter(void){ }

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &rhs)
{
	(void)rhs;
	return *this;
}

void ScalarConverter::convert(const std::string& input)
{
	env inputType;
	TypeConverter funcTab [4] = {charConverter, intConverter, doubleConverter, floatConverter};
	
	parseType(input, &inputType);
	switch(inputType.value)
	{
		case (0) :
		{
			displayChar(input);
			funcTab [1] (input, &inputType);
			funcTab [2] (input, &inputType);
			funcTab [3] (input, &inputType);
			break;
		}
		case (1) :
		{
			funcTab [0] (input, &inputType);
			funcTab [1] (input, &inputType);
			funcTab [2] (input, &inputType);
			funcTab [3] (input, &inputType);
			break;
		}
		case (2) :
		{
			displayChar("Impossible");
			funcTab [1] (input, &inputType);
			funcTab [2] (input, &inputType);
			funcTab [3] (input, &inputType);
			break;
		}
		case (3) :
		{
			displayChar("Impossible");
			funcTab [1] (input, &inputType);
			funcTab [2] (input, &inputType);
			funcTab [3] (input, &inputType);
			break;
		}
		case (4) :
		{
			specialOutput(&inputType, input);
			break;
		}
		default :
			display("Invalid input", RED);
	}
}