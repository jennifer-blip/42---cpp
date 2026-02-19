/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:24:04 by jodde             #+#    #+#             */
/*   Updated: 2026/02/19 09:28:54 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void	HumanA::setName(std::string name)
{
	this->_name = name;
}

std::string	HumanA::getName(void) const 
{
	return (this->_name);
}

void	HumanA::attack(void)
{
	std::cout<<this->getName()<<" attacks with their "<<this->_weapon->getType()<<std::endl;
}
