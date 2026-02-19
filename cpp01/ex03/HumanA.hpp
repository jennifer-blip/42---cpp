/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:24:11 by jodde             #+#    #+#             */
/*   Updated: 2026/02/15 17:47:57 by jodde            ###   ########.fr       */
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
			HumanA(){};
			HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(&weapon){}
			~HumanA(){};
			
		//accessors
			void	setName(std::string name);
			std::string	getName(void) const;
			
		//member function
			void	attack(void);
};
