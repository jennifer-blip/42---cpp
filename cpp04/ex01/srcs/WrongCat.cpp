/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:00:19 by jodde             #+#    #+#             */
/*   Updated: 2026/03/11 12:09:15 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"
#include "../includes/display.hpp"
#include <iostream>
#include <string>

//Constructors and destructors
WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	display("WrongCat default constructor called", BROWN);
}
WrongCat::WrongCat(std::string Name) : WrongAnimal("Cat"), _name (Name)
{
	display("WrongCat constructor called", BROWN);
}

WrongCat::WrongCat(WrongCat const& src) : WrongAnimal(src._type)
{
	display(getType() + " copy constructor called", BROWN);
}
WrongCat::~WrongCat()
{
	display("WrongCat destructor called", BROWN);
}
//Assignment operator
WrongCat& WrongCat::operator=(WrongCat const& src)
{
	if (this != &src)
	{
		WrongAnimal::operator=(src);
		_name = src.getName();
	}
	return (*this);
}

//accessors
std::string WrongCat::getName(void) const
{
	return(_name);
}

void	WrongCat::setName(std::string Name)
{
	_name = Name;
}
//member functions
void	WrongCat::makeSound() const
{
	display(getType() + "/// Tiny wrongpaws patter, wrongmewing with delight.", GREEN);
}
