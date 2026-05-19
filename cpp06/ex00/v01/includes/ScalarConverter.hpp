/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 22:45:36 by jodde             #+#    #+#             */
/*   Updated: 2026/05/18 14:01:14 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctype.h>

typedef struct s_env
{
	enum type { 
		CHAR,
		INT, 
		DOUBLE, 
		FLOAT,
		SPECIAL,
		INVALID
	};
	type	value;
	bool	MINFF;
	bool	MINF;
	bool	PINFF;
	bool	PINF;
	bool	NANF;
	bool	NAN;
}env;

class	ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter(void);
		ScalarConverter	&operator=(ScalarConverter const &rhs);
	public:
		static void	convert(const std::string& str);
};

void			parseType(const std::string& input, env *inputType);