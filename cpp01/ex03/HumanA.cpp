/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:24:04 by jodde             #+#    #+#             */
/*   Updated: 2026/02/25 11:37:13 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#define GREEN  "\033[32m"
#define RESET  "\033[0m"

//Constructors and destructors
HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(&weapon){ std::cout<<GREEN<<"HumanA constructor called"<<RESET<<std::endl;}
HumanA::~HumanA(){std::cout<<GREEN<<"HumanA destructor called"<<RESET<<std::endl;}

//Accessors
void	HumanA::setName(std::string name)
{
	this->_name = name;
}

std::string	HumanA::getName(void) const 
{
	return (this->_name);
}

//Member functions
void	HumanA::attack(void)
{
	if (!this->_weapon)
	{
		std::cout<<this->getName()<<" has no weapon to attack with!"<<std::endl;
		return ;
	}
	std::cout<<this->getName()<<" attacks with their "<<this->_weapon->getType()<<std::endl;
}
void	HumanA::setWeapon(Weapon *newWeapon)
{
	this->_weapon = newWeapon;
}
