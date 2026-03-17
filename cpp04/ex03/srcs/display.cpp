/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 08:57:51 by jodde             #+#    #+#             */
/*   Updated: 2026/03/16 09:15:12 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../includes/display.hpp"

void	display(std::string msg, color col)
{
	switch (col)
	{
		case (RED):
		{
			std::cout << "\033[31m" << msg << "\033[0m" << std::endl;
			break;
		}
		case (BROWN):
		{
			std::cout << "\033[33m" << msg << "\033[0m" << std::endl;
			break;
		}
		case (GREEN):
		{
			std::cout << "\033[32m" << msg << "\033[0m" << std::endl;
			break;
		}
		case (YELLOW):
		{
			std::cout << "\033[38;5;226m" << msg << "\033[0m" << std::endl;
			break;
		}
		case (BLUE):
		{
			std::cout << "\033[34m" << msg << "\033[0m" << std::endl;
			break;
		}
		case (MAGENTA):
		{
			std::cout << "\033[35m" << msg << "\033[0m" << std::endl;
			break;
		}
		case (GREY):
		{
			std::cout << "\033[37m" << msg << "\033[0m" << std::endl;
			break;
		}
		default :
			std::cout << msg << std::endl;
	}
}
