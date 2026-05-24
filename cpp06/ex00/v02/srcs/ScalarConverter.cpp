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

static Scalar*	createScalar(std::string input, env *inputType, bool *isScalar)
{
	
	switch(inputType->value)
	{
		case (0) :
		{
			Scalar *scalar = new CharValue(input);
			return scalar;
			break;
		}
		case (1) :
		{
			Scalar *scalar = new IntValue(input);
			return scalar;
			break;
		}
		case (2) :
		{
			Scalar *scalar = new FloatValue(input);
			return scalar;
			break;
		}
		case (3) :
		{
			Scalar *scalar = new DoubleValue(input);
			return scalar;
			break;
		}
		case (4) :
		{
			*isScalar = false;
			return NULL;
			break;
		}
		default :
		{	
			display("Invalid input", RED);
			return NULL;
		}
	}
	
}

void ScalarConverter::convert(const std::string str)
{
	env inputType;
	Scalar *scalar = NULL;
	bool isScalar = true;

	parseType(str, &inputType);
	scalar = createScalar(str, &inputType, &isScalar);
	if (isScalar && scalar != NULL)
	{
		displayScalar(scalar);
		delete scalar;
	}
	else
		displaySpecial(str);
}
