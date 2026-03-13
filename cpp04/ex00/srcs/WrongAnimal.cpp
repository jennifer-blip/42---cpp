/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:59:25 by jodde             #+#    #+#             */
/*   Updated: 2026/03/11 12:07:59 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"
#include "../includes/display.hpp"
#include <iostream>
#include <string>

//Constructors and destructors
WrongAnimal::WrongAnimal() : _type("Default WrongAnimal")
{
	display("WrongAnimal default constructor called", BROWN);
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	display("WrongAnimal constructor called with type " + getType(), BROWN);
}
WrongAnimal::WrongAnimal(WrongAnimal const& src) : _type(src._type)
{
	display(getType() + "WrongAnimal copy constructor called", BROWN);
}
WrongAnimal::~WrongAnimal()
{
	display("WrongAnimal destructor called", BROWN);
}
//Assignment operator
WrongAnimal& WrongAnimal::operator=(WrongAnimal const& src)
{
	if (this != &src)
		this->_type = src.getType();
	return (*this);
}

//accessors
std::string WrongAnimal::getType(void) const
{
	return(_type);
}
void	WrongAnimal::setType(std::string type)
{
	_type = type;
}
//member functions
void	WrongAnimal::makeSound() const
{
	display (getType() + " is singing a beautiful lovesong", GREEN);
}

