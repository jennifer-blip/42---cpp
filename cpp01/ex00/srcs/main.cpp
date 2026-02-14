/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:51:48 by jodde             #+#    #+#             */
/*   Updated: 2026/02/14 18:51:50 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie moche("moche");
    Zombie* laid = newZombie("laid");
    moche.announce();
    laid->announce();
    randomChump("affreux");
    delete (laid);
    return(0);
}
