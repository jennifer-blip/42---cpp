/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 10:11:41 by jodde             #+#    #+#             */
/*   Updated: 2026/03/11 10:13:08 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/DiamondTrap.hpp"

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
		std::cout << std::endl << RED << "DIAMOND TEST - MEMBER FUNCTIONS" << RESET << std::endl;
		std::cout << std::endl << BROWN << "/////TARS INSTANCIATION" << RESET << std::endl;
		DiamondTrap Tars("Tars");
		variableCheck(Tars);
		std::cout << std::endl << BROWN << "/////ATTACK FUNCTION FROM SCAVTRAP" << RESET << std::endl;
		Tars.attack("Kipp");
		variableCheck(Tars);
		std::cout << std::endl << BROWN << "/////FUNCTION INHERITED FROM SCAVTRAP" << RESET << std::endl;
		Tars.guardGate();
		variableCheck(Tars);
		std::cout << std::endl << BROWN << "/////FUNCTIONS INHERITED FROM CLAPTRAP" << RESET << std::endl;
		Tars.takeDamage(0);
		variableCheck(Tars);
		Tars.beRepaired(2);
		variableCheck(Tars);
		std::cout << std::endl << BROWN << "/////DIAMONDTRAP SPECIFIC FUNCTION" << RESET << std::endl;
		Tars.whoAmI();
		variableCheck(Tars);
		std::cout << std::endl << BROWN << "/////FUNCTION INHERITED FROM FRAGTRAP" << RESET << std::endl;
		Tars.highFivesGuys();
		variableCheck(Tars);
		std::cout << std::endl << BROWN << "END OF PROGRAM" << RESET << std::endl;
		
	}
	{
		std::cout << std::endl << RED << "DIAMOND TEST - INIT VARIABLES" << RESET << std::endl;
		std::cout << std::endl << BROWN << "/////TARS DIAMOND INSTANCIATION" << RESET << std::endl;
		DiamondTrap Tars("Tars");
		variableCheck(Tars);
		std::cout << std::endl << BROWN << "/////KIPP SCAVTRAP INSTANCIATION" << RESET << std::endl;
		ScavTrap Kipp ("Kipp");
		variableCheck(Kipp);
		std::cout << std::endl << BROWN << "/////CASE FRAGTRAP INSTANCIATION" << RESET << std::endl;
		FragTrap Case ("Case");
		variableCheck(Case);
		std::cout << std::endl << BROWN << "/////VARIABLE INITIALISATION TEST" << RESET << std::endl;
		std::cout << RED << Tars.getHPoint() << RESET << " expected = " << Case.getHPoint() << " from FragTrap" << std::endl;
		std::cout << RED << Tars.getEPoint() << RESET << " expected = " << Kipp.getEPoint() << " from ScavTrap" << std::endl;
		std::cout << RED << Tars.getDamage() << RESET << " expected = " << Case.getDamage() << " from FragTrap" <<std::endl;
		std::cout << std::endl << BROWN << "END OF PROGRAM" << RESET << std::endl;
	}
	{
		std::cout << std::endl << RED << "DIAMOND TEST - COPY CONSTRUCTOR" << RESET << std::endl;
		std::cout << std::endl << BROWN << "TARS INSTANCIATION" << RESET << std::endl;	
		DiamondTrap Tars("Tars");
		std::cout << std::endl << BROWN << "KIPP INSTANCIATION" << RESET << std::endl;	
		DiamondTrap Kipp("Kipp");
		std::cout << std::endl << BROWN << "COPY CONSTRUCTOR CALL" << RESET << std::endl;		
		DiamondTrap Case(Tars, "Case");
		std::cout << std::endl << BROWN << "ASSIGNMENT OPERATOR CALL" << RESET << std::endl;
		Kipp = Case;
		std::cout << std::endl << BROWN << "END OF PROGRAM" << RESET << std::endl;
	}
	return (0);	
}

