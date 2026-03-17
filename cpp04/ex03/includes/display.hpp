/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 08:54:16 by jodde             #+#    #+#             */
/*   Updated: 2026/03/16 17:14:25 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <sstream>

enum	color
{
	RESET,
	GREEN,
	YELLOW,
	RED,
	BROWN,
	BLUE,
	MAGENTA,
	GREY
};

void	display(std::string msg, color col);
