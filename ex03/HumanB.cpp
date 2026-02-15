/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:24:27 by jodde             #+#    #+#             */
/*   Updated: 2026/02/15 17:41:52 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::setName(std::string name)
{
	this->_name = name;
}

std::string	HumanB::getName(void) const 
{
	return (this->_name);
}

void	HumanB::attack(void)
{
	std::cout<<this->getName()<<" attacks with their "<<this->_weapon->getType()<<std::endl;
}
void	HumanB::setWeapon(Weapon& newWeapon)
{
	this->_weapon = &newWeapon;
}