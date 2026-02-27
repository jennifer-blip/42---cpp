/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:51:32 by jodde             #+#    #+#             */
/*   Updated: 2026/02/22 19:34:10 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
#include <iostream>
#include <string>
#include <sstream>


class Zombie
{
    private:
        std::string _name;
    public:
        //constructors and destructor
        Zombie(void);
        Zombie(std::string Name);
        ~Zombie(void);

        //accessors
        void    setName(std::string Name);
        std::string getName(void)const;
        
        //methods
        void    announce(void) const; 
};

Zombie* zombieHorde( int N, std::string name );
