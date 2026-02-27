/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:24:46 by jodde             #+#    #+#             */
/*   Updated: 2026/02/25 11:33:46 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include<iostream>
#include<string>

class	Weapon
{
	private:
		std::string	_type;
	
	public:
		
	//Constructors & destructors
		Weapon();
		Weapon(std::string initType);
		~Weapon();
		
	//Accessors
		void	setType(std::string newType);
		std::string	getType(void) const;
};
