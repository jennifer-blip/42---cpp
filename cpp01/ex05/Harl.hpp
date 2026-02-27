/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:14:37 by jodde             #+#    #+#             */
/*   Updated: 2026/02/25 11:18:04 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class Harl
{
	private :
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	public :
	//Constructors and destructors
		Harl();
		~Harl();
	//member function
		void complain( std::string level );
};

// typedef void (Harl::*HarlMemFunct)(void);
