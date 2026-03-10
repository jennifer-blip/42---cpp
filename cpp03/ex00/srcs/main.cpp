/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 10:11:41 by jodde             #+#    #+#             */
/*   Updated: 2026/03/10 09:23:12 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"


int main(void)
{
	{
		std::cout << std::endl << RED << "CLAPTRAP TEST - MEMBER FUNCTIONS" << RESET << std::endl;
		ClapTrap Asterix("Asterix");
		ClapTrap JCesar("Jules Cesar");
		Asterix.attack("Jules Cesar");
		JCesar.takeDamage(0);
		JCesar.beRepaired(2);
		Asterix.takeDamage(2);
		Asterix.beRepaired(2);
	}
	{
		std::cout << std::endl << RED << "CLAPTRAP TEST - COPY CONSTRUCTOR" << RESET << std::endl;
		ClapTrap Asterix("Asterix");
		ClapTrap Obelix(Asterix, "Obelix");
		Obelix.attack("some random roman soldiers");
		Obelix.takeDamage(10);
		Obelix.beRepaired(2);
	}
	return (0);	
}

