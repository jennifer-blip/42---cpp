/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseType.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 18:23:26 by jodde             #+#    #+#             */
/*   Updated: 2026/05/18 14:13:40 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<string>
#include <ctype.h>
#include "../includes/ScalarConverter.hpp"


void parseType(const std::string& input, env *inputType)
{
	size_t	i = 0;
	bool	hasDot = false;
	bool	hasF = false;
	if (input == "nan" || input == "nanf" || input == "+inf" || input == "+inff" || input == "-inf" || input == "-inff")
	{
		inputType->value = env::SPECIAL;
		return;
	}
	if (input[i] == '+' || input[i] == '-')
		i++;
	if (input.length() == 1 && !std::isdigit(input[0]))
	{
		inputType->value = env::CHAR;
		return;
	}
	while (i < input.length())
	{
		if (std::isdigit(input[i]))
		{
			i++;
			continue;
		}
		if (input[i] == '.' && !hasDot)
		{
			hasDot = true;
			i++;
			continue;
		}
		if (input[i] == 'f' && hasDot && i == input.length() - 1)
		{
			hasF = true;
			i++;
			continue;
		}
		break;
	}
	if (i != input.length())
	{
		inputType->value = env::INVALID;
		return;
	}
	if (hasF)
		inputType->value = env::FLOAT;
	else if (hasDot)
		inputType->value = env::DOUBLE;
	else
		inputType->value = env::INT;
}
