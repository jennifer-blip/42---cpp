/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 10:11:41 by jodde             #+#    #+#             */
/*   Updated: 2026/03/10 10:07:49 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

int main(void)
{
	{
		std::cout << std::endl << RED << "FRAGTRAP TEST - MEMBER FUNCTIONS" << RESET << std::endl;
		ClapTrap Tars("Tars");
		ScavTrap Case("Case");
		FragTrap Kipp("Kipp");
		Tars.attack("Kipp");
		Kipp.takeDamage(0);
		Kipp.beRepaired(2);
		Case.attack("Tars");
		Tars.takeDamage(2);
		Tars.beRepaired(2);
		Kipp.attack("Case");
		Case.takeDamage(30);
		Case.beRepaired(20);
		Kipp.highFivesGuys();
	}
	{
		std::cout << std::endl << RED << "FRAGTRAP TEST - COPY CONSTRUCTOR" << RESET << std::endl;
		ClapTrap Tars("Tars");
		FragTrap Case("Case");
		FragTrap Kipp(Case, "Kipp");
		Tars.attack("Kipp");
		Kipp.takeDamage(0);
		Kipp.beRepaired(2);
		Case.attack("Tars");
		Tars.takeDamage(2);
		Tars.beRepaired(2);
		Kipp.attack("Case");
		Case.takeDamage(30);
		Case.beRepaired(20);
		Kipp.highFivesGuys();
	}
	return (0);	
}

