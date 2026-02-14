/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:51:32 by jodde             #+#    #+#             */
/*   Updated: 2026/02/14 18:51:34 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
#include <iostream>
#include <string>


class Zombie
{
    private:
        std::string _name;
    public:
        Zombie(std::string Name) : _name(Name)
        {
            std::cout<<this->_name<<" is born"<<std::endl;
        }
        ~Zombie()
        {
            std::cout<<this->_name<<" died"<<std::endl;
        }
        void    announce(void) const;
        std::string getName(void)const {return(_name);};
        
};

Zombie*     newZombie( std::string name );
void        randomChump( std::string name);
