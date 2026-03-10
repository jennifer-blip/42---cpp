/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 08:49:09 by jodde             #+#    #+#             */
/*   Updated: 2026/03/10 09:35:45 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

//print function
void	print(std::string msg, bool color)
{
	if (color)
		std::cout << GREEN << msg << RESET << std::endl;
	else
		std::cout << msg << std::endl;
}

//Constructors and destructors:
ScavTrap::ScavTrap() : ClapTrap()
{
	setHPoint(100);
	setEPoint(50);
	setDamage(20);
	print ("ScavTrap Default constructor called", true);
}
ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
	setHPoint(100);
	setEPoint(50);
	setDamage(20);
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
ScavTrap& ScavTrap::operator=(ScavTrap const& src)
{
	if (this != &src)
	{
		this->setHPoint(src.getHPoint());
		this->setEPoint(src.getEPoint());
		this->setDamage(src.getDamage());
	}
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
		setHPoint(getHPoint() - 1);
		setEPoint(getEPoint() - 1);
		std::cout << "Scavtrap " << getName() << " attacks " << target << " causing " << getDamage() << " points of damage!" << std::endl;
	}
	else if (getEPoint() <= 0)
		std::cout << "Scavtrap " << getName() << "unable to attack - no energy point left" << std::endl;	
	else
		std::cout << "Scavtrap " << getName() << "unable to attack - no hitpoint left" << std::endl;	
}
