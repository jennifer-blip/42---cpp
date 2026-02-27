/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:14:18 by jodde             #+#    #+#             */
/*   Updated: 2026/02/25 11:41:28 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#define RED  "\033[31m"
#define RESET  "\033[0m"

//Constructors and destructors
Harl::Harl(){}
Harl::~Harl(){}

//Private functions
void	Harl::debug(void)
{
	std::cout<<RED<<"DEBUG :"<<RESET<<" Detailed information for diagnosing issues"<<std::endl;
	std::cout<<"use case : Developing and troubleshooting within the test environment"<<std::endl;
}
void	Harl::info(void)
{
	std::cout<<RED<<"INFO :"<<RESET<<" General operational messages"<<std::endl;
	std::cout<<"use case : Tracking typical operations and application flow"<<std::endl;
}
void	Harl::warning(void)
{
	std::cout<<RED<<"WARNING :"<<RESET<<" Potentially harmful situations"<<std::endl;
	std::cout<<"use case : Detecting potential and significant issues"<<std::endl;
}
void	Harl::error(void)
{
	std::cout<<RED<<"ERROR :"<<RESET<<" Error events that still allow the app to continue running"<<std::endl;
	std::cout<<"use case : Alerting teams for critical issues that need attention"<<std::endl;
}

//Member function
void Harl::complain( std::string level )
{
	// HarlMemFunct funcTab [] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	void (Harl::*funcTab[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
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
