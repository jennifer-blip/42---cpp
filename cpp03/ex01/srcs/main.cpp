/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 10:11:41 by jodde             #+#    #+#             */
/*   Updated: 2026/03/11 10:22:52 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"


int main(void)
{
	{
		std::cout << std::endl << RED << "SCAVTRAP TEST - MEMBER FUNCTIONS" << RESET << std::endl;
		std::cout << std::endl << BROWN << "/////TARS CLAPTRAP INSTANCIATION" << RESET << std::endl;
		ClapTrap Tars("Tars");
		std::cout << std::endl << BROWN << "/////CASE SCAVTRAP INSTANCIATION" << RESET << std::endl;
		ScavTrap Case("Case");
		std::cout << std::endl << BROWN << "/////CASE FUNCTION TESTS" << RESET << std::endl;
		std::cout << std::endl << BROWN << "CASE SPECIFIC ATTACK FUNCTION TESTS" << RESET << std::endl;
		Tars.attack("Case");
		Case.attack("Tars");
		std::cout << std::endl << BROWN << "CASE INHERITED FUNCTIONS FROM CLAPTRAP" << RESET << std::endl;
		Tars.takeDamage(2);
		Tars.beRepaired(2);
		Case.takeDamage(5);
		Case.beRepaired(10);
		std::cout << std::endl << BROWN << "CASE SPECIFIC FUNCTION TESTS" << RESET << std::endl;
		Case.guardGate();
		std::cout << std::endl << BROWN << "END OF PROGRAM" << RESET << std::endl;
	}
	{
		std::cout << std::endl << RED << "SCAVTRAP TEST - COPY CONSTRUCTOR" << RESET << std::endl;
		ClapTrap Tars("Tars");
		ScavTrap Case("Case");
		std::cout << std::endl << BROWN << "/////KIPP SCAVTRAP COPY INSTANCIATION OF KIPP" << RESET << std::endl;
		ScavTrap Kipp (Case, "Kipp");
		std::cout << std::endl << BROWN << "/////KIPP FUNCTION TESTS" << RESET << std::endl;
		Kipp.guardGate();
		Kipp.attack("Tars");
		Kipp.takeDamage(0);
		Kipp.beRepaired(2);
		std::cout << std::endl << BROWN << "END OF PROGRAM" << RESET << std::endl;
	}
	return (0);	
}

