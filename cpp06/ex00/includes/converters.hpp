/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 22:45:36 by jodde             #+#    #+#             */
/*   Updated: 2026/05/18 12:53:42 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctype.h>
#include "../includes/ScalarConverter.hpp"

void	charConverter(const std::string& input, env *inputType);
void	intConverter(const std::string& input, env *inputType);
void	doubleConverter(const std::string& input, env *inputType);
void	floatConverter(const std::string& input, env *inputType);
void	specialOutput(env *inputType, const std::string& input);
typedef void	(*TypeConverter)(const std::string & input, env *inputType);