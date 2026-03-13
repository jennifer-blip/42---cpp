/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:12:57 by jodde             #+#    #+#             */
/*   Updated: 2026/03/10 12:37:15 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../includes/FragTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include <iostream>
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap
{
	private :
		std::string name;
	public :
	//Constructors and destructors:
		DiamondTrap();
		DiamondTrap(std::string Name);
		DiamondTrap(DiamondTrap const& src);
		DiamondTrap(DiamondTrap const& src, std::string newName);
		~DiamondTrap();
	//assignment operator
		DiamondTrap& operator=(DiamondTrap const& src);
	//accessors
		void	setName(std::string Name);
		std::string getName();
	//Member functions
		void	whoAmI(void);
		void	initStats();
		using 	ScavTrap::attack;
};
