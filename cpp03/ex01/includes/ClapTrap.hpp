/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 10:11:19 by jodde             #+#    #+#             */
/*   Updated: 2026/03/10 09:27:52 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#define GREEN "\033[32m"
#define RED "\033[33m"
#define RESET "\033[0m"

class ClapTrap
{
	private :
		std::string	_name;
		int			_hPoint;
		int			_ePoint;
		int			_damage;

	public :
	//Constructors and destructors
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const& src);
		ClapTrap(ClapTrap const& src, std::string newName);
		~ClapTrap();
	//assignment operator
		ClapTrap& operator=(ClapTrap const& src);
	//accessors
		std::string getName() const;
		int	getHPoint() const;
		int	getEPoint() const;
		int	getDamage() const;
		void	setHPoint(int amount);
		void	setEPoint(int amount);
		void	setDamage(int amount);
	//member functions
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

