/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:24:11 by jodde             #+#    #+#             */
/*   Updated: 2026/02/25 10:10:49 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include<iostream>
#include<string>
#include"Weapon.hpp"

class	HumanA
{
	private:
		std::string _name;
		Weapon		*_weapon;
	
		public:
			
		//constructors & destructors
			HumanA(std::string name, Weapon& weapon);
			~HumanA();
			
		//accessors
			void	setName(std::string name);
			std::string	getName(void) const;
			
		//member function
			void	attack(void);
			void	setWeapon(Weapon *newWeapon);
};
