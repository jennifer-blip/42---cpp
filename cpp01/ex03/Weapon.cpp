/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:24:40 by jodde             #+#    #+#             */
/*   Updated: 2026/02/25 11:37:44 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#define GREEN  "\033[32m"
#define RESET  "\033[0m"

//constructors and destructors
Weapon::Weapon(){std::cout<<GREEN<<"Weapon default constructor called"<<RESET<<std::endl;}
Weapon::Weapon(std::string initType) : _type(initType){std::cout<<GREEN<<"Weapon constructor with type called"<<RESET<<std::endl;}
Weapon::~Weapon(){std::cout<<GREEN<<"Weapon destructor called"<<RESET<<std::endl;}

//accessors
void	Weapon::setType(std::string newType) 
{
	this->_type = newType;
}

std::string	Weapon::getType(void) const
{
	return(this->_type);
}
