/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 08:12:23 by jodde             #+#    #+#             */
/*   Updated: 2026/03/17 16:22:26 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class AMateria;

class MateriaSource : public IMateriaSource
{
	private :
		static const int	_maxSource = 4;
	 	AMateria* 			_spellBook[_maxSource];
		AMateria*			dump;

	public :
	//Constructors and destructors
		MateriaSource(void);
		MateriaSource(MateriaSource const& src);
		~MateriaSource();
	//Assignment operator
		MateriaSource& operator=(MateriaSource const& src);
	//Member functions
		void		learnMateria(AMateria* newMateria);
		AMateria*	createMateria(std::string const& type);
};
