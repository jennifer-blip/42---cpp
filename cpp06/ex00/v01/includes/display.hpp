/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:33:36 by jodde             #+#    #+#             */
/*   Updated: 2026/05/18 12:05:05 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

enum color
{
	RESET,
	RED,
	BROWN,
	GREEN,
	BLUE
};

void	display(std::string msg, color col);
void	displayChar(std::string input);
void	displayInt(int input);
void	displayFloat(float input);
void	displayDouble(double input);
