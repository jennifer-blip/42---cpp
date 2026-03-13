/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 08:49:09 by jodde             #+#    #+#             */
/*   Updated: 2026/03/11 10:09:59 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ScavTrap.hpp"

//print function
static void	print(std::string msg, bool color)
{
	if (color)
		std::cout << GREEN << msg << RESET << std::endl;
	else
		std::cout << msg << std::endl;
}
//initstats
void ScavTrap::initStats()
{
	setHPoint(100);
	setEPoint(50);
	setDamage(20);
}
//Constructors and destructors:
ScavTrap::ScavTrap() : ClapTrap()
{
	initStats();
	print ("ScavTrap Default constructor called", true);
}
ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
	initStats();
	std::cout << getName();
	print (" ScavTrap constructor called", true);
} 
ScavTrap::~ScavTrap()
{
	std::cout << getName();
	print (" ScavTrap destructor called", true);
}

ScavTrap::ScavTrap(ScavTrap const& src) : ClapTrap(src)
{
	std::cout << getName();
	print (" ScavTrap copy constructor called", true);
}

ScavTrap::ScavTrap(ScavTrap const& src, std::string newName) : ClapTrap(src, newName)
{
	std::cout << getName();
	print (" ScavTrap copy constructor called", true);
}
//assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
	if (this != &src)
		ClapTrap::operator=(src);
	return (*this);
}

//Member functions
void	ScavTrap::guardGate()
{
	std::cout << getName();
	print (" ScavTrap switching to Gate keeper mode", false);
}
void 	ScavTrap::attack(const std::string& target)
{
	if (getEPoint() > 0 && getHPoint() > 0)
	{
		setEPoint(addPoints(getEPoint(), -1));
		std::cout << "Scavtrap " << getName() << " attacks " << target << " causing " << getDamage() << " points of damage!" << std::endl;
		std::cout << "Scavtrap " << getName() << " has "<< getEPoint() << " Energy points left" << std::endl;
	}
	else if (getEPoint() <= 0)
		std::cout << "Scavtrap " << getName() << "unable to attack - no energy point left" << std::endl;	
	else
		std::cout << "Scavtrap " << getName() << "unable to attack - no hitpoint left" << std::endl;	
}
