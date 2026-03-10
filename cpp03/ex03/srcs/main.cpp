/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 10:11:41 by jodde             #+#    #+#             */
/*   Updated: 2026/03/10 10:59:52 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/DiamondTrap.hpp"

int main(void)
{
	{
		std::cout << std::endl << RED << "DIAMOND TEST - MEMBER FUNCTIONS" << RESET << std::endl;
		DiamondTrap Tars("Tars");
		Tars.attack("Kipp");
		Tars.takeDamage(0);
		Tars.beRepaired(2);
		Tars.whoAmI();
		Tars.highFivesGuys();
		Tars.guardGate();
	}
	{
		std::cout << std::endl << RED << "DIAMOND TEST - COPY CONSTRUCTOR" << RESET << std::endl;
		DiamondTrap Tars("Tars");
		DiamondTrap Case(Tars, "Case");
		DiamondTrap Kipp("Kipp");
		Kipp = Case;
	}
	return (0);	
}

