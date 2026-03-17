/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 08:05:20 by jodde             #+#    #+#             */
/*   Updated: 2026/03/17 16:23:44 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"
#include "../includes/display.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"
#include <iostream>
#include <string>

//Constructors and destructors
MateriaSource::MateriaSource(void) 
{
	for (int i = 0; i < _maxSource ; i++)
		_spellBook[i] = NULL;
	dump = NULL;
	display("MateriaSource default constructor called", GREY);
}

MateriaSource::MateriaSource(MateriaSource const& src)
{
	for (int i = 0; i < _maxSource ; i++)
		_spellBook[i] = src._spellBook[i] ? src._spellBook[i]->clone() : NULL;
	dump = NULL;
	display("MateriaSource copy constructor called", GREY);
}
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < _maxSource ; i++)
		delete (_spellBook[i]);
	delete dump;
	display("MateriaSource destructor called", GREY);
}
//Assignment operator
MateriaSource& MateriaSource::operator=(MateriaSource const& src)
{
	if (this != &src)
	{
		for (int i = 0; i < _maxSource ; i++)
		{
			delete (_spellBook[i]);
			_spellBook[i] = src._spellBook[i] ? src._spellBook[i]->clone() : NULL;
		}
	}
	return (*this);
}
//accessors

// void		setSatchel(Materia* newMateria);

//Member functions
void		MateriaSource::learnMateria(AMateria* newMateria)
{
	for (int i = 0; i <= _maxSource; i++)
	{
		if (i == _maxSource)
		{
			dump = newMateria;
			display("unable to add " + newMateria->getType() + " - The spellBook is already full", RED);
			return ;
		}
		if (i < _maxSource && _spellBook[i] == NULL)
		{
			_spellBook[i] = newMateria; 
			return;
		}
	}
}
AMateria*	MateriaSource::createMateria(std::string const& type)
{
	AMateria*	newMateria;
	if (type == "cure")
		newMateria = new Cure("cure");
	if (type == "ice")
		newMateria = new Ice("ice");
	return (newMateria); 
}
