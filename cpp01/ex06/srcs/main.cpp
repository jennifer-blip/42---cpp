/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:14:27 by jodde             #+#    #+#             */
/*   Updated: 2026/02/22 17:33:37 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl log;
	std::string	lvl;
	if (argc < 2)
	{
		std::cout<<"enter requested log level 'DEBUG', 'INFO', 'WARNING' or 'ERROR'"<<std::endl;
		if (!(std::getline(std::cin, lvl)))
		{
			std::cout<<"EOF detected, exiting program"<<std::endl;
			return (1);
		}
		log.set_logLevel(lvl);
		log.complain();
	}
	else
	{
		lvl = argv[1];
		log.set_logLevel(lvl);
		log.complain();
	}
	return (0);
}
