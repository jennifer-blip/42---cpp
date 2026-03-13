/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 10:11:41 by jodde             #+#    #+#             */
/*   Updated: 2026/03/11 10:18:27 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

static void	variableCheck(ClapTrap const& test)
{
		std::cout << std::endl << BROWN << "VARIABLE VALUE CHECK" << RESET << std::endl;
		std::cout << test.getName() << " Hit points = " << RED << test.getHPoint() << RESET << std::endl;
		std::cout << test.getName() << " Energy points = " << RED << test.getEPoint() << RESET << std::endl;
		std::cout << test.getName() << " Damage points = " << RED << test.getDamage() << RESET << std::endl;
}

int main(void)
{
	{
		std::cout << std::endl << RED << "FRAGTRAP TEST - MEMBER FUNCTIONS" << RESET << std::endl;
		std::cout << std::endl << BROWN << "/////TARS CLAPTRAP INSTANCIATION" << RESET << std::endl;
		ClapTrap Tars("Tars");
		variableCheck(Tars);
		std::cout << std::endl << BROWN << "/////CASE SCAVTRAP INSTANCIATION" << RESET << std::endl;
		ScavTrap Case("Case");
		variableCheck(Case);
		std::cout << std::endl << BROWN << "/////KIPP FRAGTRAP INSTANCIATION" << RESET << std::endl;
		FragTrap Kipp("Kipp");
		std::cout << std::endl << BROWN << "/////KIPP FRAGTRAP FUNCTION TESTS" << RESET << std::endl;
		std::cout << std::endl << BROWN << "ATTACK FUNCTION INHERITED FROM CLAPTRAP" << RESET << std::endl;
		Tars.attack("Kipp");
		variableCheck(Kipp);
		std::cout << std::endl << BROWN << "TAKE DAMAGE FUNCTION INHERITED FROM CLAPTRAP" << RESET << std::endl;
		Kipp.takeDamage(0);
		variableCheck(Kipp);
		std::cout << std::endl << BROWN << "BE REPAIRED FUNCTION INHERITED FROM CLAPTRAP" << RESET << std::endl;
		Kipp.beRepaired(2);
		variableCheck(Kipp);
		std::cout << std::endl << BROWN << "FRAGTRAP SPECIFIC FUNCTION" << RESET << std::endl;
		Kipp.highFivesGuys();
		std::cout << std::endl << BROWN << "END OF PROGRAM" << RESET << std::endl;
	}
	{
		std::cout << std::endl << RED << "FRAGTRAP TEST - COPY CONSTRUCTOR" << RESET << std::endl;
		std::cout << std::endl << BROWN << "/////CASE FRAGTRAP INSTANCIATION" << RESET << std::endl;
		FragTrap Case("Case");
		std::cout << std::endl << BROWN << "/////KIPP FRAGTRAP COPY INSTANCIATION OF CASE" << RESET << std::endl;
		FragTrap Kipp(Case, "Kipp");
		std::cout << std::endl << BROWN << "/////KIPP FRAGTRAP FUNCTION TESTS" << RESET << std::endl;
		Kipp.takeDamage(0);
		Kipp.beRepaired(2);
		Kipp.attack("Case");
		Kipp.highFivesGuys();
		std::cout << std::endl << BROWN << "END OF PROGRAM" << RESET << std::endl;
	}
	return (0);	
}

