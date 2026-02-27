/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:24:27 by jodde             #+#    #+#             */
/*   Updated: 2026/02/25 11:37:32 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#define GREEN  "\033[32m"
#define RESET  "\033[0m"
	
//Constructors and destructors
HumanB::HumanB(){std::cout<<GREEN<<"HumanB constructor called"<<RESET<<std::endl;}
HumanB::HumanB(std::string name) : _name(name){ std::cout<<GREEN<<"HumanB constructor with name called"<<RESET<<std::endl; setWeapon(NULL);}
HumanB::~HumanB(){std::cout<<GREEN<<"HumanB destructor called"<<RESET<<std::endl;}

//Accessors
void	HumanB::setName(std::string name)
{
	this->_name = name;
}

std::string	HumanB::getName(void) const 
{
	return (this->_name);
}

//Member functions
void	HumanB::attack(void)
{
	if (this->_weapon == NULL)
		std::cout<<this->getName()<<" attacks with their bare hands"<<std::endl;
	else
	std::cout<<this->getName()<<" attacks with their "<<this->_weapon->getType()<<std::endl;
}
void	HumanB::setWeapon(Weapon *newWeapon)
{
	this->_weapon = newWeapon;
}
