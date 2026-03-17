/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:53:21 by jodde             #+#    #+#             */
/*   Updated: 2026/03/17 19:57:52 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <string>
		
class	Character : public ICharacter
{
	private :
		std::string			_name;
		static const int	_maxMat = 4;
		AMateria*			_satchel[_maxMat];	
		AMateria*			_floor[_maxMat];
	public :
	//Constructors and destructors
		Character(std::string name);
		Character(Character const& src);
		~Character(void);
	//Assignment operator
		Character const&	operator=(Character const& src);
	//Accessors
		std::string const& getName() const;
	//Member functions
		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);
		void	initTabs(AMateria **tab);
};
