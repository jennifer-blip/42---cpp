/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:17:05 by jodde             #+#    #+#             */
/*   Updated: 2026/05/19 20:36:05 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <ctype.h>
#include "../includes/Scalar.hpp"
#include "../includes/env.hpp"

class	Scalar;

class	ScalarConverter
{
	private :
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const& src);
		~ScalarConverter(void);
		ScalarConverter &operator=(ScalarConverter const& src);
	public:
		static void		convert(const std::string str);
};

void	parseType(const std::string& input, env *inputType);
