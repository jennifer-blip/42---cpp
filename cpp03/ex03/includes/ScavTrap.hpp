/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 08:48:46 by jodde             #+#    #+#             */
/*   Updated: 2026/03/10 10:14:54 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../includes/ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	public :
	//Constructors and destructors:
		ScavTrap();
		ScavTrap(std::string Name);
		ScavTrap(ScavTrap const& src);
		ScavTrap(ScavTrap const& src, std::string newName);
		~ScavTrap();
	//assignment operator
		ScavTrap& operator=(ScavTrap const& src);
	//Member functions
		void	guardGate();
		void 	attack(const std::string& target);
		void	initStats(void);
};

