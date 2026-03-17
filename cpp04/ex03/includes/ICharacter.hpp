/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:51:00 by jodde             #+#    #+#             */
/*   Updated: 2026/03/16 17:41:49 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include <iostream>
#include <string>

class AMateria;

class	ICharacter
{
	public :
		virtual ~ICharacter(){};
		virtual std::string const& getName() const = 0;
		virtual void	equip(AMateria * m) = 0;
		virtual void	unequip(int idx) = 0;
		virtual void	use(int idx, ICharacter& target) = 0;
};


