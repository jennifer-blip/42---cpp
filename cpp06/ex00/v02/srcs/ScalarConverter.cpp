/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 22:48:07 by jodde             #+#    #+#             */
/*   Updated: 2026/05/19 20:36:17 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include <ctype.h>
#include "../includes/ScalarConverter.hpp"
#include "../includes/Scalar.hpp"
#include "../includes/CharValue.hpp"
#include "../includes/IntValue.hpp"
#include "../includes/FloatValue.hpp"
#include "../includes/DoubleValue.hpp"
#include "../includes/display.hpp"

ScalarConverter::ScalarConverter(void){ }

ScalarConverter::ScalarConverter(ScalarConverter const &src){   *this = src;}

ScalarConverter::~ScalarConverter(void){ }

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &rhs){ (void)rhs; return *this;}

static void	createScalar(std::string input, env *inputType)
{
	switch(inputType->value)
	{
		case (0) :
		{
			Scalar *scalar = new CharValue(input);
			scalar->displayAsChar();
			scalar->displayAsInt();
			scalar->displayAsFloat();
			scalar->displayAsDouble();
			delete scalar;
			break;
		}
		case (1) :
		{
			Scalar *scalar = new IntValue(input);
			scalar->displayAsChar();
			scalar->displayAsInt();
			scalar->displayAsFloat();
			scalar->displayAsDouble();
			delete scalar;
			break;
		}
		case (2) :
		{
			Scalar *scalar = new FloatValue(input);
			scalar->displayAsChar();
			scalar->displayAsInt();
			scalar->displayAsFloat();
			scalar->displayAsDouble();
			delete scalar;
			break;
		}
		case (3) :
		{
			Scalar *scalar = new DoubleValue(input);
			scalar->displayAsChar();
			scalar->displayAsInt();
			scalar->displayAsFloat();
			scalar->displayAsDouble();
			delete scalar;
			break;
		}
		case (4) :
		{
			displaySpecial(inputType);
			break;
		}
		default :
			display("Invalid input", RED);
	}
}

void ScalarConverter::convert(const std::string str)
{
	env inputType;

	parseType(str, &inputType);
	createScalar(str, &inputType);
}