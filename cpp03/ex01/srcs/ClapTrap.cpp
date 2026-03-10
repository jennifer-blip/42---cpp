/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 10:11:50 by jodde             #+#    #+#             */
/*   Updated: 2026/03/10 09:27:10 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

//fonction d'affichage
static void print(std::string str, bool color)
{
	if (color)
		std::cout << GREEN << str << RESET << std::endl;
	else
    	std::cout << str << std::endl;
}

//Constructors and destructors
ClapTrap::ClapTrap() : _name("default"), _hPoint(10), _ePoint(10), _damage(0) 
{
	print("ClapTrap Default Constructor called", true);
}

ClapTrap::ClapTrap(std::string Name) : _name(Name), _hPoint(10), _ePoint(10), _damage(0) 
{
	std::cout << getName();
	print(" ClapTrap Constructor called", true);
}

ClapTrap::ClapTrap(ClapTrap const& src) : _name(src.getName()), _hPoint(src.getHPoint()), _ePoint(src.getEPoint()), _damage(src.getDamage())
{
	std::cout << getName();
	print(" ClapTrap Copy constructor called", true);
}
ClapTrap::ClapTrap(ClapTrap const& src, std::string newName) : _name(newName), _hPoint(src.getHPoint()), _ePoint(src.getEPoint()), _damage(src.getDamage())	
{
	std::cout << getName();
	print(" ClapTrap Copy constructor called", true);
}

ClapTrap::~ClapTrap() 
{
	std::cout << getName();
	print(" ClapTrap Destructor called", true);
}
	
//assignment operator
ClapTrap& ClapTrap::operator=(ClapTrap const& src)
{
	if (this != &src)
	{
		this->_hPoint = src.getHPoint();
		this->_ePoint = src.getEPoint();
		this->_damage = src.getDamage();
	}
	return (*this);
}

//accessors
std::string ClapTrap::getName() const
{
	return (this->_name);
}

int	ClapTrap::getHPoint() const
{
	return (this->_hPoint);
}
int	ClapTrap::getEPoint() const
{
	return (this->_ePoint);
}
int	ClapTrap::getDamage() const
{
	return (this->_damage);
}
void	ClapTrap::setHPoint(int amount)
{
	this->_hPoint = amount;
}
void	ClapTrap::setEPoint(int amount)
{
	this->_ePoint = amount;
}
void	ClapTrap::setDamage(int amount)
{
	this->_damage = amount;
}

//member functions
void ClapTrap::attack(const std::string& target)
{
	if (getEPoint() > 0 && getHPoint() > 0)
	{
		setHPoint(getHPoint() - 1);
		setEPoint(getEPoint() - 1);
		std::cout << "ClapTrap " <<getName() << " attacks " << target << " causing " << getDamage() << " points of damage!" << std::endl;
	}
	else if (getEPoint() <= 0)
		std::cout << "ClapTrap " << getName() << "unable to attack - no energy point left" << std::endl;	
	else
		std::cout << "ClapTrap " << getName() << "unable to attack - no hitpoint left" << std::endl;	
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (getEPoint() > 0 && getHPoint() > 0)
	{
		setEPoint(getEPoint() - (int)amount);
		std::cout << "ClapTrap " << getName() << " takes " << amount << " points of damage!" << " - total Energy = " << getEPoint() << std::endl;
	}
	if (getEPoint() <= 0)
		std::cout << "ClapTrap "  << getName() << " unable to take damage - no energy point left" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (getEPoint() > 0)
	{
		setHPoint(getHPoint() + (int)amount);
		setEPoint(getEPoint() - 1);
		std::cout << "ClapTrap " << getName() << " repairs itself with " << amount << " points" << " - total Energy = " << getEPoint() << " - total hit points = " << getHPoint() <<std::endl;
	}
	else
		std::cout << "ClapTrap " << this->getName() << " unable to repair - no energy point left" << std::endl;	
}


