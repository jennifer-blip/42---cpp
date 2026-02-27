/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:52:20 by jodde             #+#    #+#             */
/*   Updated: 2026/02/25 11:26:54 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

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
