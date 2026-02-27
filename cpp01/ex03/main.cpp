/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:43:14 by jodde             #+#    #+#             */
/*   Updated: 2026/02/25 11:29:36 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		Weapon watergun = Weapon("pink water gun");
		// HumanA steve;
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
		bob.setWeapon(&watergun);
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		Weapon laser = Weapon("lasergun");
		Weapon watergun = Weapon("watergun");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(&club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
		jim.setWeapon(&laser);
		jim.attack();
		jim.setWeapon(&watergun);
		jim.attack();
	}
	return 0;
}
