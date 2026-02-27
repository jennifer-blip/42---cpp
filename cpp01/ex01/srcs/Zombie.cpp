/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:52:20 by jodde             #+#    #+#             */
/*   Updated: 2026/02/25 11:39:34 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#define GREEN  "\033[32m"
#define RESET  "\033[0m"

//Constructors and destructor
Zombie::Zombie(void)
{
    std::cout<<GREEN<<"a zombie is born"<<RESET<<std::endl;
}
Zombie::Zombie(std::string Name) : _name(Name) {}

Zombie::~Zombie(void)
{
    std::cout<<GREEN<<this->_name<<" died"<<RESET<<std::endl;
}
//Member functions
void   Zombie::setName(std::string Name) 
{
    this->_name = Name;
}

std::string Zombie::getName(void) const 
{
    return(this->_name);
}

void Zombie::announce(void) const
{
    std::cout<<this->getName()<<": "<<"BraiiiiiiinnnzzzZ..."<<std::endl;
}

