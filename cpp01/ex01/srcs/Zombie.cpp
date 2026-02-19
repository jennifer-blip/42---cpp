/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:52:20 by jodde             #+#    #+#             */
/*   Updated: 2026/02/15 15:43:11 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

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

Zombie* zombieHorde( int N, std::string name )
{
    Zombie  *horde = new Zombie[N];
    int n;
    
    for (int i = 0; i < N; i++)
    {
        std::ostringstream oss;
        n = i;
        oss<<n + 1;
        horde[i].setName(name + oss.str());
    }
    return (horde);
}
