/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 10:11:41 by jodde             #+#    #+#             */
/*   Updated: 2026/03/10 09:26:20 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"


int main(void)
{
	{
		std::cout << std::endl << RED << "SCAVTRAP TEST - MEMBER FUNCTIONS" << RESET << std::endl;
		ClapTrap Tars("Tars");
		ScavTrap Case("Case");
		ScavTrap Kipp ("Kipp");
		Kipp.guardGate();
		Tars.attack("Kipp");
		Kipp.takeDamage(0);
		Kipp.beRepaired(2);
		Case.attack("Tars");
		Tars.takeDamage(2);
		Tars.beRepaired(2);
		Kipp.guardGate();
	}
	{
		std::cout << std::endl << RED << "SCAVTRAP TEST - COPY CONSTRUCTOR" << RESET << std::endl;
		ClapTrap Tars("Tars");
		ScavTrap Case("Case");
		ScavTrap Kipp (Case, "Kipp");
		Kipp.guardGate();
		Kipp.attack("Tars");
		Kipp.takeDamage(0);
		Kipp.beRepaired(2);
	}
	return (0);	
}

