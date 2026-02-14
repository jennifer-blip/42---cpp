/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:51:48 by jodde             #+#    #+#             */
/*   Updated: 2026/02/14 19:55:02 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char**argv)
{
    int n;
    if (argc <= 1)
    {
        std::cout<<"ERROR : ARGS : ./Horde <nb of zombies>"<<std::endl;
        return (1);
    }
    std::istringstream iss(argv[1]);
    
    iss>>n;
    Zombie *zomb;
    zomb = zombieHorde(n, "vraiment moche");
    for (int i = 0; i < n; i++)
        zomb[i].announce();
    delete [] zomb;
    return(0);
}
