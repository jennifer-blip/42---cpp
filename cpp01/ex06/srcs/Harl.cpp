/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:14:18 by jodde             #+#    #+#             */
/*   Updated: 2026/02/20 10:05:59 by jodde            ###   ########.fr       */
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

void Harl::set_logLevel(std::string logLevel)
{
	if (logLevel == "DEBUG")
		_logLevel = DEBUG;
	if (logLevel == "INFO")
		_logLevel = INFO;
	if (logLevel == "WARNING")
		_logLevel = WARNING;
	if (logLevel == "ERROR")
		_logLevel = ERROR;
}
void Harl::complain( void )
{
	HarlMemFunct funcTab [] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	
	switch (static_cast<int>(_logLevel))
	{
		case (0) :
		{
			for (int i=0; i<=0; i++)
			(this->*funcTab[i])();
			break ;
		}
		case (1) :
		{
			for (int i=0; i<=1; i++)
			(this->*funcTab[i])();
			break ;
		}
		case (2) :
		{
			for (int i=0; i<=2; i++)
			(this->*funcTab[i])();
			break ;
		}
		case (3) :
		{
			for (int i=0; i<=3; i++)
			(this->*funcTab[i])();
			break ;
		}
		default :
			std::cout<<"ERROR : ARGS : level expected : DEBUG, INFO, WARNING or ERROR"<<std::endl;
	}
}