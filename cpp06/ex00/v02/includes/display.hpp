/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:14:16 by jodde             #+#    #+#             */
/*   Updated: 2026/05/19 20:54:58 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <iomanip> //std:fixed, std::setprecision
#include "../includes/ScalarConverter.hpp"
#include "../includes/Scalar.hpp"
#include "../includes/env.hpp"

class Scalar;

enum color
{
	RESET,
	RED,
	BROWN,
	GREEN,
	BLUE,
	NONE
};

void	display(std::string msg, color col);
void	displayChar(char input);
void	displayInt(int input);
void	displayFloat(float input);
void	displayDouble(double input);
void	displayScalar(Scalar *scalar);
void	displaySpecial(std::string input);
