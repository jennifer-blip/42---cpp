/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 08:48:46 by jodde             #+#    #+#             */
/*   Updated: 2026/03/10 12:35:57 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../includes/ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	public :
	//Constructors and destructors:
		FragTrap();
		FragTrap(std::string Name);
		FragTrap(FragTrap const& src);
		FragTrap(FragTrap const& src, std::string newName);
		~FragTrap();
	//assignment operator
		FragTrap& operator=(FragTrap const& src);
	//Member functions
		void	highFivesGuys();
		void 	attack(const std::string& target);
		void	initStats(void);
};
