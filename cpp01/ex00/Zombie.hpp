/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:51:32 by jodde             #+#    #+#             */
/*   Updated: 2026/02/22 19:33:09 by jodde            ###   ########.fr       */
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
        Zombie(void);
        Zombie(std::string Name);
        ~Zombie();
        void    announce(void) const;
        std::string getName(void)const;
        
};

Zombie*     newZombie( std::string name );
void        randomChump( std::string name);
