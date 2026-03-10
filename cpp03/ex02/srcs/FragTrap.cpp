/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 08:49:09 by jodde             #+#    #+#             */
/*   Updated: 2026/03/10 10:06:13 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

//print function
static void	print(std::string msg, bool color)
{
	if (color)
		std::cout << GREEN << msg << RESET << std::endl;
	else
		std::cout << msg << std::endl;
}
//inistats

void FragTrap::initStats(void)
{
	setHPoint(100);
	setEPoint(100);
	setDamage(30);
}
//Constructors and destructors:
FragTrap::FragTrap() : ClapTrap()
{
	initStats();
	print ("FragTrap Default constructor called", true);
}
FragTrap::FragTrap(std::string Name) : ClapTrap(Name)
{
	initStats();
	std::cout << getName();
	print (" FragTrap constructor called", true);
} 
FragTrap::FragTrap(FragTrap const& src) : ClapTrap(src)
{
	std::cout << getName();
	print (" FragTrap copy constructor called", true);
}

FragTrap::FragTrap(FragTrap const& src, std::string newName) : ClapTrap(src, newName)
{
	std::cout << getName();
	print (" FragTrap copy constructor called", true);
} 
FragTrap::~FragTrap()
{
	std::cout << getName();
	print (" FragTrap destructor called", true);
}

//assignation operator
FragTrap& FragTrap::operator=(FragTrap const& src)
{
	if (this != &src)
		ClapTrap::operator=(src);
	return (*this);
}

//Member functions
void	FragTrap::highFivesGuys()
{
	std::cout << getName();
	print (" FragTrap gives you a high five, guys!", false);
}
void 	FragTrap::attack(const std::string& target)
{
	if (getEPoint() > 0 && getHPoint() > 0)
	{
		setHPoint(getHPoint() - 1);
		setEPoint(getEPoint() - 1);
		std::cout << "FragTrap " << getName() << " attacks " << target << " causing " << getDamage() << " points of damage!" << std::endl;
	}
	else if (getEPoint() <= 0)
		std::cout << "FragTrap " << getName() << "unable to attack - no energy point left" << std::endl;	
	else
		std::cout << "FragTrap " << getName() << "unable to attack - no hitpoint left" << std::endl;	
}
