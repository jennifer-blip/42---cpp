/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:14:18 by jodde             #+#    #+#             */
/*   Updated: 2026/02/19 15:15:32 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout<<"DEBUG : Detailed information for diagnosing issues"<<std::endl;
	std::cout<<"use case : Developing and troubleshooting within the test environment"<<std::endl;
}
void	Harl::info(void)
{
	std::cout<<"INFO : General operational messages"<<std::endl;
	std::cout<<"use case : Tracking typical operations and application flow"<<std::endl;
}
void	Harl::warning(void)
{
	std::cout<<"WARNING : Potentially harmful situations"<<std::endl;
	std::cout<<"use case : Detecting potential and significant issues"<<std::endl;
}
void	Harl::error(void)
{
	std::cout<<"ERROR : Error events that still allow the app to continue running"<<std::endl;
	std::cout<<"use case : Alerting teams for critical issues that need attention"<<std::endl;
}
void Harl::complain( std::string level )
{
	HarlMemFunct funcTab [] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string	levelTab[] = {"DEBUG", "INFO", "WARNING", "ERROR" };
	
	for (int i = 0; i < 4; i++)
	{
		if (level == levelTab[i])
		{
			(this->*funcTab[i])();
			return ;
		}
	}
	std::cout<<"ERROR : ARGS : level expected : DEBUG, INFO, WARNING or ERROR"<<std::endl;
}