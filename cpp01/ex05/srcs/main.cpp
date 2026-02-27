/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:14:27 by jodde             #+#    #+#             */
/*   Updated: 2026/02/25 12:06:39 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	log;
	if (argc < 2)
	{
		log.complain("DEBUG");
		log.complain("INFO");
		log.complain("WARNING");
		log.complain("ERROR");
	}
	else
		log.complain(argv[1]);
	return (0);
}
