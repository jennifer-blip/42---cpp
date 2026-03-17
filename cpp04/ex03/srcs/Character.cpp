/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:55:53 by jodde             #+#    #+#             */
/*   Updated: 2026/03/17 16:30:49 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"
#include "../includes/display.hpp"
#include <iostream>
#include <string>
#include <sstream>

//Constructors and destructors
Character::Character(std::string name) : _name(name)
{
	_dump = NULL;
	initTabs(_satchel);
	initTabs(_floor);
	display(getName() + " default constructor called", BROWN);
}
Character::Character(Character const& src) : _name(src._name)
{
	_dump = NULL;
	for (int i = 0; i < _maxMat; i++)
	{
		_satchel[i] = src._satchel[i] ? src._satchel[i]->clone() : NULL;
		_floor[i] = src._floor[i] ? src._floor[i]->clone() : NULL; 
	}
	display(getName() + " copy constructor called", BROWN);
}
Character::~Character()
{
	for (int i = 0; i < _maxMat; i++)
	{
		if (_satchel[i])
				delete _satchel[i];
		_satchel[i] = NULL;
		if (_floor[i])
				delete _floor[i];
		_floor[i] = NULL;
		delete _dump;
		_dump = NULL;
	}
	display(getName() + " destructor called", BROWN);
}
//Assignment operator
Character const&	Character::operator=(Character const& src)
{
	if (this != &src)
	{
		_name = src.getName();
		for (int i = 0; i < _maxMat; i++)
		{
			if (_satchel[i])
				delete _satchel[i];
			_satchel[i] = src._satchel[i] ? src._satchel[i]->clone() : NULL; 
			if (_floor[i])
				delete _floor[i];
			_floor[i] = src._floor[i] ? src._floor[i]->clone() : NULL; 
		}
		this->_name = src.getName();
	}
	return (*this);
}
//Accessors
std::string const& Character::getName() const
{
	return (_name);
}
//Member functions
void Character::equip(AMateria* m)
{
    if (!m)
        return;

    for (int i = 0; i <= _maxMat; i++)
    {
		if (i == _maxMat)
		{
			_dump = m;
			display("unable to equip with " + m->getType() + " - The satchel is already full", RED);
			return;
		}
        if (i < _maxMat && _satchel[i] == NULL)
        {
            _satchel[i] = m;
            return;
        }
    }
}

void	Character::unequip(int idx)
{
	if (idx >= _maxMat || idx < 0)
	{
		display("wrong index! - " + getName() + " has maximum 4 materia in the satchel (index range = 0-3)", RED);
		return ;
	}
	for (int i = 0; i < _maxMat; i++)
	{
		if (i == idx)
		{
			if (_satchel[i] == NULL)
			{
				std::ostringstream os;
				os << idx;
				display("slot nb " + os.str() + " of the satchel is empty", RED);
				return ;
			}
			display (getName() + " unequips materia " + _satchel[i]->getType(), MAGENTA);
			_floor[i] = _satchel[i];
			_satchel[i] = NULL;
		}
	}
}
void	Character::use(int idx, ICharacter& target)
{
	if (idx >= _maxMat || idx < 0)
	{
		display("wrong index! - " + getName() + " has maximum 4 materia in the satchel (index range = 0-3)", RED);
		return ;
	}
	for (int i = 0; i < _maxMat; i++)
	{
		if (i == idx)
		{
			if (_satchel[i] == NULL)
			{
				std::ostringstream os;
				os << idx;
				display("slot nb " + os.str() + " of the satchel is empty", RED);
				return ; 
			}
			_satchel[i]->use(target);
		}
	}
}
void	Character::initTabs(AMateria **tab)
{
	for (int i = 0; i < _maxMat; i++)
		tab[i] = NULL;
}
