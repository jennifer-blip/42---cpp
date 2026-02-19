/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:24:17 by jodde             #+#    #+#             */
/*   Updated: 2026/02/15 17:47:46 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include<iostream>
#include<string>
#include"Weapon.hpp"

class	HumanB
{
	private:
		std::string _name;
		Weapon		*_weapon = NULL;
	
		public:
			
		//constructors & destructors
			HumanB(){};
			HumanB(std::string name) : _name(name){}
			~HumanB(){};
			
		//accessors
			void	setName(std::string name);
			std::string	getName(void) const;
			
		//member function
			void	attack(void);
			void	setWeapon(Weapon& newWeapon);
};
