/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:12:41 by jodde             #+#    #+#             */
/*   Updated: 2026/03/10 11:11:56 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

//print function
static void	print(std::string msg, bool color)
{
	if (color)
		std::cout << GREEN << msg << RESET << std::endl;
	else
		std::cout << msg << std::endl;
}

//iniStats
void	DiamondTrap::initStats()
{
	setEPoint(ScavTrap::getEPoint());
	setHPoint(FragTrap::getHPoint());
	setDamage(FragTrap::getDamage());
}
//Constructors and destructors:
DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), name("Default")
{
	initStats();
	print("DiamondTrap Default Constructor called with Default ClapTrap Name", true);
}
DiamondTrap::DiamondTrap(std::string Name) : ClapTrap(Name + "_clap_name"), ScavTrap(), FragTrap(), name(Name)
{
	initStats();
	std::cout << getName();
	print (" DiamondTrap constructor called", true);
}
DiamondTrap::DiamondTrap(DiamondTrap const& src) : ClapTrap(src)
{
	std::cout << getName();
	print (" DiamondTrap copy constructor called", true);
}
DiamondTrap::DiamondTrap(DiamondTrap const& src, std::string newName) : ClapTrap(src, newName + "_clap_name"), name(newName)
{
	std::cout << getName();
	print (" DiamondTrap copy constructor called", true);
}
DiamondTrap::~DiamondTrap()
{
	std::cout << getName();
	print (" DiamondTrap Destructor called", true);
}
//assignment operator
DiamondTrap& DiamondTrap::operator=(DiamondTrap const& src)
{
	if (this != &src)
		ClapTrap::operator=(src);
	std::cout << getName();
	print (" DiamondTrap assignation operator constructor called", true);
	return (*this);
}
//accessors

void	DiamondTrap::setName(std::string Name)
{
	name = Name;
}
std::string	DiamondTrap::getName()
{
	return(name);
}
//Member functions
void	DiamondTrap::whoAmI(void)
{
	std::cout << getName();
	print(" is my Diamond Name", false);
	std::cout << ClapTrap::getName();
	print (" is my ClapTrap Name", false);
}
void	DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}
