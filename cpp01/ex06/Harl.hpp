/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:14:37 by jodde             #+#    #+#             */
/*   Updated: 2026/02/20 10:04:48 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class Harl
{
	public :
		enum level
		{
			DEBUG, INFO, WARNING, ERROR
		};
	private :
		level		_logLevel;
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	public :
		Harl(){};
		~Harl(){};
		void complain( void);
		void set_logLevel(std::string logLevel);
};

typedef void (Harl::*HarlMemFunct)(void);