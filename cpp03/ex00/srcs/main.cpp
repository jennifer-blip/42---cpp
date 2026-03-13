/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 10:11:41 by jodde             #+#    #+#             */
/*   Updated: 2026/03/11 09:46:58 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

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
		std::cout << std::endl << RED << "CLAPTRAP TEST - MEMBER FUNCTIONS" << RESET << std::endl;
		std::cout << std::endl << BROWN << "TARS INSTANCIATION" << RESET << std::endl;
		ClapTrap Tars("Tars");
		variableCheck(Tars);
		std::cout << std::endl << BROWN << "ATTACK FUNCTION TEST" << RESET << std::endl;
		Tars.attack("Case");
		variableCheck(Tars);
		std::cout << std::endl << BROWN << "TAKE DAMAGE FUNCTION TEST" << RESET << std::endl;
		Tars.takeDamage(1);
		variableCheck(Tars);
		std::cout << std::endl << BROWN << "BE REPAIRED FUNCTION TEST" << RESET << std::endl;
		Tars.beRepaired(2);
		variableCheck(Tars);
		std::cout << std::endl << BROWN << "END OF PROGRAM" << RESET << std::endl;
	}
	{
		std::cout << std::endl << RED << "CLAPTRAP TEST - COPY CONSTRUCTOR" << RESET << std::endl;
		ClapTrap Tars("Tars");
		ClapTrap Case(Tars, "Case");
		Case.attack("Case");
		Case.takeDamage(10);
		Case.beRepaired(2);
		std::cout << std::endl << BROWN << "END OF PROGRAM" << RESET << std::endl;
	}
	return (0);	
}

